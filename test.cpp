#include "map.hpp"
#include <map>
#include <stdlib.h>
template <typename U, typename V >
void show_map(ft::map<U, V>& map) {
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
void show_map(std::map< U, V>& map) {
	for (size_t n = 0; n < map.size(); n++)
		std::cout << "map[" << n << "] = " << map[n] << std::endl;
	std::cout << std::endl;
}

int main ()
{
	ft::map<int, std::string>	My;
	ft::map<int, std::string>	copy(My);
	std::map<int, std::string>	Stl;
	My.insert(ft::make_pair<int, std::string>(1, "a"));
	My.insert(ft::make_pair<int, std::string>(2, "b"));
	My.insert(ft::make_pair<int, std::string>(3, "c"));
	My.insert(ft::make_pair<int, std::string>(4, "c"));
	My.insert(ft::make_pair<int, std::string>(5, "c"));
    My.erase(My.begin());
    show_map(My);

    return 0;
}