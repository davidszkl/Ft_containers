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
	typedef ft::RBT<std::map<char, int> > RBT_char_int;

	RBT_char_int tree;
	tree.insert(std::make_pair('c', 1));
	//tree.insert(std::make_pair('g', 20));
	tree.insert(std::make_pair('a', 2));
	tree.insert(std::make_pair('b', 3));
	//std::cout << "HERE" << tree.root()->Lchild->Rchild->data.first;
	tree.insert(std::make_pair('d', 4));
	tree.insert(std::make_pair('e', 5));
	tree.show_tree(tree.root());
	//tree.show_tree(tree.root());
	std::cout << std::endl;
	//tree.rotate_right(tree.root());
//tree.show_tree(tree.root());
	std::cout << std::endl;
	//tree.rotate_left(tree.root());
	//tree.show_tree(tree.root());
	std::cout << std::endl;

	return 0;
}