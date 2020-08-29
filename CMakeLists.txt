cmake_minimum_required(VERSION 3.17)
project(Julia_Set)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
        ${CMAKE_MODULE_PATH})

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_MODULE_PATH}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_MODULE_PATH}/conan.cmake")
endif()

include(${CMAKE_MODULE_PATH}/conan.cmake)
conan_add_remote(NAME bincrafters URL
        https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(REQUIRES
        sfml/2.5.1@bincrafters/stable
        BASIC_SETUP
        BUILD missing)

add_executable(${CMAKE_PROJECT_NAME} Main.cpp Julia_Set.cpp Julia_Set.h)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CONAN_LIBS})