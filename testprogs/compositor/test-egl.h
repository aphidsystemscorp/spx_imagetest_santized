#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <cmath>
#include <csignal>
#include <cassert>
#include <memory>
#include <linux/input.h>

extern "C" {
#include <wayland-client.h>
#include <wayland-egl.h>
#include <wayland-cursor.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
}

class Window;
class Display;

void log_error(const std::string& message);
void log_info(const std::string& message);

class SimpleEGL {
public:
    SimpleEGL(int argc, char** argv);
    void run();
    static bool parse_arg(int argc, char** argv, const char* option);
    static void signal_int(int signum);
    static int running;

    std::unique_ptr<Display> display;
    std::unique_ptr<Window> window;
};

class Window {
public:
    Window(Display* display, int width, int height, bool fullscreen, bool opaque);
    ~Window();
    void redraw(uint32_t time);
    void toggle_fullscreen(bool fullscreen);
    void create_surface();
    void destroy_surface();
    void init_egl();
    void fini_egl();
   	void init_gl();

    GLuint create_shader(const char* source, GLenum shader_type);
    static void handle_ping(void* data, struct wl_shell_surface* shell_surface, uint32_t serial);
    static void handle_configure(void* data, struct wl_shell_surface* shell_surface, uint32_t edges,
                                 int32_t width, int32_t height);
    static void handle_popup_done(void* data, struct wl_shell_surface* shell_surface);
    static void configure_callback(void* data, struct wl_callback* callback, uint32_t time);

    static const struct wl_shell_surface_listener shell_surface_listener;
    static const struct wl_callback_listener configure_callback_listener;
    static const struct wl_callback_listener frame_listener;

    Display* display;
    struct geometry {
        int width, height;
    } geometry, window_size;

    struct {
        GLuint rotation_uniform;
        GLuint pos;
        GLuint col;
    } gl;

    struct wl_egl_window* native = nullptr;
    struct wl_surface* surface = nullptr;
    struct wl_shell_surface* shell_surface = nullptr;
    EGLSurface egl_surface = nullptr;
    struct wl_callback* callback = nullptr;
    bool fullscreen = false;
    bool configured = false;
    bool opaque = false;
};

class Display {
public:
    Display();
    ~Display();

    struct wl_display* get_display() { return display; }
    struct wl_compositor* get_compositor() { return compositor; }
    struct wl_shell* get_shell() { return shell; }

    struct {
        EGLDisplay dpy;
        EGLContext ctx;
        EGLConfig conf;
    } egl;

private:
    static void registry_handle_global(void* data, struct wl_registry* registry,
                                       uint32_t name, const char* interface, uint32_t version);
    static void registry_handle_global_remove(void* data, struct wl_registry* registry, uint32_t name);

    static const struct wl_registry_listener registry_listener;
    static const struct wl_seat_listener seat_listener;
    static const struct wl_pointer_listener pointer_listener;
    static const struct wl_keyboard_listener keyboard_listener;

	Window* window = nullptr;
    struct wl_display* display = nullptr;
    struct wl_registry* registry = nullptr;
    struct wl_compositor* compositor = nullptr;
    struct wl_shell* shell = nullptr;
    struct wl_seat* seat = nullptr;
    struct wl_pointer* pointer = nullptr;
    struct wl_keyboard* keyboard = nullptr;
    struct wl_shm* shm = nullptr;
    struct wl_cursor_theme* cursor_theme = nullptr;
    struct wl_cursor* default_cursor = nullptr;
    struct wl_surface* cursor_surface = nullptr;
};
