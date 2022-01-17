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

private:

	RBT									rbt;
	Compare								_comp;
	allocator_type						_alloc;
};

} //ft