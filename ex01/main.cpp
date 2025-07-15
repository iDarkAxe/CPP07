
#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstring>

// Tests
void test_on_int(void);
void test_on_char(void);

// Utils
void print_int_as_char(const int *s, size_t len, const std::string &text);
void toupper_and_assign(char &c);
void isdigit_and_assign(char &c);
void tolower_and_assign(int &c);
void isvowel_and_assign(int &c);

int main(void)
{
	test_on_char();
	test_on_int();
}

void test_on_char(void)
{
	char array[100];
	strncpy(array, "Hello, World! My fav number is 42.", 100);
	std::cout << "Original: " << array << std::endl;

	::iter(array, std::strlen(array), toupper);
	std::cout << "toupper: " << array << std::endl;

	::iter(array, std::strlen(array), isdigit);
	std::cout << "isdigit: " << array << std::endl;

	::iter(array, std::strlen(array), toupper_and_assign);
	std::cout << "toupper_and_assign: " << array << std::endl;

	::iter(array, std::strlen(array), isdigit_and_assign);
	std::cout << "isdigit_and_assign: " << array << std::endl;
}

void test_on_int(void)
{
	int array[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

	size_t len = 35;
	print_int_as_char(array, len, "Original: ");
	
	::iter(array, len, tolower);
	print_int_as_char(array, len, "tolower: ");\

	::iter(array, len, isdigit);
	print_int_as_char(array, len, "isdigit: ");
	
	::iter(array, len, tolower_and_assign);
	print_int_as_char(array, len, "tolower_and_assign: ");

	::iter(array, len, isvowel_and_assign);
	print_int_as_char(array, len, "isvowel_and_assign: ");
}

/* Renvoie la valeur majuscule du caractère si miniscule
sinon renvoie le caractère tel quel */
void toupper_and_assign(char &c)
{
	if (std::toupper(c) != c)
		c -= 32;
}

/* info isdigit: Si c == digit, return != 0 */
void isdigit_and_assign(char &c)
{
	if (std::isdigit(c) != 0)
		c = '1';
	else
		c = '0';
}

/* Renvoie la valeur miniscule du caractère si majuscule 
sinon renvoie le caractère tel quel */
void tolower_and_assign(int &c)
{
	if (std::tolower(c) != c)
		c += 32;
}

/* Si c est une voyelle, return assigne '1' à c sinon '0' */
void isvowel_and_assign(int &c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
		c = '1';
	else
		c = '0';
}

/**
 * Prints the integer array as characters.
 * @param s Pointer to the integer array.
 * @param len Length of the array.
 * @param text Text to print before the characters.
 */
void print_int_as_char(const int *s, size_t len, const std::string &text)
{
	if (s == NULL || len == 0)
		return;
	std::cout << text;
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << static_cast<char>(s[i]);
		if (i != len - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}
