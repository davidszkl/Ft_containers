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
	for (size_t n = 0; n < map.size() - 1; n++, node = map._rbt.successor(node))
		std::cout << "map[" << n << "][key " << node->data.first << "] = " << map[node->data.first] << std::endl;
	std::cout << std::endl;
}

template <typename U, typename V >
void show_map(std::map< U, V> & map) {
	for (size_t n = 0; n < map.size(); n++)
		std::cout << "map[" << n << "] = " << map[n] << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::pair<int, int> pair;
	ft::map<int, std::string>	My;
	ft::map<int, std::string>	copy(My);
	std::map<int, std::string>	Stl;
	typedef ft::map<int, std::string>::iterator iter;
	typedef ft::map<int, std::string>::reverse_iterator Riter;

	My.insert(ft::make_pair<int, std::string>(1, "a"));
	
	std::cout << "SIZE " << My.size() << std::endl;
	My.insert(ft::make_pair<int, std::string>(2, "b"));
		std::cout << "SIZE " << My.size() << std::endl;

	My.insert(ft::make_pair<int, std::string>(3, "c"));
		std::cout << "SIZE " << My.size() << std::endl;

	My.insert(ft::make_pair<int, std::string>(4, "d"));
	My.insert(ft::make_pair<int, std::string>(-1, "c"));
	My.insert(ft::make_pair<int, std::string>(5, "c"));

	My.insert(ft::make_pair<int, std::string>(6, "c"));

	std::cout << "SIZE " << My.size() << std::endl;

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
	std::cout << (*it1).first << std::endl;
	std::cout << (*it2).first << std::endl;
	std::cout << "begin:                            \033[1;32mok\033[0m\n";
	std::cout << "end:                              \033[1;32mok\033[0m\n";
	Rit1 = My.rbegin();
	Rit2 = My.rend();
	std::cout << (*Rit1).first << std::endl;
	std::cout << (*Rit2).first << std::endl;
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
	{
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
	}
	std::cout << "-------------hint_insert------------\n";
	My.insert(My.begin(), ft::make_pair<const int, std::string>(7, "f"));
	std::cout << "My[7] = " << My[7] << std::endl;
	My.insert(My.begin(), ft::make_pair<const int, std::string>(7, "z"));
	std::cout << "My[7] = " << My[7] << std::endl;
	My.insert(My.begin(), ft::make_pair<const int, std::string>(8, "g"));
	std::cout << "My[8] = " << My[8] << std::endl;
	std::cout << "hint insert :                     \033[1;32mok\033[0m\n";
	std::cout << "-------------range_insert------------\n";
	{
	copy = My;
	ft::map<int, std::string>	tmp;
	show_map(copy);
	show_map(tmp);
	tmp.insert(copy.begin(), copy.end());
	show_map(copy);
	show_map(tmp);
	}
	std::cout << "range insert :                    \033[1;32mok\033[0m\n";
	std::cout << "-----------iterator_delete----------\n";
	{
	show_map(My);
	My.erase(My.begin());
	show_map(My);
	std::cout << "single delete :                   \033[1;32mok\033[0m\n";
	std::cout << "-------------key_delete-------------\n";
	{
	size_t tmp;
	tmp = My.erase(1);
	std::cout << "tmp = " << tmp << std::endl;
	show_map(My);
	tmp = My.erase(1);
	std::cout << "tmp = " << tmp << std::endl;
	show_map(My);
	std::cout << "key delete :                      \033[1;32mok\033[0m\n";
	std::cout << "------------range_delete------------\n";
	My.erase(My.begin(), My.begin() + 3);
	show_map(My);
	std::cout << "range delete :                    \033[1;32mok\033[0m\n";
	}
	}
	std::cout << "---------------swap-----------------\n";
	{
		ft::map<int, std::string>	tmp;
		for (char n = 0; n < 5; n++)
			tmp.insert(ft::make_pair<const int, std::string>(n + 1, "tmp"));
		show_map(My);
		show_map(tmp);
		My.swap(tmp);
		show_map(My);
		show_map(tmp);
		std::cout << "swap :                            \033[1;32mok\033[0m\n";
		std::cout << "---------------swap-----------------\n";
	}

	return 0;
}