cmake_minimum_required(VERSION 3.13)

project(Renote C)

find_package(PkgConfig REQUIRED) 

pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET cairo)
pkg_check_modules(GTK+3.0 REQUIRED IMPORTED_TARGET gtk+-3.0)

add_subdirectory(src)
# add_subdirectory(include)

include_directories(${Renote_SOURCE_DIR}/include)

# Renote executable
add_executable(renote
  ${Renote_SOURCE_DIR}/src/renote.c
)

file(COPY gui/ribbon.ui DESTINATION ./)

target_link_libraries(renote PUBLIC
  PkgConfig::GTK+3.0
  PkgConfig::CAIRO
)