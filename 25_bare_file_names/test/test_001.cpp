/**
 *
 * \file test_001.cpp
 *
 * \brief Simple test harness to accustom users to the idea of a separate test/ directory.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>
#include "../include/add_two_numbers.hpp"

using namespace std;

int main(int argc, char **argv)
{
	if(AddTwoNumbers(1, 2) == 3)
	{
		cout << "1 + 2 = 3" << endl;
	}
	else
	{
		cerr << "1 + 2 != 3" << endl;
	}

	return 0;
}

