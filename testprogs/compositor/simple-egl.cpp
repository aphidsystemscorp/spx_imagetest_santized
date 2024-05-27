#include "simple-egl.h"

///////////////////////////////////////////////////////////////////////////////

SimpleEGL::SimpleEGL(int argc, char **argv)
    : display(std::make_unique<Display>()),
      window(std::make_unique<Window>(display.get(), 250, 250,
                                      parse_arg(argc, argv, "-f"),
                                      parse_arg(argc, argv, "-o"))) {
  struct sigaction sigint;
  sigint.sa_handler = signal_int;
  sigemptyset(&sigint.sa_mask);
  sigint.sa_flags = SA_RESETHAND;
  sigaction(SIGINT, &sigint, nullptr);
}

///////////////////////////////////////////////////////////////////////////////

void SimpleEGL::run() {
  int ret = 0;
  while (running && ret != -1) {
    ret = wl_display_dispatch(display->get_display());
  }
  std::cerr << "simple-egl exiting" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////

bool SimpleEGL::parse_arg(int argc, char **argv, const char *option) {
  for (int i = 1; i < argc; ++i) {
    if (strcmp(option, argv[i]) == 0)
      return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

void SimpleEGL::signal_int(int signum) { running = 0; }

///////////////////////////////////////////////////////////////////////////////

int SimpleEGL::running = 1;

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
  try {
    SimpleEGL app(argc, argv);
    app.run();
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
