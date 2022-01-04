#include <iostream>
#include "RandIter.hpp"
#include "ReverseRandIter.hpp"
#include <algorithm>
int main()
{	
	int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = 0;

	RandIter<int> first(tab);
	RandIter<int> tmp(first);

	std::cout << *first << std::endl;
	std::cout << *tmp	<< std::endl;

	tmp++;

	std::cout << *first << std::endl;
	std::cout << *tmp	<< std::endl;
	std::cout << !size << std::endl;

	return 0;
}
