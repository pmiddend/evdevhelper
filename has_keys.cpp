#include "has_keys.hpp"
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>

bool
joypad::has_keys(
	joypad::part_sequence const &_parts)
{
	if(_parts.size() < 4)
		return true;

	joypad::part const max_lower_part =
		(*std::max_element(
			_parts.rbegin(),
			std::next(
				_parts.rbegin(),
				4)));

	return
		max_lower_part != 0u;
}
