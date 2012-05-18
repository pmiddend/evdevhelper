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
	Fcppt REQUIRED)
include_directories(
	${Fcppt_INCLUDE_DIRS})
add_definitions(
	${Fcppt_DEFINITIONS})
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
	${Fcppt_core_LIBRARIES}
	${Fcppt_filesystem_LIBRARIES}
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
	${Fcppt_core_LIBRARIES}
	${Fcppt_filesystem_LIBRARIES}
	${Boost_LIBRARIES})

install(
	TARGETS
	joypad_is_joypad
	DESTINATION
	${INSTALL_BINARY_DIR})
