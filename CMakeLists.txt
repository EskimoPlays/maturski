cmake_minimum_required(VERSION 3.10.0)
project(Maturski VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp src/*.h src/*.inl)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Audio SFML::Graphics SFML::Window SFML::System)

set(RESOURCES_SOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
set(RESOURCES_OUTPUT_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCES_SOURCE_DIR} ${RESOURCES_OUTPUT_DIR}
)