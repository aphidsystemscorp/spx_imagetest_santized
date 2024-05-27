cmake_minimum_required(VERSION 3.10)
project(compositor)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(WAYLAND_SERVER REQUIRED wayland-server)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)
pkg_check_modules(WAYLAND_EGL REQUIRED wayland-egl)
pkg_check_modules(WAYLAND_CURSOR REQUIRED wayland-cursor)
pkg_check_modules(EGL REQUIRED egl)
pkg_check_modules(OPENGL_ES2 REQUIRED glesv2)

#pkg_check_modules(PTHREAD REQUIRED pthread)

include_directories(${WAYLAND_SERVER_INCLUDE_DIRS})
link_directories(${WAYLAND_SERVER_LIBRARY_DIRS})

add_executable(compositor ${PROJECT_SOURCE_DIR}/compositor.cpp)
target_link_libraries(compositor ${WAYLAND_SERVER_LIBRARIES} )
install(TARGETS compositor DESTINATION  bin)

add_executable(simple-egl 
               ${PROJECT_SOURCE_DIR}/simple-egl.cpp 
               ${PROJECT_SOURCE_DIR}/simple-egl-display.cpp 
               ${PROJECT_SOURCE_DIR}/simple-egl-window.cpp)

target_link_libraries(simple-egl     ${WAYLAND_CLIENT_LIBRARIES}
    ${WAYLAND_EGL_LIBRARIES}
    ${WAYLAND_CURSOR_LIBRARIES}
    ${EGL_LIBRARIES}
    ${OPENGL_ES2_LIBRARIES}
 )
install(TARGETS simple-egl DESTINATION  bin)