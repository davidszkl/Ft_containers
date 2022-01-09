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
	std::cout << "mine(" << mine.size() << " / " << mine.capacity() << "): {";
	for (; it1 != it2; it1++)
		std::cout << *it1 << ", ";
	std::cout << *it1 << "}" << std::endl;
	std::cout << "stl(" << stl.size() << " / " << stl.capacity() << "):  {";
	for (; it3 != it4; it3++)
		std::cout << *it3 << ", ";
	std::cout << *it3 << "}" << std::endl << std::endl;
}

int main()
{	
	std::allocator<int> alloc;
	ft_vec   mine(5, 10);
	ft_vec   mine2(5, 10);
	ft_vec   empty(0);
	st_vec  stl(5, 10);
	ft::vector<int>::iterator				mine_it1 = mine.begin();
	ft::vector<int>::iterator				mine_it2 = mine.end();
	ft::vector<int>::reverse_iterator		mine_Rit1 = mine.rbegin();
	ft::vector<int>::reverse_iterator		mine_Rit2 = mine.rend();
	std::vector<int>::iterator				stl_it1 = stl.begin();
	std::vector<int>::iterator				stl_it2 = stl.end();
	std::vector<int>::reverse_iterator		stl_Rit1 = stl.rbegin();
	std::vector<int>::reverse_iterator		stl_Rit2 = stl.rend();

	std::cout << "\n==========ITERATORS===========" << std::endl;
	mine.push_back(5);
	stl.push_back(5);
	show(mine, stl);
	std::cout << "mine_it1:  " << *mine_it1 << std::endl;
	std::cout << "mine_it2:  " << *mine_it2++ << std::endl;
	std::cout << "mine_rit1: " << *mine_Rit1 << std::endl;
	std::cout << "mine_rit2: " << *mine_Rit2 << std::endl;
	std::cout << "stl_it1:   " << *stl_it1 << std::endl;
	std::cout << "stl_it2:   " << *stl_it2++ << std::endl;
	std::cout << "stl_rit1:  " << *stl_Rit1 << std::endl;
	std::cout << "stl_rit2:  " << *stl_Rit2 << std::endl;
	std::cout << "empty begin: " << *(empty.begin()) << std::endl;
	std::cout << "empty end:   " << *(empty.end()) << std::endl;

	show(mine, stl);
	std::cout << "==========CAPACITY===========" << std::endl;
	std::cout << "mine_max_size: " << mine.max_size() << std::endl;
	std::cout << "stl_max_size: " << stl.max_size() << std::endl;
	show(mine, stl);

	std::cout << "--------RESIZE_UP :" << std::endl;
	mine.resize(10, 5);
	stl.resize(10, 5);
	std::cout << "mine_max_size: " << mine.max_size() << std::endl;
	std::cout << "stl_max_size: " << stl.max_size() << std::endl;
	show(mine, stl);

	std::cout << "--------RESIZE_DOWN :" << std::endl;
	mine.resize(5, 42);
	stl.resize(5, 42);
	show(mine, stl);

	std::cout << "--------RESIZE_SAME :" << std::endl;
	mine.resize(5, 21);
	stl.resize(5, 21);
	show(mine, stl);

	std::cout << "--------EMPTY :" << std::endl;
	std::cout << mine.empty() << std::endl;
	std::cout << empty.empty() << std::endl;
	std::cout << stl.empty() << std::endl;
	show(mine, stl);

	//STL
	std::cout << "--------RESERVE_MORE :" << std::endl;
	mine.reserve(50);
	stl.reserve(50);
	show(mine, stl);

	std::cout << "--------RESERVE_LESS :" << std::endl;
	mine.reserve(25);
	stl.reserve(25);
	show(mine, stl);

	std::cout << "--------RESERVE_SAME :" << std::endl;
	mine.reserve(25);
	stl.reserve(25);
	show(mine, stl);

	std::cout << "==========ELEMENT_ACCESS===========" << std::endl;
	mine[0] = 1;
	mine[1] = 3;
	stl[0] = 1;
	stl[1] = 3;
	show(mine, stl);

	std::cout << "--------OPERATOR[] :" << std::endl;
	std::cout << "mine[0]: " << mine[0] << std::endl;
	std::cout << "mine[1]: " << mine[1] << std::endl;

	std::cout << "stl[0]:  " << stl[0] << std::endl;
	std::cout << "stl[1]:  " << stl[1] << std::endl << std::endl;

	std::cout << "--------NORMAL_AT(3) :" << std::endl;
	std::cout << "mine: " << mine.at(3) << std::endl;
	std::cout << "stl:  " << stl.at(3) << std::endl << std::endl;

	std::cout << "--------OUT_OF_BOUNDS_AT(15) :" << std::endl;
	try {
		std::cout << "mine: " << mine.at(15) << std::endl;}
	catch  (std::exception &e){std::cout << e.what() << std::endl;}
	try {
		std::cout << "stl:  " << stl.at(15) << std::endl;}
	catch  (std::exception &e){std::cout << e.what() << std::endl << std::endl;}

	std::cout << "--------FRONT :" << std::endl;
	std::cout << "mine: " << mine.front() << std::endl;
	std::cout << "stl:  " << stl.front() << std::endl << std::endl;

	std::cout << "--------BACK :" << std::endl;
	std::cout << "mine: " << mine.back() << std::endl;
	std::cout << "stl:  " << stl.back() << std::endl << std::endl;

	std::cout << "==========MODIFIERS===========" << std::endl;
	return 0;
}
