cmake_minimum_required(VERSION 2.8)

project(hypergamy_in_matching_markets)


set(SOURCE_EXE main.cpp)


set(SOURCE_LIB graph_generation.cpp)
set(HEADERS_LIB graph_generation.h)
add_library(graph_generation ${SOURCE_LIB} ${HEADERS_LIB})

set(SOURCE_LIB make_priorities.cpp)
set(HEADERS_LIB make_priorities.h)
add_library(make_priorities ${SOURCE_LIB} ${HEADERS_LIB})


set(SOURCE_LIB get_matching.cpp)
set(HEADERS_LIB get_matching.h)
add_library(get_matching ${SOURCE_LIB} ${HEADERS_LIB})


set(SOURCE_LIB fertility_cleaning.cpp)
set(HEADERS_LIB fertility_cleaning.h)
add_library(fertility_cleaning ${SOURCE_LIB} ${HEADERS_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main graph_generation make_priorities get_matching fertility_cleaning)
