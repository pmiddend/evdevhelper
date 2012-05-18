#ifndef JOYPAD_RETRIEVE_PARTS_HPP_INCLUDED
#define JOYPAD_RETRIEVE_PARTS_HPP_INCLUDED

#include "part_sequence.hpp"
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>

namespace joypad
{
joypad::part_sequence const
retrieve_parts(
	boost::filesystem::path const &);
}

#endif
