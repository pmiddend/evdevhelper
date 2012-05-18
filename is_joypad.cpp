#include "sysfs_path_for_device_name.hpp"
#include "retrieve_parts.hpp"
#include "has_keys.hpp"
#include "is_mouse.hpp"
#include <fcppt/config/external_begin.hpp>
#include <linux/input.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace
{
std::string const error_file{
	"/tmp/joypad_errors"};
}

int
main(
	int argc,
	char *argv[])
try
{
	{
		std::ofstream error_output_stream(
			error_file,
			std::ios::app);

		if(argc < 2)
		{
			error_output_stream << "Please give me a device path...\n";
			return EXIT_FAILURE;
		}
	}

	joypad::device_name const device_name{
		std::string{
			argv[1]}};

	joypad::part_sequence const parts{
		joypad::retrieve_parts(
			joypad::sysfs_path_for_device_name(
				device_name))};

	std::cout << "Has keys: " << std::boolalpha << joypad::has_keys(parts) << ", is mouse: " << std::boolalpha << joypad::is_mouse(parts) << "\n";

	return
		!joypad::has_keys(
			parts) &&
		!joypad::is_mouse(
			parts)
		?
			EXIT_SUCCESS
		:
			EXIT_FAILURE;
}
catch(
	std::exception const &e)
{
	std::ofstream error_output_stream(
		error_file,
		std::ios::app);

	error_output_stream << e.what() << "\n";

	return
		EXIT_FAILURE;
}
catch(...)
{
	std::ofstream error_output_stream(
		error_file,
		std::ios::app);

	error_output_stream << "unknown error\n";

	return
		EXIT_FAILURE;
}
