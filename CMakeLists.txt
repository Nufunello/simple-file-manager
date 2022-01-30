cmake_minimum_required(VERSION 3.2)

project("Simple File Manager" VERSION 1.0)

add_executable(core "src/main.cpp")
set_target_properties(core PROPERTIES OUTPUT_NAME "Simple File Manager")

#Import third party
set(THIRD_PARTY_DIR "third-party")

#ASIO, Beast for server and their dependecies
set(BOOST_LIBS 
	"beast" "asio" 
	"config" "regex" "system" "coroutine" "assert" "throw_exception" "align"
	"winapi" "predef" "date_time" "smart_ptr" "core" "utility" "static_assert"
	"type_traits" "numeric_conversion" "mpl" "preprocessor" "bind"
	"tokenizer" "iterator" "move" "range" "io" "conversion" "lexical_cast"
	"algorithm" "integer" "container" "array" "unordered" "tuple" "optional"
	"detail" "container_hash" "concept_check" "fusion" "intrusive" "typeof"
	"function_types" "function" "exception" "variant2" "context" "pool"
	"mp11" "type_index" "logic"
)

foreach(BOOST_LIB_NAME IN LISTS BOOST_LIBS)

	set(BOOST_LIB_DIR "${THIRD_PARTY_DIR}/boost/${BOOST_LIB_NAME}")
	add_subdirectory("${BOOST_LIB_DIR}")
	include_directories("${BOOST_LIB_DIR}/include/")

endforeach()

#undefined reference to `__imp_WSACleanup'
if(WIN32)
	target_link_libraries(core wsock32 ws2_32)
endif()
