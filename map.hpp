#pragma once
#include <functional>	// std::less
#include "pair.hpp"
#include "RBTree.hpp"
#include "utils.hpp"

namespace ft
{ //ft

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map
{
public:

	typedef Key									key_type;
	typedef T									mapped_type;
	typedef pair<const key_type, mapped_type>	value_type;
	typedef Compare								key_compare;
	typedef Alloc								allocator_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef value_type*							pointer;
	typedef const value_type*					const_pointer;
	typedef ptrdiff_t							difference_type;
	typedef size_t								size_type;

	typedef RBT<ft::map<Key, T, Compare>, allocator_type>	RBTree;
	typedef typename RBTree::Node_ptr						Node_ptr;

	RBTree										_rbt; //TO ERASE
private:

	// RBTree									_rbt;
	Compare										_comp;
	std::allocator<pair<const key_type, T> >	_alloc;

public:

	class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			public:
				bool operator()(const value_type& left, const value_type& right) const {
					return (comp(left.first, right.first));
				}
				value_compare(key_compare pred) : comp(pred) {}
			protected:
				key_compare comp;
		};

//ITERATORS DEFINITIONS=====================================================================================

	class map_iter : public ft::iterator<ft::random_access_iterator_tag, T, difference_type, pointer, reference>
		{
			Node_ptr	NodePtr;
			RBTree*		Tree;
	public:
			map_iter(): NodePtr(nullptr), Tree(nullptr) {}
			map_iter(const map_iter& cpy) {*this = cpy;}
			map_iter(Node_ptr ptr, RBTree* rbt): NodePtr(ptr), Tree(rbt) {}
			map_iter& operator=(const map_iter& rhs) {
				NodePtr = rhs.NodePtr;
				Tree	= rhs.Tree;
				return *this;
			}
			~map_iter(){}
			
		reference	operator*() const {return (*NodePtr).data;}
		pointer		operator->() const {return &(operator*());}

		bool		operator== (map_iter& rhs) {return NodePtr == rhs.NodePtr;}
		bool		operator!= (map_iter& rhs) {return NodePtr != rhs.NodePtr;}
		map_iter&	operator++ () {
				NodePtr = Tree->successor(NodePtr);
				return *this;
			}
		map_iter	operator++ (int dummy) {
				(void)dummy;
				map_iter tmp(*this);
				NodePtr = Tree->successor(NodePtr);
				return tmp;
			}
		map_iter&	operator-- () {
				NodePtr = Tree->predecessor(NodePtr);
				return *this;
			}
		map_iter	operator-- (int dummy) {
				(void)dummy;
				map_iter tmp(*this);
				NodePtr = Tree->predecessor(NodePtr);
				return tmp;
			}
		map_iter&	operator+ (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator++();
			return *this;
			}
		map_iter&	operator- (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator--();
			return *this;
			}
		};

		class const_map_iter : public ft::iterator<ft::random_access_iterator_tag, T, difference_type, pointer, reference>
		{	
			Node_ptr	NodePtr;
			RBTree*		Tree;
	public:
			const_map_iter(): NodePtr(nullptr), Tree(nullptr) {}
			const_map_iter(const map_iter& cpy) {*this = cpy;}
			const_map_iter(const const_map_iter& cpy) {*this = cpy;}
			const_map_iter(const Node_ptr ptr, RBTree* rbt): NodePtr(ptr), Tree(rbt) {}
			const_map_iter(const Node_ptr ptr, const RBTree* rbt): NodePtr(ptr), Tree(rbt) {}
			const_map_iter& operator=(const map_iter& rhs) {
				NodePtr = rhs.NodePtr;
				Tree	= rhs.Tree;
				return *this;
			}
			~const_map_iter(){}
			
		reference	operator*()  const {return (*NodePtr).data;}
		pointer		operator->() const {return &(operator*());}

