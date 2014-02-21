cmake_minimum_required(VERSION 2.6)

project(joypad)

include(
	FcpptCMakeUtils)

include(
	FcpptSymbol)

find_package(
	Boost 1.45.0 REQUIRED COMPONENTS
	filesystem
	system)

include_directories(
	${Boost_INCLUDE_DIR})
link_directories(
	${Boost_LIBRARY_DIRS})
# boost end

find_package(
	fcppt REQUIRED)

set(
	JOYPAD_COMMON_FILES
	retrieve_parts.cpp
	has_keys.cpp
	is_mouse.cpp)

add_executable(
	joypad_echo_buttons
	echo_buttons.cpp
	${JOYPAD_COMMON_FILES})

fcppt_utils_set_target_compiler_flags(
	joypad_echo_buttons)

target_link_libraries(
	joypad_echo_buttons
	${fcppt_core_TARGET}
	${fcppt_filesystem_TARGET}
	${Boost_LIBRARIES})

install(
	TARGETS
	joypad_echo_buttons
	DESTINATION
	${INSTALL_BINARY_DIR})

add_executable(
	joypad_is_joypad
	is_joypad.cpp
	${JOYPAD_COMMON_FILES})

fcppt_utils_set_target_compiler_flags(
	joypad_is_joypad)

target_link_libraries(
	joypad_is_joypad
	${fcppt_core_TARGET}
	${fcppt_filesystem_TARGET}
	${Boost_LIBRARIES})

install(
	TARGETS
	joypad_is_joypad
	DESTINATION
	${INSTALL_BINARY_DIR})
