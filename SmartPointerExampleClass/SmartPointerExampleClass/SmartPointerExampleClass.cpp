#include <iostream>
#include <vector>
#include "SmartPointer.h"

using std::cout;
using std::cin;

int main()
{
	SmartPointer<std::vector<long>> numbers(new std::vector<long>{});

	long temp_input = 0;
	for (size_t i = 0; i < 10; i++)
	{
		cin >> temp_input;
		numbers->push_back(temp_input);
	}
	cout << '\n';

	for (const auto n : *numbers)
	{
		cout << n << ", ";
	}

	return 0;
}