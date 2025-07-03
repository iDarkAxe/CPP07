#include "whatever.hpp"
#include <iostream>

// Mandatory
int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// More tests
// int main( void ) {
// 	{
// 		float a = 2.8f;
// 		float b = 3.5f;
		
// 		std::cout << "a = " << a << ", b = " << b << std::endl;
// 		::swap( a, b );
// 		std::cout << "a = " << a << ", b = " << b << std::endl;
// 		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	}
// 	std::cout << std::endl;
// 	{
// 		long a = 20;
// 		long b = 30;
		
// 		std::cout << "a = " << a << ", b = " << b << std::endl;
// 		::swap( a, b );
// 		std::cout << "a = " << a << ", b = " << b << std::endl;
// 		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	}
// 	std::cout << std::endl;
// 	{
// 		double a = 200.8;
// 		double b = 300.5;
		
// 		std::cout << "a = " << a << ", b = " << b << std::endl;
// 		::swap( a, b );
// 		std::cout << "a = " << a << ", b = " << b << std::endl;
// 		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	}
// 	std::cout << std::endl;
// 	{
// 		char first_letter = 'a';
// 		char other = 'o';
		
// 		std::cout << "first_letter = " << first_letter << ", other = " << other << std::endl;
// 		::swap( first_letter, other );
// 		std::cout << "first_letter = " << first_letter << ", other = " << other << std::endl;
// 		std::cout << "min( first_letter, other ) = " << ::min( first_letter, other ) << std::endl;
// 		std::cout << "max( first_letter, other ) = " << ::max( first_letter, other ) << std::endl;
// 	}
// 	return 0;
// }
