#include "RBTree.hpp"
#include <map>
#include <iostream>


int	power(int base, int power){
	int nbr = base;
	while (--power >= 0)
		nbr *= base;
	return nbr;
}

size_t getDepth(size_t size) {
	size_t depth = 0;
	while (size > (depth * 2) + 1)
		depth++;
	return depth;
}


int main()
{
	typedef ft::RBT<std::map<int, char> > RBT_char_int;

	RBT_char_int tree;
	tree.insert(std::make_pair(1, 'a'));
	tree.insert(std::make_pair(2, 'b'));
	tree.insert(std::make_pair(3, 'c'));
	tree.insert(std::make_pair(4, 'd'));
	tree.insert(std::make_pair(5, 'e'));
	// tree.insert(std::make_pair('f', 1));
	// tree.insert(std::make_pair('h', 2));
	// tree.insert(std::make_pair('g', 3));
	// tree.insert(std::make_pair('i', 4));
	// tree.insert(std::make_pair('k', 5));
	// tree.insert(std::make_pair('j', 5));
	//tree.show_tree(tree.root());
	tree.in_order(tree.root());
	std::cout << std::endl;
	tree.pre_order(tree.root());
	std::cout << std::endl;
	tree.post_order(tree.root());
	std::cout << std::endl;
	tree.level_order_traversal(tree.root());
	std::cout << std::endl;
	std::cout << tree.search(tree.root(), std::make_pair(6, 'c'))->data.first << std::endl;
	std::cout << std::endl;
	std::cout << tree.predecessor(tree.root()->Rchild->Rchild)->data.first << std::endl;

	return 0;
}