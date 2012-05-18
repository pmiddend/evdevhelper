#include "retrieve_parts.hpp"
#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
#include <stdexcept>
#include <fcppt/config/external_end.hpp>

joypad::part_sequence const
joypad::retrieve_parts(
	boost::filesystem::path const &_file_name)
{
	boost::filesystem::ifstream file{
		_file_name};

	if(!file.is_open())
	{
		std::string error_output{"file "+_file_name.string<std::string>()};
		if(!boost::filesystem::exists(_file_name))
			error_output += " not found";
		else
			error_output += " couldn't be opened (but it _does_ exist!)";
		throw
			std::runtime_error{
				error_output};
	}

	joypad::part_sequence result;
	joypad::part current_part;

	while(file >> std::hex >> current_part)
		result.push_back(
			current_part);

	if(!file.eof())
		throw
			std::runtime_error(
				"file "+
				_file_name.string<std::string>()+
				" read error on "+
				fcppt::insert_to_std_string(
					result.size())+
				"th part (expected a hex number)");

	return
		result;
}
