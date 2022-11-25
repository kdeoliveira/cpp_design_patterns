
function(do_test target name result)
	add_test(NAME ${name} COMMAND ${target} ${name})
	set_tests_properties(${name} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()