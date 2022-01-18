#pragma once
#include <algorithm>
#include <memory>
#include <iostream>

namespace ft
{

enum COLOR {BLACK, RED};

template<typename value_type>
struct Node {
	value_type	data;
	Node*		parent;
	Node*		Lchild;
	Node*		Rchild;
	COLOR		color;

	Node() : parent(nullptr), Lchild(nullptr), Rchild(nullptr), color(BLACK) {}
	Node (value_type v) : data(v), parent(nullptr), Lchild(nullptr), Rchild(nullptr), color(BLACK){}
	~Node() {}
};

template<class Container, class Allocator = std::allocator<Node<typename Container::value_type> > >
class RBT
{
public:

	typedef typename Container::value_type									value_type;
	typedef typename Container::key_type									key_type;
	typedef typename Container::mapped_type									mapped_type;
	typedef typename Allocator::template rebind<Node<value_type> >::other	allocator_type;
	typedef Node<value_type>												Node;
	typedef Node*															Node_ptr;
	typedef typename Container::key_compare									key_compare;
	typedef typename Container::size_type									size_type;

private:


	size_type 				_size;
	key_compare				_comp;
	allocator_type			_alloc;

	Node_ptr	new_node(value_type val, Node_ptr parent) {
		Node_ptr newNode = _alloc.allocate(1);
		_alloc.construct(newNode, val);
		newNode->parent	 = parent;
		newNode->Lchild  = _leaf;
		newNode->Rchild  = _leaf;
		newNode->color	 = RED;
		return newNode;
	}

public:
	Node_ptr				_root;
	Node_ptr				_leaf;
	RBT(allocator_type alloc = allocator_type()) : _alloc(alloc), _size(0) {
		_leaf			= new_node(value_type(), nullptr);
		_leaf->color 	= BLACK;
	}

	void insert(value_type val) {
	if (!_size++) {
		_root = new_node(val, nullptr);
		_root->color = BLACK;
		return ;
	}
	else {
		Node_ptr currentNode	= _root;
		Node_ptr previousNode	= _root;
		while (currentNode != _leaf)
		{
			previousNode = currentNode;
			if (val.first == currentNode->data.first)
					return ;
			if  (_comp(val.first, currentNode->data.first))
				currentNode = currentNode->Lchild;
			else
				currentNode = currentNode->Rchild;
		}
		if (_comp(val.first, previousNode->data.first))
			previousNode->Lchild = new_node(val, previousNode);
		else
			previousNode->Rchild = new_node(val, previousNode);
		if (!previousNode->parent)
			return;
		//fix_insert(currentNode);
	}
}

	void	rotate_right(Node_ptr x) {
		Node_ptr y = x->Lchild;
		x->Lchild = y->Rchild;
		if (y->Rchild)
			y->Rchild->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->Rchild)
			x->parent->Rchild = y;
		else
			x->parent->Lchild = y;
		y->Rchild = x;
		x->parent = y;
	}

	void	rotate_left(Node_ptr x) {
		Node_ptr y = x->Rchild;
		x->Rchild = y->Lchild;
		if (y->Lchild)
			y->Lchild->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->Lchild)
			x->parent->Lchild = y;
		else
			x->parent->Rchild = y;
		y->Lchild = x;
		x->parent = y;
	}

	void fix_insert(Node_ptr currentNode) {
		if (currentNode->parent->color == BLACK)
			return ;
		while (currentNode->parent->color == RED)
		{
			//std::cout << "FIX" << std::endl;
			//show_Node(currentNode);
			if (currentNode->parent == currentNode->parent->parent->Rchild)
			{
				Node_ptr uncle = currentNode->parent->parent->Lchild;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					currentNode->parent->color = BLACK;
					currentNode->parent->parent->color = RED;
					currentNode = currentNode->parent->parent;
				}
				else
				{
					if (currentNode == currentNode->parent->Lchild)
					{
						currentNode = currentNode->parent;
						rotate_right(currentNode);
					}
					else
					{
						currentNode->parent->color = BLACK;
						currentNode->parent->parent->color = RED;
						rotate_left(currentNode->parent->parent);
					}
				}
			}
			else
			{
				std::cout << "ici\n";
				Node_ptr uncle = currentNode->parent->parent->Rchild;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					currentNode->parent->color = BLACK;
					currentNode->parent->parent->color = RED;
					currentNode = currentNode->parent->parent;
				}
				else
				{
					if (currentNode == currentNode->parent->Rchild)
					{
						currentNode = currentNode->parent;
						rotate_left(currentNode);
					}
					else
					{
						currentNode->parent->color = BLACK;
						currentNode->parent->parent->color = RED;
						rotate_right(currentNode->parent->parent);
					}
				}
			}
			if (currentNode == _root)
				break ;
		}
		_root->color = BLACK;
	}

	Node_ptr	root() const {return _root;}
	size_t		size() const {return _size;}

	void show_tree(Node_ptr node) {
		if (node != _leaf)
		{
			show_Node(node);
			show_tree(node->Lchild);
			show_tree(node->Rchild);
		}
	}

	void show_Node(Node_ptr node) {
		if (node->parent && node == node->parent->Lchild)
			std::cout << "LCHILD ";
		else if (node->parent && node == node->parent->Rchild)
			std::cout << "RCHILD ";
		else
			std::cout << "ROOT ";
		std::cout << "[" << node->data.first << "][" << node->data.second << "][";
		if (node->color == BLACK)
			std::cout << "BLACK]" << std::endl;
		else
			std::cout << "RED]" << std::endl;
	}
};

}//ft