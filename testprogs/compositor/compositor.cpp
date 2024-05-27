#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <wayland-server-protocol.h>
#include <wayland-server.h>
#include <fcntl.h>
#include <unistd.h>
//#include <xf86drm.h>
//#include <xf86drmMode.h>
#include <gbm.h>
#include <EGL/egl.h>

// Utility function to log errors
void log_error(const std::string &message) {
  std::cerr << "Error: " << message << std::endl;
}

// Utility function to log info
void log_info(const std::string &message) {
  std::cout << "Info: " << message << std::endl;
}

class MinimalCompositor {
public:
  MinimalCompositor() {
    log_info("Initializing Wayland display...");
    display = wl_display_create();

    auto display_name = wl_display_add_socket_auto(display);

    log_info("Wayland display name: " + std::string(display_name));

    if (!display) {
      throw std::runtime_error("Failed to create display");
    }
    log_info("Wayland display created successfully.");

    // Initialize EGL
    if (!init_egl()) {
      throw std::runtime_error("Failed to initialize EGL");
    }

    log_info("Getting Wayland event loop...");
    event_loop = wl_display_get_event_loop(display);
    if (!event_loop) {
      throw std::runtime_error("Failed to get event loop");
    }
    log_info("Wayland event loop acquired successfully.");

    // Register global Wayland interfaces
    log_info("Creating global Wayland compositor interface...");
    if (!wl_global_create(display, &wl_compositor_interface, 4, this,
                          bind_compositor)) {
      throw std::runtime_error("Failed to create compositor global");
    }
    log_info("Wayland compositor interface created successfully.");

    log_info("Creating global Wayland surface interface...");
    if (!wl_global_create(display, &wl_surface_interface, 3, this,
                          bind_surface)) {
      throw std::runtime_error("Failed to create surface global");
    }
    log_info("Wayland surface interface created successfully.");

    log_info("Creating global Wayland shell interface...");
    if (!wl_global_create(display, &wl_shell_interface, 1, this, bind_shell)) {
      throw std::runtime_error("Failed to create shell global");
    }
    log_info("Wayland shell interface created successfully.");

    log_info("Creating global Wayland output interface...");
    if (!wl_global_create(display, &wl_output_interface, 2, this,
                          bind_output)) {
      throw std::runtime_error("Failed to create output global");
    }
    log_info("Wayland output interface created successfully.");

    log_info("MinimalCompositor initialized successfully");
  }

  ~MinimalCompositor() {
    if (display) {
      wl_display_destroy(display);
    }
    log_info("MinimalCompositor destroyed");
  }

  bool init_egl() {
    // Get the EGL display
    egl_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (egl_display == EGL_NO_DISPLAY) {
      log_error("Failed to get EGL display");
      return false;
    }
    log_info("EGL display acquired successfully");

    // Initialize EGL
    if (!eglInitialize(egl_display, nullptr, nullptr)) {
      log_error("Failed to initialize EGL");
      return false;
    }
    log_info("EGL initialized successfully");

    // Bind the Wayland display
    if (!eglBindAPI(EGL_OPENGL_ES_API)) {
      log_error("Failed to bind EGL API");
      return false;
    }
    log_info("EGL API bound successfully");

    // Configure EGL attributes
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

    EGLint num_configs;
    if (!eglChooseConfig(egl_display, config_attribs, &egl_config, 1,
                         &num_configs) ||
        num_configs < 1) {
      log_error("Failed to choose EGL config");
      return false;
    }

    // Create an EGL context
    EGLint context_attribs[] = {EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE};
    egl_context = eglCreateContext(egl_display, egl_config, EGL_NO_CONTEXT,
                                   context_attribs);
    if (egl_context == EGL_NO_CONTEXT) {
      log_error("Failed to create EGL context");
      return false;
    }

    log_info("EGL context created successfully");
    // dump the EGL config
    EGLint value;
    eglGetConfigAttrib(egl_display, egl_config, EGL_RED_SIZE, &value);
    log_info("EGL_RED_SIZE: " + std::to_string(value));
    eglGetConfigAttrib(egl_display, egl_config, EGL_GREEN_SIZE, &value);
    log_info("EGL_GREEN_SIZE: " + std::to_string(value));
    eglGetConfigAttrib(egl_display, egl_config, EGL_BLUE_SIZE, &value);
    log_info("EGL_BLUE_SIZE: " + std::to_string(value));
    eglGetConfigAttrib(egl_display, egl_config, EGL_ALPHA_SIZE, &value);
    log_info("EGL_ALPHA_SIZE: " + std::to_string(value));
    eglGetConfigAttrib(egl_display, egl_config, EGL_RENDERABLE_TYPE, &value);
    log_info("EGL_RENDERABLE_TYPE: " + std::to_string(value));
    // dump EGL resolution
    EGLint width, height;
    eglGetConfigAttrib(egl_display, egl_config, EGL_MAX_PBUFFER_WIDTH, &width);
    eglGetConfigAttrib(egl_display, egl_config, EGL_MAX_PBUFFER_HEIGHT, &height);
    log_info("EGL_MAX_PBUFFER_WIDTH: " + std::to_string(width));
    log_info("EGL_MAX_PBUFFER_HEIGHT: " + std::to_string(height));
    // dump HW info
    const char *vendor = eglQueryString(egl_display, EGL_VENDOR);
    log_info("EGL_VENDOR: " + std::string(vendor));
    const char *version = eglQueryString(egl_display, EGL_VERSION);
    log_info("EGL_VERSION: " + std::string(version));
    const char *extensions = eglQueryString(egl_display, EGL_EXTENSIONS);
    log_info("EGL_EXTENSIONS: " + std::string(extensions));
    // dump hw client api's
    const char *client_apis = eglQueryString(egl_display, EGL_CLIENT_APIS);
    log_info("EGL_CLIENT_APIS: " + std::string(client_apis));
    // dump hw-output (crtc, etc.) info
    //const char *hw_output = eglQueryString(egl_display, EGL_NATIVE_VISUAL_ID);
    //log_info("EGL_NATIVE_VISUAL_ID: " + std::string(hw_output));
    // dump hw-renderable type
    //const char *hw_renderable = eglQueryString(egl_display, EGL_RENDERABLE_TYPE);
    //log_info("EGL_RENDERABLE_TYPE: " + std::string(hw_renderable));
    // dump hw-configs
    //const char *hw_configs = eglQueryString(egl_display, EGL_CONFIG_CAVEAT);
    //log_info("EGL_CONFIG_CAVEAT: " + std::string(hw_configs));
    // dump hw-profiles
    //const char *hw_profiles = eglQueryString(egl_display, EGL_CONTEXT_CLIENT_VERSION);
    //log_info("EGL_CONTEXT_CLIENT_VERSION: " + std::string(hw_profiles));
    // dump hw-extensions
    
    // dump DRM info 
    //const char *drm_info = eglQueryString(egl_display, EGL_DRM_DEVICE_FILE);
    //log_info("EGL_DRM_DEVICE_FILE: " + std::string(drm_info));


    return true;
  }

