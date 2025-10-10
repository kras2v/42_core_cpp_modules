#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::cout << "=== Test 1: Basic addNumber and capacity limit ===\n";
	try {
		Span sp(6);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try {
			sp.addNumber(42); // should throw
		} catch (std::exception &e) {
			std::cout << "Expected exception: " << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Exception with too few elements ===\n";
	try {
		Span sp(2);
		sp.addNumber(10);
		sp.shortestSpan(); // should throw
	} catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}

	try {
		Span sp(2);
		sp.addNumber(10);
		sp.longestSpan(); // should throw
	} catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Add range using iterators ===\n";
	try {
		std::vector<int> vec = {10, 20, 30, 40, 50};
		Span sp(10);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Range constructor ===\n";
	try {
		std::vector<int> vec = {1, 2, 3, 4, 5};
		Span sp(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: 10,000 numbers performance test ===\n";
	try {
		Span sp(10000);
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(std::rand());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5(1): 10,000 numbers performance test ===\n";
	try {
		Span sp(10000);
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(i);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy constructor ===\n";
	try {
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(100);
		Span sp2(sp1); // copy constructor
		std::cout << "sp2 shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longest span: " << sp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Copy assignment operator ===\n";
	try {
		Span sp1(3);
		sp1.addNumber(10);
		sp1.addNumber(20);
		Span sp2(5);
		sp2 = sp1;
		std::cout << "sp2 shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longest span: " << sp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	return 0;
}
