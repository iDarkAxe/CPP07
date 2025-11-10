#include <iostream>
#include <Array.hpp>

// Needed for Mandatory as we can't use srand without it
#include <cstdlib>

// More tests
#include <limits>
#include <iomanip>

int mandatory(void);
void simple_test(void);
void ascii_test(void);

#define MAX_VAL 10
// #define MAX_VAL 750

int main(int, char**)
{
	mandatory();
	simple_test();
	ascii_test();
}

void simple_test(void)
{
	int *a = new int();
	std::cout << "Test with int array:\n\t" << a << " = " << *a << std::endl;
	delete a;
	Array<int> numbers(1);
	std::cout << "Test with class Array<int>[0]:\n\t" << &numbers << " = " << numbers[0] << std::endl;
	Array<int> noelem(0);
	try {
		std::cout << "Test with class Array<int>[0]:\n\t" << &noelem << " = " << noelem[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void ascii_test(void)
{
	size_t nbr_elements = std::numeric_limits<char>::max() * 2 + 2;
	Array<char> numbers(nbr_elements);
	for (size_t i = 0; i < nbr_elements; i++)
	{
		numbers[i] = i;
	}
	for (size_t i = 0; i < nbr_elements; i++)
	{
		std::cout << "numbers[" << std::setw(3) << std::setfill(' ') << i << "] = " << static_cast<int>(numbers[i]) << " -> " << static_cast<char>(numbers[i]) << std::endl;
	}
}

int mandatory(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "Numbers array content:" << std::endl;
	numbers.print(MAX_VAL);

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "\nTmp array content:" << std::endl;
		tmp.print(MAX_VAL);
		std::cout << "\nTest array content:" << std::endl;
		test.print(MAX_VAL);
		std::cout << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cout << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "\nNumbers array content before:" << std::endl;
	numbers.print();
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "\nNumbers array content after:" << std::endl;
	numbers.print();

	delete [] mirror;//
	return 0;
}