		bool		operator== (const_map_iter& rhs) const {return NodePtr == rhs.NodePtr;}
		bool		operator!= (const_map_iter& rhs) const {return NodePtr != rhs.NodePtr;}
		const_map_iter&	operator++ () {
				NodePtr = Tree->successor(NodePtr);
				return *this;
			}
		const_map_iter	operator++ (int dummy) {
				(void)dummy;
				const_map_iter tmp(*this);
				NodePtr = Tree->successor(NodePtr);
				return tmp;
			}
		const_map_iter&	operator-- () {
				NodePtr = Tree->predecessor(NodePtr);
				return *this;
			}
		const_map_iter	operator-- (int dummy) {
				(void)dummy;
				const_map_iter tmp(*this);
				NodePtr = Tree->predecessor(NodePtr);
				return tmp;
			}
		const_map_iter&	operator+ (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator++();
			return *this;
			}
		const_map_iter&	operator- (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator--();
			return *this;
			}
		};

		class reverse_map_iter : public ft::iterator<ft::random_access_iterator_tag, T, difference_type, pointer, reference>
		{
			Node_ptr	NodePtr;
			RBTree*		Tree;

	public:
			reverse_map_iter(): NodePtr(nullptr), Tree(nullptr) {}
			reverse_map_iter(const reverse_map_iter& cpy) {*this = cpy;}
			reverse_map_iter(Node_ptr ptr, RBTree* rbt): NodePtr(ptr), Tree(rbt) {}
			reverse_map_iter& operator=(const reverse_map_iter& rhs) {
				NodePtr = rhs.NodePtr;
				Tree	= rhs.Tree;
				return *this;
			}
			~reverse_map_iter(){}
			
		reference	operator*() const {return (*NodePtr).data;}
		pointer		operator->() const {return &(operator*());}

		bool		operator== (reverse_map_iter& rhs) {return NodePtr == rhs.NodePtr;}
		bool		operator!= (reverse_map_iter& rhs) {return NodePtr != rhs.NodePtr;}
		reverse_map_iter&	operator++ () {
				NodePtr = Tree->predecessor(NodePtr);
				return *this;
			}
		reverse_map_iter	operator++ (int dummy) {
				(void)dummy;
				reverse_map_iter tmp(*this);
				NodePtr = Tree->predecessor(NodePtr);
				return tmp;
			}
		reverse_map_iter&	operator-- () {
				NodePtr = Tree->successor(NodePtr);
				return *this;
			}
		reverse_map_iter	operator-- (int dummy) {
				(void)dummy;
				reverse_map_iter tmp(*this);
				NodePtr = Tree->successor(NodePtr);
				return tmp;
			}
		reverse_map_iter&	operator+ (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator--();
			return *this;
			}
		reverse_map_iter&	operator- (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator++();
			return *this;
			}
		};

		class const_reverse_map_iter : public ft::iterator<ft::random_access_iterator_tag, T, difference_type, pointer, reference>
		{
			Node_ptr	NodePtr;
			RBTree*		Tree;

	public:
			const_reverse_map_iter(): NodePtr(nullptr), Tree(nullptr) {}
			const_reverse_map_iter(const reverse_map_iter& cpy) {*this = cpy;}
			const_reverse_map_iter(const const_reverse_map_iter& cpy) {*this = cpy;}
			const_reverse_map_iter(const Node_ptr ptr, RBTree* rbt): NodePtr(ptr), Tree(rbt) {}
			const_reverse_map_iter(const Node_ptr ptr, const RBTree* rbt): NodePtr(ptr), Tree(rbt) {}
			const_reverse_map_iter& operator=(const reverse_map_iter& rhs) {
				NodePtr = rhs.NodePtr;
				Tree	= rhs.Tree;
				return *this;
			}
			~const_reverse_map_iter(){}
			
		reference	operator*()  const {return (*NodePtr).data;}
		pointer		operator->() const {return &(operator*());}

