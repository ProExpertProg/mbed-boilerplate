function(add_unit_test NAME)
    add_executable(${NAME} run-test.cpp ${ARGN})

    target_link_libraries(${NAME} gtest gtest_main)
    target_compile_definitions(${NAME} PRIVATE ENV_TEST=TRUE)
    add_test(${NAME} ${NAME})
endfunction()