#include "map.hpp"
#include <map>
#include <stdlib.h>
template <typename U, typename V >
void show_map(ft::map<U, V> & map ) {
	if (map.empty())
	{
		std::cout << "empty\n";
		return ;
	}
	typename ft::RBT<ft::map<int, std::string> >::Node_ptr node =  map._rbt.min(map._rbt.root());
	for (size_t n = 0; n < map.size(); n++, node = map._rbt.successor(node))
		std::cout << "map[" << n << "][key " << node->data.first << "] = " << map[node->data.first] << std::endl;
	std::cout << std::endl;
}

template <typename U, typename V >
void show_map(std::map< U, V> & map) {
	for (size_t n = 0; n < 9; n++)
		std::cout << "map[" << n << "] = " << map[n] << std::endl;
}

int main()
{
	std::pair<int, int> pair;
	ft::map<int, std::string>	My;
	ft::map<int, std::string>	copy(My);
	std::map<int, std::string>	Stl;
	typedef ft::map<int, std::string>::iterator iter;
	typedef ft::map<int, std::string>::reverse_iterator Riter;
	//typedef std::map<int, std::string>::reverse_iterator Stl_Riter;

	My.insert(ft::make_pair<int, std::string>(1, "a"));
	My.insert(ft::make_pair<int, std::string>(2, "b"));
	My.insert(ft::make_pair<int, std::string>(3, "c"));
	My.insert(ft::make_pair<int, std::string>(4, "d"));
	My.insert(ft::make_pair<int, std::string>(-1, "c"));
	My.insert(ft::make_pair<int, std::string>(5, "c"));
	My.insert(ft::make_pair<int, std::string>(6, "c"));

	show_map(My);
	show_map(copy);
	show_map(Stl);

	std::cout	<< "==========|MAP_ITERATOR|============\n";
	std::cout	<< "\n-----------CONSTRUCTORS-------------\n";
	iter it1;
	std::cout << "default:                          \033[1;32;mok\033[0m\n";
	iter it2(My._rbt.root(), &My._rbt);
	std::cout << "parameterized:                    \033[1;32;mok\033[0m\n";
	iter it3(it2);
	std::cout << "copy:                             \033[1;32;mok\033[0m\n";
	it1 = it3; 
	std::cout << "assignement:                      \033[1;32;mok\033[0m\n";
	Riter Rit1;
	Riter Rit2;

	std::cout << "-----------DEREFERENCING------------\n";
	std::cout << "it1 = " << (*it1).first << std::endl;
	std::cout << "it2 = " << it2->first << std::endl;
	std::cout << "it3 = " << (*it3).first << std::endl;
	if ((*it1).first != (*it2).first || (*it1).first != (*it3).first)
	{
		std::cout << "'*'  operator:                    \033[1;31mko\033[0m\n";
		std::cout << "'->' operator:                    \033[1;31mko\033[0m\n";
	}
	else
	{
		std::cout << "'*' operator:                     \033[1;32mok\033[0m\n";
		std::cout << "'->' operator:                    \033[1;32mok\033[0m\n";
	}
	*it3 = *it2;
	std::cout << "it3 = it2 = " << (*it3).first << std::endl;
	std::cout << "lvalue:                           \033[1;32mok\033[0m\n";

	std::cout << "-----------INCREMENTATION-----------\n";
	std::cout << "pre-increment:  " <<  (*(++it1)).first << std::endl;
	std::cout << "post-increment: " << (*(it2++)).first << std::endl;
	
	std::cout << "compare:                          ";
	if ((*it2).first != (*(it1)).first)
		std::cout << "s\033[1;31mko\033[0m\n";
	else
		std::cout << "\033[1;32mok\033[0m\n";
	std::cout << "pre-decrement:  " <<  (*(--it1)).first << std::endl;
	std::cout << "post-decrement: " << (*(it2--)).first << std::endl;
	std::cout << "compare:                          ";
	if ((*it2).first != (*(it1)).first)
		std::cout << "s\033[1;31mko\033[0m\n";
	else
		std::cout << "\033[1;32mok\033[0m\n";

	std::cout << "-------------BEGIN/END--------------\n";
	it1 = My.begin();
	it2 = My.end();
	
	show_map(My);

	std::cout << (*it1).first << std::endl;
	std::cout << (*it2).first << std::endl;
	std::cout << "begin:                            \033[1;32mok\033[0m\n";
	std::cout << "end:                              \033[1;32mok\033[0m\n";
	Rit1 = My.rbegin();
	Rit2 = My.rend();
	std::cout << (*Rit1).first << std::endl;
	//std::cout << (*Rit2).first << std::endl;
	std::cout << "rbegin:                           \033[1;32mok\033[0m\n";
	std::cout << "rend:                             \033[1;32mok\033[0m\n";

	std::cout << "============|CAPACITY|==============\n";

	std::cout << "size     = " << My.size() << "                      \033[1;32mok\033[0m\n";
	std::cout << "max_size = " << My.max_size() << "     \033[1;32mok\033[0m\n";
	std::cout << "empty    = ";
	if (My.empty()) std::cout << "true" << "                   \033[1;32mok\033[0m\n";
	else std::cout << "false" << "                  \033[1;32mok\033[0m\n";

	std::cout << "==========|ELEMENT_ACCESS|==========\n" << std::endl;
	std::cout << "-------------operator[]-------------\n";

	Stl.insert(std::make_pair<const int, std::string>(1, "a"));
	Stl.insert(std::make_pair<const int, std::string>(2, "b"));
	Stl.insert(std::make_pair<const int, std::string>(3, "c"));
	std::cout << "map[1] = " << My[1] << std::endl;
	std::cout << "map[2] = " << My[2] << std::endl;
	std::cout << "map[3] = " << My[3] << std::endl;
	My[4];
	std::cout << "map[4] (doesn't exist yet) = " << My[4] << std::endl;
	
	std::cout << "map[4] (exists now) = " << My[4] << std::endl;
	std::cout << "map[-1] = " << My[-1] << std::endl;
	std::cout << "stl[1] = " << Stl[1] << std::endl;
	std::cout << "stl[2] = " << Stl[2] << std::endl;
	std::cout << "stl[3] = " << Stl[3] << std::endl;
	std::cout << "stl[4] (doesn't exist yet) = " << Stl[4] << std::endl;
	std::cout << "stl[4] (exists now) = " << Stl[4] << std::endl;
	std::cout << "stl[-1] = " << Stl[-1] << std::endl;
	std::cout << "operator[]                        \033[1;32mok\033[0m\n";
	 
	std::cout << "============|MODIFIERS|=============\n\n";
	std::cout << "------------single_insert-----------\n";

	std::string string("coucou");
	ft::pair<iter, bool> a;
	a = My.insert(ft::make_pair<const int, std::string>(4, string));
	std::cout << a.second << " already exists" << std::endl;
	a = My.insert(ft::make_pair<const int, std::string>(5, "salut"));
	std::cout << a.second << " doesn't exist" <<std::endl;
	a = My.insert(ft::make_pair<const int, std::string>(6, "salut"));
	std::cout << a.second << " doesn't exist" <<std::endl;
	a = My.insert(ft::make_pair<const int, std::string>(1, "bonjour"));
	std::cout << a.second << " already exists" << std::endl;
	std::cout << "insert single:                    \033[1;32mok\033[0m\n";

	std::cout << "-------------hint_insert------------\n";

	My.insert(My.begin(), ft::make_pair<const int, std::string>(7, "f"));
	std::cout << "My[7] = " << My[7] << std::endl;
	My.insert(My.begin(), ft::make_pair<const int, std::string>(7, "z"));
	std::cout << "My[7] = " << My[7] << std::endl;
	My.insert(My.begin(), ft::make_pair<const int, std::string>(8, "g"));
	std::cout << "My[8] = " << My[8] << std::endl;
	std::cout << "hint insert :                     \033[1;32mok\033[0m\n";

	std::cout << "-------------range_insert------------\n";

		copy = My;
		ft::map<int, std::string>	tmp_map1;
		show_map(copy);
		show_map(tmp_map1);
		tmp_map1.insert(copy.begin(), copy.end());
		show_map(copy);
		show_map(tmp_map1);
		std::cout << "TMP BEFORE CLEAR " << std::endl;
		tmp_map1._rbt.show_tree(tmp_map1._rbt.root());
		std::cout << "COPY BEFORE CLEAR " << std::endl;
		copy._rbt.show_tree(copy._rbt.root());

	std::cout << "range insert :                    \033[1;32mok\033[0m\n";
	 
	std::cout << "-----------iterator_delete----------\n";
	 
	show_map(My);
	My.erase(My.begin());
	show_map(My);
	std::cout << "single delete :                   \033[1;32mok\033[0m\n";
	 
	std::cout << "-------------key_delete-------------\n";

	size_t tmp_size;
	tmp_size = My.erase(1);
	std::cout << "tmp = " << tmp_size << std::endl;
	show_map(My);
	tmp_size = My.erase(1);
	std::cout << "tmp = " << tmp_size << std::endl;
	show_map(My);
	std::cout << "key delete :                      \033[1;32mok\033[0m\n";

	std::cout << "------------range_delete------------\n";
	 
	My.erase(My.begin(), My.begin() + 3);
	show_map(My);
	std::cout << "range delete :                    \033[1;32mok\033[0m\n";

	std::cout << "---------------swap-----------------\n";

	ft::map<int, std::string>	tmp_map2;
	for (char n = 0; n < 5; n++)
		tmp_map2.insert(ft::make_pair<const int, std::string>(n + 1, "tmp"));
	show_map(My);
	show_map(tmp_map2);
	My.swap(tmp_map2);
	show_map(My);
	show_map(tmp_map2);
	std::cout << "swap :                            \033[1;32mok\033[0m\n";

	std::cout << "--------------clear-----------------\n";
	
	My = copy;
	show_map(My);
	My.clear();
	std::cout << "My: ";
	show_map(My);
	std::cout << "clear :                           \033[1;32mok\033[0m\n";

	std::cout << "=============|OBSERVERS|============\n";

	My = copy;
	ft::map<int, std::string>::key_compare compare_tmp = My.key_comp();
	std::cout << compare_tmp(My.begin()->first, (My.begin() + 1)->first) << std::endl;
	std::cout << compare_tmp((My.begin() + 1)->first, My.begin()->first) << std::endl;
	ft::map<int, std::string>::value_compare compare_tmp2 = My.value_comp();
	std::cout << compare_tmp2(*My.begin(), *(My.begin() + 1)) << std::endl;
	std::cout << compare_tmp2(*(My.begin() + 1) , *My.begin()) << std::endl;
	std::cout << "key_compare :                     \033[1;32mok\033[0m\n";
	std::cout << "value_compare :                   \033[1;32mok\033[0m\n";

	std::cout << "============|OPERATIONS|============\n";
	std::cout << "--------------Search----------------\n";

	show_map(My);
	show_map(Stl);
	std::cout << "Search key 3 " << std::endl;
	std::cout << "key = " << My.find(3)->first << std::endl;
	std::cout << "Search non-existent key " << std::endl;
	std::cout << "key = " << My.find(100)->first << std::endl;
	std::cout << "Search key 3 " << std::endl;
	std::cout << "key = " << Stl.find(3)->first << std::endl;
	std::cout << "Search non-existent key " << std::endl;
	std::cout << "key = " << Stl.find(100)->first << std::endl;
	std::cout << "search :                         \033[1;32mok\033[0m\n";
	std::cout << "--------------Count----------------\n";
	std::cout << "Count existent:     " << My.count(1) << std::endl;
	std::cout << "Count non-existent: " << My.count(18) << std::endl;
	std::cout << "count :                          \033[1;32mok\033[0m\n";

	std::cout << "-----------Lower_bound-------------\n";

	Stl.clear();
	Stl.insert(std::make_pair<const int, std::string>(0, "c"));
	Stl.insert(std::make_pair<const int, std::string>(1, "a"));
	Stl.insert(std::make_pair<const int, std::string>(2, "b"));
	Stl.insert(std::make_pair<const int, std::string>(3, "c"));
	Stl.insert(std::make_pair<const int, std::string>(4, "d"));
	Stl.insert(std::make_pair<const int, std::string>(5, "c"));
	Stl.insert(std::make_pair<const int, std::string>(6, "c"));
	Stl.insert(std::make_pair<const int, std::string>(7, "f"));
	Stl.insert(std::make_pair<const int, std::string>(8, "g"));
	//show_map(Stl);
	//show_map(My);
	std::cout << "Lower bounds:\nStl:\n";
	std::cout << "at min     : " << Stl.lower_bound(0)->first << std::endl;
	std::cout << "at min + 1 : " << Stl.lower_bound(1)->first << std::endl;
	std::cout << "at middle  : " << Stl.lower_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << Stl.lower_bound(7)->first << std::endl;
	std::cout << "at end     : " << Stl.lower_bound(8)->first << std::endl;
	std::cout << "overflow   : " << Stl.lower_bound(15)->first << std::endl;
	std::cout << "underflow  : " << Stl.lower_bound(-15)->first << std::endl;

	std::cout << "My:\n";
	std::cout << "at min     : " << My.lower_bound(-1)->first << std::endl;
	std::cout << "at nan     : " << My.lower_bound(0)->first << std::endl;
	std::cout << "at min + 1 : " << My.lower_bound(1)->first << std::endl;
	std::cout << "at middle  : " << My.lower_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << My.lower_bound(7)->first << std::endl;
	std::cout << "at end     : " << My.lower_bound(8)->first << std::endl;
	std::cout << "overflow   : " << My.lower_bound(15)->first << std::endl;
	std::cout << "underflow  : " << My.lower_bound(-15)->first << std::endl;
	std::cout << "lower_bounds :                   \033[1;32mok\033[0m\n";
	std::cout << "-----------Upper_bound-------------\n";

	std::cout << "Upper bounds:\nStl:\n";
	std::cout << "at min     : " << Stl.upper_bound(0)->first << std::endl;
	std::cout << "at min + 1 : " << Stl.upper_bound(1)->first << std::endl;
	std::cout << "at middle  : " << Stl.upper_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << Stl.upper_bound(7)->first << std::endl;
	std::cout << "at end     : " << Stl.upper_bound(8)->first << std::endl;
	std::cout << "overflow   : " << Stl.upper_bound(15)->first << std::endl;
	std::cout << "underflow  : " << Stl.upper_bound(-15)->first << std::endl;

	std::cout << "My:\n";
	std::cout << "at nan     : " << My.upper_bound(0)->first << std::endl;
	std::cout << "at min     : " << My.upper_bound(-1)->first << std::endl;
	std::cout << "at min + 1 : " << My.upper_bound(1)->first << std::endl;
	std::cout << "at middle  : " << My.upper_bound(5)->first << std::endl;
	std::cout << "at end - 1 : " << My.upper_bound(7)->first << std::endl;
	std::cout << "at end     : " << My.upper_bound(8)->first << std::endl;
	std::cout << "overflow   : " << My.upper_bound(15)->first << std::endl;
	std::cout << "underflow  : " << My.upper_bound(-15)->first << std::endl;
	std::cout << "Upper_bounds :                   \033[1;32mok\033[0m\n";

	std::cout << "-----------equal_range-------------\n";
	ft::pair<iter, iter>Range1(My.equal_range(3));
	ft::pair<iter, iter>Range2(My.equal_range(15));
	while (Range1.first != Range1.second)
	{
		std::cout << "key " << Range1.first->first << std::endl;
		Range1.first++;
	}
	while (Range2.first != Range2.second)
	{
		std::cout << "key " << Range1.first->first << std::endl;
		Range1.first++;
	}
	std::cout << "Range 2: empty" << std::endl;
	std::cout << "equal_range :                    \033[1;32mok\033[0m\n";
	std::cout << "-----------equal_range-------------\n";

	return 0;

}