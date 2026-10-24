add_library(archbenchs_sort STATIC
    src/quick_sort.cpp
)

target_include_directories(archbenchs_sort PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(archbenchs_sort
    PUBLIC
        archbenchs_common
        OpenMP::OpenMP_CXX
)

if(MSVC)
    target_compile_options(archbenchs_sort PRIVATE /openmp:llvm)
endif()

add_executable(sort_benchmark
    benchmarks/main.cpp
)

target_link_libraries(sort_benchmark PRIVATE
    archbenchs_sort
)

add_executable(sort_test
    tests/sort_test.cpp
)

target_link_libraries(sort_test PRIVATE
    archbenchs_sort
)

add_test(NAME sort_test COMMAND sort_test)
