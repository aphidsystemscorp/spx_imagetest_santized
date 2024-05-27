#include "test-egl.h"

///////////////////////////////////////////////////////////////////////////////

Display::Display() {
  display = wl_display_connect(nullptr);
  if (!display) {
    throw std::runtime_error("Failed to connect to Wayland display");
  }

  registry = wl_display_get_registry(display);
  wl_registry_add_listener(registry, &registry_listener, this);

  wl_display_dispatch(display);
  wl_display_roundtrip(display);
}

///////////////////////////////////////////////////////////////////////////////

Display::~Display() {
  if (cursor_surface)
    wl_surface_destroy(cursor_surface);
  if (cursor_theme)
    wl_cursor_theme_destroy(cursor_theme);
  if (shell)
    wl_shell_destroy(shell);
  if (compositor)
    wl_compositor_destroy(compositor);
  wl_registry_destroy(registry);
  wl_display_flush(display);
  wl_display_disconnect(display);
}

///////////////////////////////////////////////////////////////////////////////

void Display::registry_handle_global(void *data, struct wl_registry *registry,
                                     uint32_t name, const char *interface,
                                     uint32_t version) {
  auto *d = static_cast<Display *>(data);

  if (strcmp(interface, "wl_compositor") == 0) {
    d->compositor = static_cast<wl_compositor *>(
        wl_registry_bind(registry, name, &wl_compositor_interface, 1));
  } else if (strcmp(interface, "wl_shell") == 0) {
    d->shell = static_cast<wl_shell *>(
        wl_registry_bind(registry, name, &wl_shell_interface, 1));
  } else if (strcmp(interface, "wl_seat") == 0) {
    d->seat = static_cast<wl_seat *>(
        wl_registry_bind(registry, name, &wl_seat_interface, 1));
    wl_seat_add_listener(d->seat, &seat_listener, d);
  } else if (strcmp(interface, "wl_shm") == 0) {
    d->shm = static_cast<wl_shm *>(
        wl_registry_bind(registry, name, &wl_shm_interface, 1));
    d->cursor_theme = wl_cursor_theme_load(nullptr, 32, d->shm);
    d->default_cursor = wl_cursor_theme_get_cursor(d->cursor_theme, "left_ptr");
  }
}

///////////////////////////////////////////////////////////////////////////////

void Display::registry_handle_global_remove(void *data,
                                            struct wl_registry *registry,
                                            uint32_t name) {
  // Handle global remove event if necessary
}

///////////////////////////////////////////////////////////////////////////////

const struct wl_registry_listener Display::registry_listener = {
    Display::registry_handle_global, Display::registry_handle_global_remove};

///////////////////////////////////////////////////////////////////////////////

const struct wl_seat_listener Display::seat_listener = {
    [](void *data, struct wl_seat *seat, uint32_t caps) {
      auto *d = static_cast<Display *>(data);

      if ((caps & WL_SEAT_CAPABILITY_POINTER) && !d->pointer) {
        d->pointer = wl_seat_get_pointer(seat);
        wl_pointer_add_listener(d->pointer, &pointer_listener, d);
      } else if (!(caps & WL_SEAT_CAPABILITY_POINTER) && d->pointer) {
        wl_pointer_destroy(d->pointer);
        d->pointer = nullptr;
      }

      if ((caps & WL_SEAT_CAPABILITY_KEYBOARD) && !d->keyboard) {
        d->keyboard = wl_seat_get_keyboard(seat);
        wl_keyboard_add_listener(d->keyboard, &keyboard_listener, d);
      } else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD) && d->keyboard) {
        wl_keyboard_destroy(d->keyboard);
        d->keyboard = nullptr;
      }
    }};

///////////////////////////////////////////////////////////////////////////////

const struct wl_pointer_listener Display::pointer_listener = {
    [](void *data, struct wl_pointer *pointer, uint32_t serial,
       struct wl_surface *surface, wl_fixed_t sx, wl_fixed_t sy) {
      auto *d = static_cast<Display *>(data);
      struct wl_buffer *buffer;
      struct wl_cursor *cursor = d->default_cursor;
      struct wl_cursor_image *image;

      if (d->window->fullscreen) {
        wl_pointer_set_cursor(pointer, serial, nullptr, 0, 0);
      } else if (cursor) {
        image = cursor->images[0];
        buffer = wl_cursor_image_get_buffer(image);
        wl_pointer_set_cursor(pointer, serial, d->cursor_surface,
                              image->hotspot_x, image->hotspot_y);
        wl_surface_attach(d->cursor_surface, buffer, 0, 0);
        wl_surface_damage(d->cursor_surface, 0, 0, image->width, image->height);
        wl_surface_commit(d->cursor_surface);
      }
    },
    [](void *data, struct wl_pointer *pointer, uint32_t serial,
       struct wl_surface *surface) {
      // Handle leave event if necessary
    },
    [](void *data, struct wl_pointer *pointer, uint32_t time, wl_fixed_t sx,
       wl_fixed_t sy) {
      // Handle motion event if necessary
    },
    [](void *data, struct wl_pointer *pointer, uint32_t serial, uint32_t time,
       uint32_t button, uint32_t state) {
      auto *d = static_cast<Display *>(data);

      if (button == BTN_LEFT && state == WL_POINTER_BUTTON_STATE_PRESSED) {
        wl_shell_surface_move(d->window->shell_surface, d->seat, serial);
      }
    },
    [](void *data, struct wl_pointer *pointer, uint32_t time, uint32_t axis,
       wl_fixed_t value) {
      // Handle axis event if necessary
    }};

///////////////////////////////////////////////////////////////////////////////

const struct wl_keyboard_listener Display::keyboard_listener = {
    [](void *data, struct wl_keyboard *keyboard, uint32_t format, int fd,
       uint32_t size) {
      // Handle keymap event if necessary
    },
    [](void *data, struct wl_keyboard *keyboard, uint32_t serial,
       struct wl_surface *surface, struct wl_array *keys) {
      // Handle enter event if necessary
    },
    [](void *data, struct wl_keyboard *keyboard, uint32_t serial,
       struct wl_surface *surface) {
      // Handle leave event if necessary
    },
    [](void *data, struct wl_keyboard *keyboard, uint32_t serial, uint32_t time,
       uint32_t key, uint32_t state) {
      auto *d = static_cast<Display *>(data);

      if (key == KEY_F11 && state) {
        d->window->toggle_fullscreen(!d->window->fullscreen);
      } else if (key == KEY_ESC && state) {
        SimpleEGL::running = 0;
      }
    },
    [](void *data, struct wl_keyboard *keyboard, uint32_t serial,
       uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked,
       uint32_t group) {
      // Handle modifiers event if necessary
    }};
