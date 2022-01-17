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
		newNode->Lchild  = nullptr;
		newNode->Rchild  = nullptr;
		newNode->color	 = RED;
		return newNode;
	}

	void fix_insert(Node_ptr currentNode) {
		if (currentNode->parent->color == BLACK)
			return ;
	}

public:
	Node_ptr				_root;
	RBT(allocator_type alloc = allocator_type()) : _alloc(alloc), _size(0) {}

	void insert(value_type val) {
		if (!_size++) {
			_root = new_node(val, nullptr);
			_root->color = BLACK;
			return ;
		}
		else {
			Node_ptr currentNode = _root;
			Node_ptr toAlloc = nullptr;
			while (currentNode)
			{
				Node_ptr previousNode = currentNode;
				if (val.first == currentNode->data.first)
					throw std::out_of_range("Duplicate key");
				if  (_comp(val.first, currentNode->data.first))
				{
					if (!currentNode->Lchild)
					{
						currentNode->Lchild = new_node(val, previousNode);
						break ;
					}
					currentNode = currentNode->Lchild;
				}
				else
				{
					if (!currentNode->Rchild)
					{
						currentNode->Rchild = new_node(val, previousNode);
						break ;
					}
					currentNode = currentNode->Rchild;
				}
			}
			//fix_insert(currentNode);
		}
	}

	Node_ptr rotate_right(Node_ptr A, Node_ptr B) {
		Node_ptr tmp = A->parent;
		A->Lchild = B->Rchild;
		if (B->Rchild)
			B->Rchild->parent = A;
		B->Rchild = A;
		A->parent = B;
		B->parent = tmp;
		if (tmp)
		{
			if (tmp->Lchild == A)
				tmp->Lchild = B;
			else
				tmp->Rchild = B;
		}
		return B;
	}

	Node_ptr rotate_left(Node_ptr A, Node_ptr B) {
		Node_ptr tmp = A->parent;
		A->Rchild = B->Lchild;
		if (B->Lchild)
			B->Lchild->parent = A;
		B->Lchild = A;
		A->parent = B;
		B->parent = tmp;
		if (tmp)
		{
			if (tmp->Lchild == A)
				tmp->Lchild = B;
			else
				tmp->Rchild = B;
		}
		return B;
	}

	Node_ptr	root() const {return _root;}
	size_t		size() const {return _size;}
};

}//ft