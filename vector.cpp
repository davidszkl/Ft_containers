#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.hpp"
#include <chrono>
#include <unistd.h>

typedef ft::vector<int, std::allocator<int> > ft_vec;
typedef const ft::vector< int, std::allocator< int> > ft_const_vec;
typedef std::vector<int, std::allocator<int> > st_vec;
typedef const std::vector<int, std::allocator< int> > st_const_vec;

void show(ft_vec mine, st_vec stl) {
	ft::vector<int>::iterator it1 = mine.begin();
	ft::vector<int>::iterator it2 = mine.end();
	std::vector<int>::iterator it3 = stl.begin();
	std::vector<int>::iterator it4 = stl.end();
	
	it2--;
	it4--;
	std::cout << "mine(" << mine.size() << " / " << mine.capacity() << "): {";
	if (!mine.size())
		std::cout << "}\n";
	else
	{
		for (; it1 != it2; it1++)
			std::cout << *it1 << ", ";
		std::cout << *it1 << "}" << std::endl;
	}
	std::cout << "stl(" << stl.size() << " / " << stl.capacity() << "):  {";
	if (!stl.size())
		std::cout << "}\n";
	else
	{
		for (; it3 != it4; it3++)
			std::cout << *it3 << ", ";
		std::cout << *it3 << "}" << std::endl << std::endl;
	}
}

void show1(ft_vec mine, st_vec stl) {
	ft::vector<int>::iterator it1 = mine.begin();
	ft::vector<int>::iterator it2 = mine.end();
	std::vector<int>::iterator it3 = stl.begin();
	std::vector<int>::iterator it4 = stl.end();
	
	it2--;
	it4--;
	std::cout << "mine2(" << mine.size() << " / " << mine.capacity() << "): {";
	if (!mine.size())
		std::cout << "}\n";
	else
	{
		for (; it1 != it2; it1++)
			std::cout << *it1 << ", ";
		std::cout << *it1 << "}" << std::endl;
	}
	std::cout << "stl(" << stl.size() << " / " << stl.capacity() << "):  {";
	if (!stl.size())
		std::cout << "}\n";
	else
	{
		for (; it3 != it4; it3++)
			std::cout << *it3 << ", ";
		std::cout << *it3 << "}" << std::endl << std::endl;
	}
}

