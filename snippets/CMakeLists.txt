CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
SET(CMAKE_CXX_STANDARD 14)

project(grootc)

find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(LLVM_LIBS core native orcjit support)

add_executable(fntest fn.cpp)
target_link_libraries(fntest PRIVATE ${LLVM_LIBS})


add_executable(whiletest while.cpp)
target_link_libraries(whiletest PRIVATE ${LLVM_LIBS})
