cmake_minimum_required(VERSION 3.14)
project(conservatory)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)
include_directories(targets includes includes/data_structures includes/searching includes/sorting ${Boost_INCLUDE_DIRS})

add_executable(conservatory-binary-search targets/conservatory-binary-search.cpp includes/searching/binary_search.h targets/conservatory-binary-search.cpp includes/math_lib.h includes/data_structures/binary_tree.h)
target_link_libraries(conservatory-binary-search ${Boost_LIBS})