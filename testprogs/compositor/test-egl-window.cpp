#include "test-egl.h"

///////////////////////////////////////////////////////////////////////////////

Window::Window(Display *display, int width, int height, bool fullscreen,
               bool opaque)
    : display(display), geometry{width, height}, window_size{width, height},
      fullscreen(fullscreen), opaque(opaque) {
  create_surface();
  init_egl();
  init_gl();
}

///////////////////////////////////////////////////////////////////////////////

Window::~Window() {
  destroy_surface();
  fini_egl();
}

///////////////////////////////////////////////////////////////////////////////

void Window::redraw(uint32_t time) {
  static const GLfloat verts[3][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0, 0.5}};
  static const GLfloat colors[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  GLfloat angle;
  GLfloat rotation[4][4] = {
      {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  static const int32_t speed_div = 5;
  static uint32_t start_time = 0;

  if (start_time == 0)
    start_time = time;

  angle = ((time - start_time) / speed_div) % 360 * M_PI / 180.0;
  rotation[0][0] = cos(angle);
  rotation[0][2] = sin(angle);
  rotation[2][0] = -sin(angle);
  rotation[2][2] = cos(angle);

  glViewport(0, 0, geometry.width, geometry.height);

  glUniformMatrix4fv(gl.rotation_uniform, 1, GL_FALSE, (GLfloat *)rotation);

  glClearColor(0.0, 0.0, 0.0, 0.5);
  glClear(GL_COLOR_BUFFER_BIT);

  glVertexAttribPointer(gl.pos, 2, GL_FLOAT, GL_FALSE, 0, verts);
  glVertexAttribPointer(gl.col, 3, GL_FLOAT, GL_FALSE, 0, colors);
  glEnableVertexAttribArray(gl.pos);
  glEnableVertexAttribArray(gl.col);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(gl.pos);
  glDisableVertexAttribArray(gl.col);

  wl_surface_damage(surface, 0, 0, geometry.width, geometry.height);
  wl_surface_commit(surface);

  callback = wl_surface_frame(surface);
  wl_callback_add_listener(callback, &frame_listener, this);

  eglSwapBuffers(display->egl.dpy, egl_surface);
}

///////////////////////////////////////////////////////////////////////////////

void Window::toggle_fullscreen(bool fullscreen) {
  this->fullscreen = fullscreen;
  configured = false;

  if (fullscreen) {
    wl_shell_surface_set_fullscreen(
        shell_surface, WL_SHELL_SURFACE_FULLSCREEN_METHOD_DEFAULT, 0, nullptr);
  } else {
    wl_shell_surface_set_toplevel(shell_surface);
    handle_configure(this, shell_surface, 0, window_size.width,
                     window_size.height);
  }

  auto *callback = wl_display_sync(display->get_display());
  wl_callback_add_listener(callback, &configure_callback_listener, this);
}

///////////////////////////////////////////////////////////////////////////////

void Window::create_surface() {
    surface = wl_compositor_create_surface(display->get_compositor());
    shell_surface = wl_shell_get_shell_surface(display->get_shell(), surface);

    wl_shell_surface_add_listener(shell_surface, &shell_surface_listener, this);

    native = wl_egl_window_create(surface, window_size.width, window_size.height);
    if (!native) {
        log_error("Failed to create wl_egl_window");
        return;
    }

    egl_surface = eglCreateWindowSurface(display->egl.dpy, display->egl.conf, native, nullptr);
    if (egl_surface == EGL_NO_SURFACE) {
        EGLint error = eglGetError();
        log_error("Failed to create EGL window surface. Error: " + std::to_string(error));
        return;
    }

    auto ret = eglMakeCurrent(display->egl.dpy, egl_surface, egl_surface, display->egl.ctx);
    if (ret != EGL_TRUE) {
        EGLint error = eglGetError();
        log_error("Failed to make EGL context current. Error: " + std::to_string(error));
        return;
    }

    wl_shell_surface_set_title(shell_surface, "simple-egl");

    toggle_fullscreen(fullscreen);
}


///////////////////////////////////////////////////////////////////////////////

void Window::destroy_surface() {
  wl_egl_window_destroy(native);
  wl_shell_surface_destroy(shell_surface);
  wl_surface_destroy(surface);
  if (callback)
    wl_callback_destroy(callback);
}

///////////////////////////////////////////////////////////////////////////////

void Window::init_egl() {
  static const EGLint context_attribs[] = {EGL_CONTEXT_CLIENT_VERSION, 2,
                                           EGL_NONE};

  EGLint config_attribs[] = {EGL_SURFACE_TYPE,
                             EGL_WINDOW_BIT,
                             EGL_RED_SIZE,
                             1,
                             EGL_GREEN_SIZE,
                             1,
                             EGL_BLUE_SIZE,
                             1,
                             EGL_ALPHA_SIZE,
                             1,
                             EGL_RENDERABLE_TYPE,
                             EGL_OPENGL_ES2_BIT,
                             EGL_NONE};

  if (opaque)
    config_attribs[9] = 0;

  display->egl.dpy =
      eglGetDisplay((EGLNativeDisplayType)display->get_display());
  assert(display->egl.dpy);

  EGLBoolean ret = eglInitialize(display->egl.dpy, nullptr, nullptr);
  assert(ret == EGL_TRUE);

  ret = eglBindAPI(EGL_OPENGL_ES_API);
  assert(ret == EGL_TRUE);

  EGLint n;
  ret = eglChooseConfig(display->egl.dpy, config_attribs, &display->egl.conf, 1,
                        &n);
  assert(ret && n == 1);

  display->egl.ctx = eglCreateContext(display->egl.dpy, display->egl.conf,
                                      EGL_NO_CONTEXT, context_attribs);
  assert(display->egl.ctx);
}

///////////////////////////////////////////////////////////////////////////////

void Window::fini_egl() {
  eglMakeCurrent(display->egl.dpy, EGL_NO_SURFACE, EGL_NO_SURFACE,
                 EGL_NO_CONTEXT);
  eglTerminate(display->egl.dpy);
  eglReleaseThread();
}

///////////////////////////////////////////////////////////////////////////////

void Window::init_gl() {
  static const char *vert_shader_text = R"(
            uniform mat4 rotation;
            attribute vec4 pos;
            attribute vec4 color;
            varying vec4 v_color;
            void main() {
                gl_Position = rotation * pos;
                v_color = color;
            }
        )";

  static const char *frag_shader_text = R"(
            precision mediump float;
            varying vec4 v_color;
            void main() {
                gl_FragColor = v_color;
            }
        )";

  GLuint frag = create_shader(frag_shader_text, GL_FRAGMENT_SHADER);
  GLuint vert = create_shader(vert_shader_text, GL_VERTEX_SHADER);

  GLuint program = glCreateProgram();
  glAttachShader(program, frag);
  glAttachShader(program, vert);
  glLinkProgram(program);

  GLint status;
  glGetProgramiv(program, GL_LINK_STATUS, &status);
  if (!status) {
    char log[1000];
    GLsizei len;
    glGetProgramInfoLog(program, 1000, &len, log);
    std::cerr << "Error: linking: " << std::string(log, len) << std::endl;
    exit(1);
  }

  glUseProgram(program);

  gl.pos = 0;
  gl.col = 1;

  glBindAttribLocation(program, gl.pos, "pos");
  glBindAttribLocation(program, gl.col, "color");
  glLinkProgram(program);

  gl.rotation_uniform = glGetUniformLocation(program, "rotation");
}

