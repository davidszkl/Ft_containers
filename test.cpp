#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.hpp"
#include <chrono>
#include <unistd.h>

typedef ft::vector<int, std::allocator<int> > ft_vec;
typedef std::vector<int, std::allocator<int> > st_vec;
int main()
{
	using namespace std::chrono;
	std::allocator<int> alloc;
	ft_vec   mine(5, 10);
	ft_vec   mine2(5, 42);
	ft_vec   empty(0);

	st_vec  stl(5, 10);
	st_vec  stl2(5, 6);
	st_vec	stl_empty(0);

	ft::vector<int>::iterator				mine_it1 = mine.begin();
	ft::vector<int>::iterator				mine_it2 = mine.end();
	ft::vector<int>::reverse_iterator		mine_Rit1 = mine.rbegin();
	ft::vector<int>::reverse_iterator		mine_Rit2 = mine.rend();

	std::vector<int>::iterator				stl_it1 = stl.begin();
	std::vector<int>::iterator				stl_it2 = stl.end();
	std::vector<int>::reverse_iterator		stl_Rit1 = stl.rbegin();
	std::vector<int>::reverse_iterator		stl_Rit2 = stl.rend();

	high_resolution_clock					clock;
	high_resolution_clock::time_point		t1;
	high_resolution_clock::time_point		t2;
	microseconds::rep 						time_span1;
	microseconds::rep 						time_span2;

	std::cout << "mine = {";
	for(size_t n = 0; n < mine.size(); n++)
	{
		mine[n] = n + 1;
 		std::cout << mine[n] << ", ";
	}
	std::cout << "}" << std::endl;
	mine.erase(mine.begin(), mine.begin() + 2);
	std::cout << "in main: " << *mine.begin() << std::endl;
	std::cout << "mine = {";
	for(size_t n = 0; n < mine.size(); n++)
 		std::cout << mine[n] << ", ";
	std::cout << "}" << std::endl;
	return 0;
}