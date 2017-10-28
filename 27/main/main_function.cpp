/**
 *
 * \file main_function.cpp
 *
 * \brief C++ file to demonstrate basic arithmetic operations for the purpose of learning to work with GNU make
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>
#include "../include/add_two_numbers.hpp"
#include "../include/subtract_two_numbers.hpp"

using namespace std;

int main(int argc, char **argv)
{
	cout << AddTwoNumbers(1, 2) << endl;
	cout << SubtractTwoNumbers(1, 2) << endl;

	return 0;
}

