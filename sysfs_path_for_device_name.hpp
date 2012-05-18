#ifndef JOYPAD_SYSFS_PATH_FOR_DEVICE_NAME_HPP_INCLUDED
#define JOYPAD_SYSFS_PATH_FOR_DEVICE_NAME_HPP_INCLUDED

#include "device_name.hpp"
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>

namespace joypad
{
inline boost::filesystem::path const
sysfs_path_for_device_name(
	joypad::device_name const &_name)
{
	return
		boost::filesystem::path{
			std::string{
				"/sys/class/input/"+
				_name.get()+
				"/device/capabilities/key"}};
}
}

#endif
