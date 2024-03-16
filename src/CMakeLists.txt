cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -mavx2 -mfma -ffast-math")

project(imgui-template)

find_package(SDL2 REQUIRED)

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
set(IMGUI_DIR ${PARENT_DIR}/submodule/imgui)
set(IMGUIFILEDIALOG_DIR ${PARENT_DIR}/submodule/ImGuiFileDialog)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${IMGUIFILEDIALOG_DIR}
    )

add_executable(aubebe
    main.cpp
    aubebe.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
    ${IMGUIFILEDIALOG_DIR}/ImGuiFileDialog.cpp
    )

target_link_libraries(aubebe
    GL
    dl
    ${SDL2_LIBRARIES}
    )
