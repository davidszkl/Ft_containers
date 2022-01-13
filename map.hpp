#pragma once
#include <functional>	// std::less
#include "pair.hpp"

namespace ft
{ //ft

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map
{

};

} //ft