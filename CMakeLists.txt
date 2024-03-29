CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
SET(CMAKE_CXX_STANDARD 14)

project(grootc)

find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(LLVM_LIBS core native orcjit support)
find_package(antlr4-runtime REQUIRED)

SET(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/antlr/antlr-4.9.3-complete.jar)

include_directories(/usr/local/include/antlr4-runtime/ ${ANTLR4CPP_INCLUDE_DIRS})
link_directories(${ANTLR4CPP_LIBS})
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

execute_process(COMMAND java -jar ${ANTLR4CPP_JAR_LOCATION} -Dlanguage=Cpp -o parser -no-listener -visitor groot.g4
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        RESULT_VARIABLE antlr4_result
        OUTPUT_VARIABLE antlr4_output)

if (${antlr4_result})
    message(FATAL_ERROR "antlr failed: ${antlr4_result}: ${antlr4_output}, CMake will exit.")
else ()
    message(STATUS "lex/parse file generated successfully.")
endif ()

add_executable(grootc
        parser/grootLexer.cpp
        parser/grootParser.cpp
        parser/grootVisitor.cpp
        visitorimpl.cpp
        main.cpp
        )

add_dependencies(grootc antlr4_static)
target_link_libraries(grootc PRIVATE antlr4_static ${LLVM_LIBS})

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS groot.g4)
