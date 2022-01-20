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
	for (int n = 0; n < 35; n++)
		tree.insert(std::make_pair(n + 1, 'a'));
	tree.show_tree(tree.root());
	// tree.in_order(tree.root());
	// std::2 << std::endl;
	// tree.pre_order(tree.root());
	// std::cout << std::endl;
	// tree.post_order(tree.root());
	// std::cout << std::endl;
	// tree.level_order_traversal(tree.root());
	// std::cout << std::endl;
	// std::cout << tree.search(tree.root(), 6)->data.first << std::endl;
	// std::cout << std::endl;
	// std::cout << tree.predecessor(tree.root()->Rchild->Rchild)->data.first << std::endl;
	// std::cout << tree.one_child(tree.root()) << std::endl;
	// std::cout << tree.one_child(tree.root()->Rchild->Rchild) << std::endl;
	//tree.show_tree(tree.root());
	std::cout << std::endl;
	for (int n = 30; n > 13; n--)
	{
		tree.show_Node(tree.root());
		tree.delete_node(tree.root()->data.first);
	}
	std::cout << std::endl;
	tree.show_tree(tree.root());
	return 0;
}