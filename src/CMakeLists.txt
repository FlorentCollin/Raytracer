set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES main.cpp tuple.h)

add_executable(${BINARY}_run ${SOURCES})

set(CXX_COMPILE_FLAGS
    -Wall
    -Wextra
    -Wshadow
    -Wformat=2
    -Wundef
    -Wconversion
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion)
target_compile_options(${BINARY}_run PRIVATE ${CXX_COMPILE_FLAGS})

add_library(${BINARY}_lib STATIC ${SOURCES})