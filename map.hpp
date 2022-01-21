#pragma once
#include <functional>	// std::less
#include "pair.hpp"
#include "RandIter.hpp"
#include "ReverseRandIter.hpp"
#include "RBTree.hpp"

namespace ft
{ //ft

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map
{

typedef Key									key_type;
typedef T									mapped_type;
typedef pair<const key_type, mapped_type>	value_type;
typedef Compare								key_compare;
typedef Alloc								allocator_type;
typedef value_type&							reference;
typedef const value_type&					const_reference;
typedef value_type*							pointer;
typedef const value_type*					const_pointer;
typedef RandIter<value_type>				iterator;
typedef RandIter<const value_type>			const_iterator;
typedef ReverseRandIter<value_type>			reverse_iterator;
typedef ReverseRandIter<const value_type>	const_reverse_iterator;
typedef ptrdiff_t							difference_type;
typedef size_t								size_type;

class value_compare : public std::binary_function<value_type, value_type, bool>
{
	public:
		bool operator()(const value_type& left, const value_type& right) const
			return (comp(left.first, right.first));
		value_compare(key_compare pred) : comp(pred) {}
	protected:
		key_compare comp;
};

template < class value_type = pair<const key_type, mapped_type > >
class map_iter
{
public:	

	typedef key_type					key;
	typedef mapped_type					data;
	typedef typename ft::RBT::Node_ptr	NodePtr;

private:
	NodePtr	_ptr;

public:
	map_iter(): _ptr(nullptr) {}
	map_iter(const map_iter& cpy): _ptr(cpy._ptr) {}
	~map_iter()
	map_iter& operator=(const map_iter& rhs) {_ptr = cpy._ptr;}

	bool operator==(const map_iter& lhs, const map_iter& rhs) const {return lhs._ptr == cpy._ptr;}
	bool operator!=(const map_iter& lhs, const map_iter& rhs) const {return lhs._ptr != cpy._ptr;}
	data operator*(const map_iter& lhs) const {return lhs._ptr->data.second;}
	map_iter& operator++() {_ptr = _ptr.successor(); return *this;}
	map_iter& operator++(int dummy) {
		(void)dummy;
		map_iter tmp = map_iter(this);
		operator++();
		return tmp;
	}

};

private:

	RBT									_rbt;
	Compare								_comp;
	allocator_type						_alloc;
	size_type							_size;

public:

//-----------------------------------------<< Constructors >>-----------------------------------------------

	explicit map (const key_compare& _comp = key_compare(),
				const allocator_type& _alloc = allocator_type()): _size(0) {}

	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());

	map (const map& x);
	~map();

//-----------------------------------------<< Iterators >>--------------------------------------------------

	iterator				begin()	 {}
	iterator				end()	 {}
	reverse_iterator		rbegin() {}
	reverse_iterator		rend()	 {}
	const_iterator			begin()	 const {}
	const_iterator			end()	 const {}
	reverse_const_iterator	rbegin() const {}
	reverse_const_iterator	rend()	 const {}
};

} //ft