  void run() {
    log_info("Running minimal Wayland compositor");
    wl_event_loop_add_idle(event_loop, display_idle, this);
    wl_display_run(display);
  }

private:
  static void log_protocol(const std::string &direction,
                           const std::string &message) {
    std::cout << direction << ": " << message << std::endl;
  }

  static void display_idle(void *data) {
    auto compositor = static_cast<MinimalCompositor *>(data);
    log_info("Entering idle state");
  }

  static void bind_compositor(struct wl_client *client, void *data,
                              uint32_t version, uint32_t id) {
    auto compositor = static_cast<MinimalCompositor *>(data);
    auto resource =
        wl_resource_create(client, &wl_compositor_interface, version, id);
    if (!resource) {
      log_error("Failed to create compositor resource");
    } else {
      log_info("Compositor bound to client: " +
               std::to_string(reinterpret_cast<uintptr_t>(client)));
    }
  }

  static void bind_surface(struct wl_client *client, void *data,
                           uint32_t version, uint32_t id) {
    auto compositor = static_cast<MinimalCompositor *>(data);
    auto resource =
        wl_resource_create(client, &wl_surface_interface, version, id);
    if (!resource) {
      log_error("Failed to create surface resource");
    } else {
      wl_resource_set_implementation(resource, &surface_implementation,
                                     compositor, handle_surface_destroy);
      log_info("Surface bound to client: " +
               std::to_string(reinterpret_cast<uintptr_t>(client)));
    }
  }

  static void bind_shell(struct wl_client *client, void *data, uint32_t version,
                         uint32_t id) {
    auto compositor = static_cast<MinimalCompositor *>(data);
    auto resource =
        wl_resource_create(client, &wl_shell_interface, version, id);
    if (!resource) {
      log_error("Failed to create shell resource");
    } else {
      log_info("Shell bound to client: " +
               std::to_string(reinterpret_cast<uintptr_t>(client)));
    }
  }

  static void bind_output(struct wl_client *client, void *data,
                          uint32_t version, uint32_t id) {
    auto compositor = static_cast<MinimalCompositor *>(data);
    auto resource =
        wl_resource_create(client, &wl_output_interface, version, id);
    if (!resource) {
      log_error("Failed to create output resource");
    } else {
      log_info("Output bound to client: " +
               std::to_string(reinterpret_cast<uintptr_t>(client)));
    }
  }

  static void handle_surface_destroy(struct wl_resource *resource) {
    log_info("Surface destroyed: " +
             std::to_string(reinterpret_cast<uintptr_t>(resource)));
  }

  static const struct wl_surface_interface surface_implementation;

  wl_display *display = nullptr;
  wl_event_loop *event_loop = nullptr;
    EGLDisplay egl_display = EGL_NO_DISPLAY;
    EGLContext egl_context = EGL_NO_CONTEXT;
    EGLConfig egl_config = nullptr;
};

const struct wl_surface_interface MinimalCompositor::surface_implementation = {
    // Implement the necessary surface functions here
};

int main(int argc, char *argv[]) {
  try {
    MinimalCompositor compositor;
    compositor.run();
  } catch (const std::exception &e) {
    log_error(std::string("Exception: ") + e.what());
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