///////////////////////////////////////////////////////////////////////////////

GLuint Window::create_shader(const char *source, GLenum shader_type) {
  GLuint shader = glCreateShader(shader_type);
  assert(shader != 0);

  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if (!status) {
    char log[1000];
    GLsizei len;
    glGetShaderInfoLog(shader, 1000, &len, log);
    std::cerr << "Error: compiling "
              << (shader_type == GL_VERTEX_SHADER ? "vertex" : "fragment")
              << ": " << std::string(log, len) << std::endl;
    exit(1);
  }

  return shader;
}

///////////////////////////////////////////////////////////////////////////////

void Window::handle_ping(void *data, struct wl_shell_surface *shell_surface,
                         uint32_t serial) {
  wl_shell_surface_pong(shell_surface, serial);
}

///////////////////////////////////////////////////////////////////////////////

void Window::handle_configure(void *data,
                              struct wl_shell_surface *shell_surface,
                              uint32_t edges, int32_t width, int32_t height) {
  auto *window = static_cast<Window *>(data);

  if (window->native)
    wl_egl_window_resize(window->native, width, height, 0, 0);

  window->geometry.width = width;
  window->geometry.height = height;

  if (!window->fullscreen)
    window->window_size = window->geometry;
}

///////////////////////////////////////////////////////////////////////////////

void Window::handle_popup_done(void *data,
                               struct wl_shell_surface *shell_surface) {
  // Handle popup done event if necessary
}

///////////////////////////////////////////////////////////////////////////////

void Window::configure_callback(void *data, struct wl_callback *callback,
                                uint32_t time) {
  auto *window = static_cast<Window *>(data);

  wl_callback_destroy(callback);

  window->configured = true;

  if (window->callback == nullptr)
    window->redraw(time);
}

///////////////////////////////////////////////////////////////////////////////

const struct wl_shell_surface_listener Window::shell_surface_listener = {
    Window::handle_ping, Window::handle_configure, Window::handle_popup_done};

///////////////////////////////////////////////////////////////////////////////

const struct wl_callback_listener Window::configure_callback_listener = {
    Window::configure_callback};

///////////////////////////////////////////////////////////////////////////////

const struct wl_callback_listener Window::frame_listener = {
    [](void *data, struct wl_callback *callback, uint32_t time) {
      static_cast<Window *>(data)->redraw(time);
    }};

