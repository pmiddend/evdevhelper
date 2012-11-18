cmake_minimum_required(VERSION 2.6)

project(joypad)

include(
	FcpptCMakeUtils)

include(
	FcpptSymbol)

find_package(
	Boost 1.45.0 REQUIRED COMPONENTS
	chrono
	system)

include_directories(
	${Boost_INCLUDE_DIR})
link_directories(
	${Boost_LIBRARY_DIRS})
# boost end

# fcppt begin
find_package(
	fcppt REQUIRED)
include_directories(
	${fcppt_INCLUDE_DIRS})
add_definitions(
	${fcppt_DEFINITIONS})
# fcppt end

add_definitions(
	-Wno-old-style-cast -std=c++0x)

set(
	JOYPAD_COMMON_FILES
	retrieve_parts.cpp
	has_keys.cpp
	is_mouse.cpp)

add_executable(
	joypad_echo_buttons
	echo_buttons.cpp
	${JOYPAD_COMMON_FILES})

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