		bool		operator== (const_reverse_map_iter& rhs) const {return NodePtr == rhs.NodePtr;}
		bool		operator!= (const_reverse_map_iter& rhs) const {return NodePtr != rhs.NodePtr;}
		const_reverse_map_iter&	operator++ () {
				NodePtr = Tree->predecessor(NodePtr);
				return *this;
			}
		const_reverse_map_iter	operator++ (int dummy) {
				(void)dummy;
				const_reverse_map_iter tmp(*this);
				NodePtr = Tree->predecessor(NodePtr);
				return tmp;
			}
		const_reverse_map_iter&	operator-- () {
				NodePtr = Tree->sucessor(NodePtr);
				return *this;
			}
		const_reverse_map_iter	operator-- (int dummy) {
				(void)dummy;
				const_reverse_map_iter tmp(*this);
				NodePtr = Tree->sucessor(NodePtr);
				return tmp;
			}
		const_reverse_map_iter&	operator+ (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator--();
			return *this;
			}
		const_reverse_map_iter&	operator- (size_type offset) {
			for (size_type n = 0; n < offset; n++)
				operator++();
			return *this;
			}
		};

	typedef map_iter				iterator;	
	typedef const_map_iter			const_iterator;
	typedef reverse_map_iter		reverse_iterator;	
	typedef const_reverse_map_iter	const_reverse_iterator;

//-----------------------------------------<< Constructors >>-----------------------------------------------

	explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _rbt(alloc), _comp(comp), _alloc(alloc) {
	}

	// template <class InputIterator>
	// map (InputIterator first, InputIterator last,
	// 	const key_compare& comp = key_compare(),
	// 	const allocator_type& alloc = allocator_type()):

	map (const map& x) {*this = x;}
	~map(){_rbt.clear(_rbt.root());}

	map&	operator= (const map& rhs) {
		_rbt	= rhs._rbt;
		_comp	= rhs._comp;
		_alloc	= rhs._alloc;
		return *this;
	}

//-----------------------------------------<< Iterators >>--------------------------------------------------

	iterator					begin()	 {return iterator(_rbt.min(_rbt.root()) , &_rbt);}
	iterator					end()	 {return iterator(_rbt.max(_rbt.root()) , &_rbt);}
	reverse_iterator			rbegin() {return reverse_iterator(_rbt.max(_rbt.root()) , &_rbt);}
	reverse_iterator			rend()	 {return reverse_iterator(_rbt.min(_rbt.root()) , &_rbt);}
	const_iterator				begin()	 const {return const_iterator(_rbt.min(_rbt.root()) , &_rbt);}
	const_iterator				end()	 const {return const_iterator(_rbt.max(_rbt.root()) , &_rbt);}
	const_reverse_iterator		rbegin() const {return const_reverse_iterator(_rbt.max(_rbt.root()) , &_rbt);}
	const_reverse_iterator		rend()	 const {return const_reverse_iterator(_rbt.min(_rbt.root()) , &_rbt);}

//-----------------------------------------<< Capacity >>---------------------------------------------------

	bool						empty()		const {return _rbt.size() == 0;}
	size_type					size()		const {return _rbt.size();}
	size_type					max_size()	const {return _alloc.max_size();}

//--------------------------------------<< Element Access >>------------------------------------------------	

	mapped_type& 				operator[] (const key_type& k) {
		return insert(ft::make_pair(k, T())).first->second;
	}

//-----------------------------------------<< Modifiers >>--------------------------------------------------	

pair<iterator, bool> insert (const value_type& val) {
	size_type	size_before(_rbt.size());
	Node_ptr	tmp = _rbt.insert(val);
	if (_rbt.size() != size_before)
		return ft::make_pair<iterator, bool>(iterator(tmp, &_rbt), true);
	return ft::make_pair<iterator, bool>(iterator(tmp, &_rbt), false);
}

iterator insert (iterator position, const value_type& val) {
	(void)position;
	return iterator(_rbt.insert(val), &_rbt);
}

template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		while (first != last)
			_rbt.insert(*first++);
		_rbt.insert(*first);
	}

	void erase (iterator position) {
		_rbt.delete_node((*position).first);
	}

	size_type erase (const key_type& k) {
		size_type sizeBefore = _rbt.size();
		_rbt.delete_node(k);
		return sizeBefore != _rbt.size() ? 1 : 0;
	}

	void erase (iterator ItFirst, iterator last) {
		while (ItFirst != last)
			_rbt.delete_node((*ItFirst++).first);
		_rbt.delete_node((*ItFirst).first);	
	}

	void swap (map& x)	{_rbt.swap(x._rbt);}
	void clear()		{_rbt.clear(_rbt.root());}

};

} //ft