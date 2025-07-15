#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

/**
 * @brief Applies a function to each element of an array.
 * 
 * @tparam T_array template type for the array elements.
 * @tparam T_function template type for the function to apply.
 * @param array array to iterate over
 * @param length size of the array
 * @param function function to apply to each element
 */
template <typename T_array, typename T_function>
void iter(T_array* array, size_t length, T_function function)
{
	if (array == NULL || function == NULL || length == 0)
		return;
	for (size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}

#endif
