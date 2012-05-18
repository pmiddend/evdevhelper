#include "is_mouse.hpp"
#include "bit_is_set.hpp"
#include <fcppt/config/external_begin.hpp>
#include <linux/input.h>
#include <fcppt/config/external_end.hpp>

bool
joypad::is_mouse(
	joypad::part_sequence const &_parts)
{
	if(_parts.size() < 5)
		return false;

	return
		joypad::bit_is_set(
			_parts[_parts.size()-5],
			BTN_MOUSE);
}