void show2(ft_vec vec1, ft_vec vec2)
{
	ft::vector<int>::iterator it1 = vec1.begin();
	ft::vector<int>::iterator it2 = vec1.end();
	ft::vector<int>::iterator it3 = vec2.begin();
	ft::vector<int>::iterator it4 = vec2.end();

	it2--;
	it4--;
	std::cout << "mine_2(" << vec1.size() << " / " << vec1.capacity() << "): {";
	for (; it1 != it2; it1++)
		std::cout << *it1 << ", ";
	std::cout << *it1 << "}" << std::endl;
	std::cout << "stl2(" << vec2.size() << " / " << vec2.capacity() << "):  {";
	for (; it3 != it4; it3++)
		std::cout << *it3 << ", ";
	std::cout << *it3 << "}" << std::endl;
}

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
	ft::vector<int>::reverse_iterator		mine_Rit1 = mine.rbegin();
	//ft::vector<int>::iterator				mine_it2 = mine.end();
	//ft::vector<int>::reverse_iterator		mine_Rit2 = mine.rend();

	std::vector<int>::iterator				stl_it1 = stl.begin();
	std::vector<int>::reverse_iterator		stl_Rit1 = stl.rbegin();	
	//std::vector<int>::iterator			stl_it2 = stl.end();
	//std::vector<int>::reverse_iterator	stl_Rit2 = stl.rend();

	std::cout << "\n==========ITERATORS===========" << std::endl;

	show(mine, stl);
	show1(mine2, stl2);

	std::cout << "mine_it1:  " << *mine_it1 << std::endl;
	std::cout << "mine_rit1: " << *mine_Rit1 << std::endl;
	std::cout << "stl_it1:   " << *stl_it1 << std::endl;
	std::cout << "stl_rit1:  " << *stl_Rit1 << std::endl;
	std::cout << "empty begin: " << *(empty.begin()) << std::endl;
	std::cout << "empty end:   " << *(empty.end()) << std::endl;
	//std::cout << "mine_it2:  " << *mine_it2 << std::endl;
	//std::cout << "mine_rit2: " << *mine_Rit2 << std::endl;
	//std::cout << "stl_it2:   " << *stl_it2 << std::endl;
	//std::cout << "stl_rit2:  " << *stl_Rit2 << std::endl;


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
	show1(mine2, stl2);
	show(mine, stl);

	std::cout << "-------RANGE_ASSIGN(mine assigned with mine_2, stl assigned with stl_2) :" << std::endl;
	mine.assign(mine2.begin(), mine2.end());
	stl.assign(stl2.begin(), stl2.end());
	show1(mine2, stl2);
	show(mine, stl);

	std::cout << "-------VALUE_ASSIGN(mine2 assigned with 10,15 ; stl assigned with 10,15) :" << std::endl;
	std::cout << "CAP = " << mine2.capacity() << std::endl;
	mine2.assign(10, 15);
	stl2.assign(10, 15);
	std::cout << mine2.size() << std::endl;
	show1(mine2, stl2);
	show(mine, stl);

	std::cout << "--------PUSH_BACK/POP_BACK :" << std::endl;
	std::cout << "push 5 numbers, pop 5 numbers" << std::endl;
	for (int j = 0; j < 5; j++)
	{
		mine.push_back(j + 1);
		stl.push_back(j + 1);
		show(mine, stl);
	}

	for (int j = 0; j < 5; j++)
	{
		mine.pop_back();
		stl.pop_back();
		show(mine, stl);
	}

	std::cout << "---------INSERT 1 at 0, 1, end" << std::endl;
	mine.assign(10, 0);
	stl.assign(10, 0);
	show(mine, stl);

	mine_it1 = mine.insert(mine.begin(), 1);
	stl_it1 = stl.insert(stl.begin(), 1);
	std::cout << "mine_it1 = " << *mine_it1 << std::endl;
	std::cout << "stl_it1  = " << *stl_it1 << std::endl;
	show(mine, stl);

	mine_it1 = mine.insert(mine.begin() + 1, 2);
	stl_it1 = stl.insert(stl.begin() + 1, 2);
	std::cout << "mine_it1 = " << *mine_it1 << std::endl;
	std::cout << "stl_it1  = " << *stl_it1 << std::endl;
	show(mine, stl);

	mine.insert(mine.begin() + mine.size(), 1);
	stl.insert(stl.begin() + stl.size(), 1);
	show(mine, stl);

	std::cout << "---------INSERT 5 numbers at 0, 1, end" << std::endl;
	mine.assign(10, 0);
	stl.assign(10, 0);
	for (int j = 0; j < 10; j++)
	{
		mine[j] = j + 1;
		stl[j] = j + 1;
	}
	show(mine, stl);

	mine.insert(mine.begin(), 5, 0);
	stl.insert(stl.begin(), 5, 0);
	show(mine, stl);

	mine.insert(mine.begin() + 1, 5, 0);
	stl.insert(stl.begin() + 1, 5, 0);
	show(mine, stl);

	mine.insert(mine.begin() + mine.size(), 5, 0);
	stl.insert(stl.begin() + stl.size(), 5, 0);
	show(mine, stl);

	std::cout << "---------INSERT range of 5 numbers at 0, 1, end" << std::endl;
	mine.assign(10, 0);
	stl.assign(10, 0);
	mine2.assign(10, 0);
	stl2.assign(10, 0);
	for (int j = 0; j < 10; j++)
	{
		mine2[j] = j + 1;
		stl2[j] = j + 1;
	}
	show1(mine2, stl2);
	show(mine, stl);

	mine.insert(mine.begin(), mine2.begin(), mine2.end());
	stl.insert(stl.begin(), stl2.begin(), stl2.end());
	show(mine, stl);

	mine.insert(mine.begin() + 1, mine2.begin(), mine2.begin() + 5);
	stl.insert(stl.begin() + 1, stl2.begin(), stl2.begin() + 5);
	show(mine, stl);

	mine.insert(mine.begin() + mine.size(), mine2.begin(), mine2.begin() + 5);
	stl.insert(stl.begin() + stl.size(), stl2.begin(), stl2.begin() + 5);
	show(mine, stl);

	std::cout << "--------ERASE :" << std::endl;
	std::cout << "erase the insert changes" << std::endl;
	show(mine, stl);

	for (int n = 0; n < 5; n++)
	{
		mine_it1 = mine.erase(mine.begin());
		stl_it1 = stl.erase(stl.begin());
	}
	show(mine, stl);
	std::cout << "Return iterator = " << *mine_it1 << std::endl;
	std::cout << "Return iterator = " << *stl_it1 << std::endl;

	mine_it1 = mine.erase(mine.begin(), mine.begin() + 10);
	stl_it1 = stl.erase(stl.begin(), stl.begin() + 10);
	show(mine, stl);
	std::cout << "Return iterator = " << *mine_it1 << std::endl;
	std::cout << "Return iterator = " << *stl_it1 << std::endl;

	mine_it1 = mine.erase(mine.begin() + 10, mine.begin() + 15);
	stl_it1 = stl.erase(stl.begin() + 10, stl.begin() + 15);
	show(mine, stl);
	std::cout << "Return iterator = " << *(mine_it1 - 1) << std::endl;
	std::cout << "Return iterator = " << *(stl_it1 - 1) << std::endl;

	// std::cout << "erase empty" << std::endl;
	// std::cout << "size = " << empty.size() << std::endl;
	// stl_empty.erase(stl_empty.begin());
	// stl_empty.erase(stl_empty.end());
	// empty.erase(empty.begin());
	// empty.erase(empty.end());

	std::cout << "--------SWAP_EMPTY :" << std::endl;
	show(empty, stl_empty);
	show(mine, stl);

	mine.swap(empty);
	stl.swap(stl_empty);
	show(empty, stl_empty);
	show(mine, stl);

	std::cout << "--------SWAP_NOT_EMPTY :" << std::endl;
	show(mine, stl);
	show(mine2, stl2);
	std::cout << std::endl;

	mine.swap(mine2);
	stl.swap(stl2);
	show(mine, stl);
	show(mine2, stl2);

	std::cout << "--------CLEAR :" << std::endl;
	std::cout << "clear twice" << std::endl;
	show(mine, stl);

	mine.clear();
	stl.clear();
	show(mine, stl);

	mine.clear();
	stl.clear();
	show(mine, stl);

	std::cout << "\n==========RELATIONAL OPERATORS===========" << std::endl;
	mine.assign(10, 0);
	mine2.assign(10, 1);
	show2(mine, mine2);

	std::cout << "mine == mine2 --> ";
	if (mine == mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine != mine2 --> ";
	if (mine != mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine < mine2 --> ";
	if (mine < mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine > mine2 --> ";
	if (mine > mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine <= mine2 --> ";
	if (mine <= mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "mine >= mine2 --> ";
	if (mine >= mine2)
 		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << std::endl;

	std::cout << "==========TIMERS===" << std::endl;
	std::cout << "check out a few operation heavy functions for times" << std::endl;

	high_resolution_clock				clock;
	high_resolution_clock::time_point	t1;
	high_resolution_clock::time_point	t2;
	microseconds::rep					time_span1;
	microseconds::rep					time_span2;

	ft_vec	my_big(10000, 5);
	st_vec	stl_big(10000, 5);
	std::cout << "my_size: " << my_big.size() << std::endl;
	std::cout << "my_size: " << stl_big.capacity() << std::endl << std::endl;

	std::cout << "assign 10000 50s" << std::endl;
	t1 = clock.now();
	my_big.assign(10000, 50);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.assign(10000, 50);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "range_assign 5000" << std::endl;
	ft_vec clone1(5000, 0);
	st_vec clone2(5000, 0);

	t1 = clock.now();
	my_big.assign(clone1.begin(), clone1.end());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.assign(clone2.begin(), clone2.end());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "insert at 5000" << std::endl;
	t1 = clock.now();
	my_big.insert(my_big.begin() + 5000, 10);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.insert(stl_big.begin() + 5000, 10);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "insert 5000 at 5000" << std::endl;
	t1 = clock.now();
	my_big.insert(my_big.begin() + 5000, 5000, 10);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.insert(stl_big.begin() + 5000, 5000, 10);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time:" << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n" << std::endl;

	std::cout << "erase 1 at: 1, 5000, end" << std::endl;
	t1 = clock.now();
	my_big.erase(my_big.begin());
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin());
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 4998);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 4998);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 9995);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 9995);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	std::cout << "\nerase 10 ,100, 1000 at: 5000" << std::endl;
	t1 = clock.now();
	my_big.erase(my_big.begin() + 5000, my_big.begin() + 5010);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 5000, stl_big.begin() + 5010);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 5000, my_big.begin() + 5100);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 5000, stl_big.begin() + 5100);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	t1 = clock.now();
	my_big.erase(my_big.begin() + 5000, my_big.begin() + 6000);
	t2 = clock.now();
	time_span1 = duration_cast<microseconds>(t2 - t1).count();
	t1 = clock.now();
	stl_big.erase(stl_big.begin() + 5000, stl_big.begin() + 6000);
	t2 = clock.now();
	time_span2 = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "my_time: " << time_span1 << "ms\n";
	std::cout << "stl_time:" << time_span2 << "ms\n";

	std::cout << "\nconstant versions" << std::endl;
	ft_const_vec cVec(10, 10);
	st_const_vec cSvec(10, 10);
	ft::vector<int>::const_iterator cit1 = cVec.begin();
	//ft::vector<int>::const_iterator cit2 = cVec.end();
	std::vector<int>::const_iterator cit3 = cSvec.begin();
	//std::vector<int>::const_iterator cit4 = cSvec.end();

	std::cout << *cit1 << std::endl;
	//std::cout << *cit2 << std::endl;
	std::cout << *cit3 << std::endl;
	//std::cout << *cit4 << std::endl;

	cit1++;
	cit3++;

	std::cout << *cit1 << std::endl;
	std::cout << *cit3 << std::endl;

	std::cout << cVec.size() << std::endl;
	std::cout << cVec.max_size() << std::endl;
	//std::cout << cVec.resize(5) << std::endl;
	std::cout << cVec.capacity() << std::endl;
	std::cout << cVec.empty() << std::endl;
	//std::cout << cVec.reserve(42) << std::endl;

	std::cout << cSvec.size() << std::endl;
	std::cout << cSvec.max_size() << std::endl;
	//std::cout << cSvec.resize(5) << std::endl;
	std::cout << cSvec.capacity() << std::endl;
	std::cout << cSvec.empty() << std::endl;
	//std::cout << cSvec.reserve(42) << std::endl;

	std::cout << cVec[0] << std::endl;
	std::cout << cVec.at(5) << std::endl;
	std::cout << cVec.front() << std::endl;
	std::cout << cVec.back() << std::endl;

	std::cout << cSvec[0] << std::endl;
	std::cout << cSvec.at(5) << std::endl;
	std::cout << cSvec.front() << std::endl;
	std::cout << cSvec.back() << std::endl;

	//*cit1 = 5;
	//*cit3 = 5;

	//constVec.insert(constVec.begin(), 1);
	//constVec.insert(constVec.begin() + 1, 10, 1);
	//constVec.insert(constVec.begin() + 11, constVec.begin(), constVec.end());
	//ft_const_vec constVec2 = constVec;
	std::cout << "If it compiled then it's ok, decommenting any of the lines would make it not compile" << std::endl;

	return 0;
}
