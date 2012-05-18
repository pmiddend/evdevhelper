#include "bit_is_set.hpp"
#include "sysfs_path_for_device_name.hpp"
#include "retrieve_parts.hpp"
#include <fcppt/config/external_begin.hpp>
#include <linux/input.h>
#include <boost/cstdint.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/filesystem/operations.hpp>
#include <fcppt/config/external_end.hpp>

int
main(
	int argc,
	char *argv[])
try
{
	if(argc < 2)
	{
		std::cerr << "Please give me a device path...\n";
		return EXIT_FAILURE;
	}

	joypad::device_name const device_name{
		std::string{
			argv[1]}};

	joypad::part_sequence const parts{
		joypad::retrieve_parts(
			joypad::sysfs_path_for_device_name(
				device_name))};

	if(parts.size() < 5)
	{
		std::cerr << "Device caps has only " << parts.size() << " parts...\n";
		return EXIT_FAILURE;
	}

	typedef
	std::map
	<
		int,
		std::string
	>
	translation_map;

	translation_map translation
		{
			{0x100,"BTN_MISC"},
			{0x100,"BTN_0"},
			{0x101,"BTN_1"},
			{0x102,"BTN_2"},
			{0x103,"BTN_3"},
			{0x104,"BTN_4"},
			{0x105,"BTN_5"},
			{0x106,"BTN_6"},
			{0x107,"BTN_7"},
			{0x108,"BTN_8"},
			{0x109,"BTN_9"},

			{0x110,"BTN_MOUSE"},
			{0x110,"BTN_LEFT"},
			{0x111,"BTN_RIGHT"},
			{0x112,"BTN_MIDDLE"},
			{0x113,"BTN_SIDE"},
			{0x114,"BTN_EXTRA"},
			{0x115,"BTN_FORWARD"},
			{0x116,"BTN_BACK"},
			{0x117,"BTN_TASK"},

			{0x120,"BTN_JOYSTICK"},
			{0x120,"BTN_TRIGGER"},
			{0x121,"BTN_THUMB"},
			{0x122,"BTN_THUMB2"},
			{0x123,"BTN_TOP"},
			{0x124,"BTN_TOP2"},
			{0x125,"BTN_PINKIE"},
			{0x126,"BTN_BASE"},
			{0x127,"BTN_BASE2"},
			{0x128,"BTN_BASE3"},
			{0x129,"BTN_BASE4"},
			{0x12a,"BTN_BASE5"},
			{0x12b,"BTN_BASE6"},
			{0x12f,"BTN_DEAD"},

			{0x130,"BTN_GAMEPAD"},
			{0x130,"BTN_A"},
			{0x131,"BTN_B"},
			{0x132,"BTN_C"},
			{0x133,"BTN_X"},
			{0x134,"BTN_Y"},
			{0x135,"BTN_Z"},
			{0x136,"BTN_TL"},
			{0x137,"BTN_TR"},
			{0x138,"BTN_TL2"},
			{0x139,"BTN_TR2"},
			{0x13a,"BTN_SELECT"},
			{0x13b,"BTN_START"},
			{0x13c,"BTN_MODE"},
			{0x13d,"BTN_THUMBL"},
			{0x13e,"BTN_THUMBR"},

			{0x140,"BTN_DIGI"},
			{0x140,"BTN_TOOL_PEN"},
			{0x141,"BTN_TOOL_RUBBER"},
			{0x142,"BTN_TOOL_BRUSH"},
			{0x143,"BTN_TOOL_PENCIL"},
			{0x144,"BTN_TOOL_AIRBRUSH"},
			{0x145,"BTN_TOOL_FINGER"},
			{0x146,"BTN_TOOL_MOUSE"},
			{0x147,"BTN_TOOL_LENS"},
			{0x148,"BTN_TOOL_QUINTTAP"},
			{0x14a,"BTN_TOUCH"},
			{0x14b,"BTN_STYLUS"},
			{0x14c,"BTN_STYLUS2"},
			{0x14d,"BTN_TOOL_DOUBLETAP"},
			{0x14e,"BTN_TOOL_TRIPLETAP"},
			{0x14f,"BTN_TOOL_QUADTAP"},
			{0x150,"BTN_WHEEL"},
			{0x150,"BTN_GEAR_DOWN"},
			{0x151,"BTN_GEAR_UP"}
		};

	joypad::part const button_part{
		parts[parts.size()-5u]};

	for(boost::uint64_t i = 0; i < 64; ++i)
		if(joypad::bit_is_set(button_part,i))
			std::cout
				<< std::dec
				<< i
				<< "tes Bit gesetzt: "
				<< translation[static_cast<int>(BTN_0 + i)]
				<< "\n";
}
catch(
	std::exception const &e)
{
	std::cerr << e.what() << "\n";

	return
		EXIT_FAILURE;
}
catch(...)
{
	std::cerr << "unknown error\n";

	return
		EXIT_FAILURE;
}
