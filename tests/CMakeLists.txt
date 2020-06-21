set(BINARY ${CMAKE_PROJECT_NAME}_tests)

set(TEST_SOURCES main.cpp tuple_tests.cpp)

add_executable(${BINARY} ${TEST_SOURCES})

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
target_compile_options(${BINARY} PRIVATE ${CXX_COMPILE_FLAGS})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
