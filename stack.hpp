#pragma once
#include "vector.hpp"
namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
public:

    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;

    explicit stack(const container_type& ctnr = container_type()): _arr(cntr) {}

    stack &operator=(const stack &other) {
        if (this != &other)
            c = other.c;
        return (*this);
    }

private:

    container_type  _arr;

public:

    bool        empty(  const {return _arr.empty();}
    size_type   size()  const {return _arr.size();}
    value_type&         top() {return _arr.back();}
    const value_type&   top() const {return _arr.back();}
    void push (const value_type& val) {_arr.push_back(val);}
    void pop() {_arr.pop_back();}

};

template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs == rhs;
  }

template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs != rhs;
  }

template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs < rhs;
  }

template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs <= rhs;
  }

template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs > rhs;
  }

template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
      return lhs >= rhs;
  }
}