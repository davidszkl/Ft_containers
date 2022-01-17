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
template <class T, class U>
void show_tree(typename ft::RBT<std::map <T, U> > tree, size_t size, size_t depth) {
	typename ft::RBT<std::map<T, U> >::Node_ptr ptr = tree.root();
	std::cout << "root = " << tree.root()->data.second << std::endl;
	size_t n = 1;
	while (n <= depth)
		ptr = ptr->Lchild;
}

void show_Node(ft::RBT<std::map <char, int> >::Node_ptr node) {
	std::cout << "key  = " << node->data.first << std::endl;
	std::cout << "data = " << node->data.second << std::endl;
	std::cout << "color = ";
	if (node->color == ft::BLACK)
		std::cout << "Black" << std::endl;
	else
		std::cout << "Red" << std::endl;
}

int main()
{
	typedef ft::RBT<std::map<char, int> > RBT_char_int;

	RBT_char_int tree;
	tree.insert(std::make_pair('g', 10));
	//tree.insert(std::make_pair('g', 20));
	tree.insert(std::make_pair('z', 15));
	tree.insert(std::make_pair('m', 35));
	tree.insert(std::make_pair('b', 35));
	tree.insert(std::make_pair('c', 4));
	std::cout << tree.root()->data.second << std::endl;
	std::cout << tree.root()->Rchild->data.first << std::endl;
	std::cout << tree.root()->Rchild->Lchild->data.first << std::endl;
	std::cout << tree.root()->Lchild->data.first << std::endl;
	std::cout << tree.root()->Lchild->Rchild->data.first << std::endl;
	tree._root = tree.rotate_right(tree.root(), tree.root()->Lchild);
	std::cout << tree.root()->data.second << std::endl;
	std::cout << tree.root()->Rchild->data.first << std::endl;
	std::cout << tree.root()->Rchild->Lchild->data.first << std::endl;
	std::cout << tree.root()->Rchild->Rchild->data.first << std::endl;
	std::cout << tree.root()->Rchild->Rchild->Lchild->data.first << std::endl;
	tree._root = tree.rotate_left(tree.root(), tree.root()->Rchild);
	std::cout << tree.root()->data.second << std::endl;
	std::cout << tree.root()->Rchild->data.first << std::endl;
	std::cout << tree.root()->Rchild->Lchild->data.first << std::endl;
	std::cout << tree.root()->Lchild->data.first << std::endl;
	std::cout << tree.root()->Lchild->Rchild->data.first << std::endl;
	//show_tree(tree, tree.size());

	return 0;
}