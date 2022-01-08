#include <iostream>
#include "RandIter.hpp"
#include "ReverseRandIter.hpp"
#include "vector.hpp"
#include <algorithm>
#include <vector>

typedef ft::vector<int, std::allocator<int> > ft_vec;
typedef std::vector<int, std::allocator<int> > st_vec;

void show(ft_vec mine, st_vec stl) {
	ft::vector<int>::iterator it1 = mine.begin();
	ft::vector<int>::iterator it2 = mine.end();
	std::vector<int>::iterator it3 = stl.begin();
	std::vector<int>::iterator it4 = stl.end();
	
	it2--;
	it4--;
	std::cout << "mine: {";
	for (; it1 != it2; it1++)
		std::cout << *it1 << ", ";
	std::cout << *it1 << "}" << std::endl;
	std::cout << "stl:  {";
	for (; it3 != it4; it3++)
		std::cout << *it3 << ", ";
	std::cout << *it3 << "}" << std::endl;
}

int main()
{	
	std::allocator<int> alloc;
	ft::vector<int, std::allocator<int> >   mine(10);
	ft::vector<int, std::allocator<int> >   mine2(10);
	ft::vector<int>::iterator				it = mine.begin();
	std::vector<int, std::allocator<int> >  stl(10);

	mine.push_back(10);
	stl.push_back(10);

	show(mine, stl);

	it += 2;
	mine.insert(it, 5, 5);

	show(mine, stl);
	return 0;
}
