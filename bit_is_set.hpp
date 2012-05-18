#ifndef JOYPAD_BIT_IS_SET_HPP_INCLUDED
#define JOYPAD_BIT_IS_SET_HPP_INCLUDED

namespace joypad
{
template<typename T,typename U>
bool
bit_is_set(
	T const _bit_set,
	U const _test_mask)
{
	return
		_bit_set & (static_cast<T>(1) << static_cast<T>(_test_mask));
}
}

#endif
