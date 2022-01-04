/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:49:07 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/29 09:49:11 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <memory>
#include "RandIter.hpp"
#include "ReverseRandIter.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:

		typedef T							value_type;
		typedef Alloc						allocator_type;
		typedef T&							reference;
		typedef const T&					const_reference;
		typedef T*							pointer;
		typedef const T*					const_pointer;
		typedef RandIter<T>					iterator;
		typedef RandIter<const T>			const_iterator;
		typedef ReverseRandIter<T>			reverse_iterator;
		typedef ReverseRandIter<const T>	const_reverse_iterator;
		typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;

		// clear();

		//relational operators



		//DONE:
		//erase
		//assign
		//begin
		//end
		//rbegin
		//rend
		//size();
		//max_size();
		//capacity();
		//get_allocator
		//operator[]
		//at
		//front
		//back
		//resize();
		//reserve();
		//insert();
		//swap();
	
	private:

		T				*_arr;
		allocator_type	_alloc;
		size_type		_size;
		size_type		_cap;	//capacity

		void	realloc(size_type n) {
			_alloc.deallocate(_arr);
			while (_cap < n)
				_cap *= 2;
			_arr = _alloc.allocate(_cap);
		}
	
	public:

	//-----------------------------------------<< Constructors >>-----------------------------------------------

		explicit vector(const allocator_type &alloc = allocator_type()): _size(0), _cap(256), _alloc(alloc) {
			_arr = _alloc.allocate(256, 0);
		}

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type()): _size(n), _alloc(alloc) {
			size_type	capacity = 1;
			iterator	tmp;

			while (capacity < n)
				capacity *= 2;
			_arr = _alloc.allocate(capacity, 0);
			for (tmp = begin(); tmp != end(); tmp++)
				_alloc.construct(tmp, val);
		}

	template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()):
			_size(1),
			_cap(1),
			_alloc(alloc)
		{
			InputIterator tmp = first;
			while (tmp != last)
			{
				++tmp;
				++_size;
			}
			while (_cap < _size)
				_cap *= 2;
			_arr = _alloc.allocate(_cap, 0);
			tmp = first;
			for (int n = 0; n < _size; n++)
				_alloc.construct(tmp++, *first++);
		}

		vector (const vector &x) {

		}

		~vector() {
			iterator	tmp = begin();
			iterator	end = end();
			for (; tmp != end; tmp++)
				_alloc.destroy(tmp);
			_alloc.deallocate(_arr);
		}

	//-----------------------------------------<< Iterators >>-------------------------------------------------

		iterator 			begin()	 {return iterator(_arr[0]);}
		iterator			end()	 {return iterator(_arr[_size]);}
		reverse_iterator	rbegin() {return iterator(_arr[_size - 1]);}
		reverse_iterator	rend()	 {return iterator(_arr[0]);}
		const_iterator 			begin()	 const {return const_iterator(_arr[0]);}
		const_iterator 			end()	 const {return const_iterator(_arr[_size]);}
		const_reverse_iterator	rbegin() const {return const_iterator(_arr[_size - 1]);}
		const_reverse_iterator	rend()	 const {return const_iterator(_arr[0]);}

	//-----------------------------------------<< Capacity >>--------------------------------------------------

		size_type	size()		const {return _size;}
		size_type	max_size()	const {return _alloc.max_size();}
		size_type	capacity()	const {return _cap;}
		bool		empty()		const {return !_size;}

		void	resize(size_type n, value_type val = value_type()) {
			reverse_iterator it = rend();
			iterator		 tmp = end();
			if (n < _size)
				while (_size-- > n)
					_alloc.destroy(it++);
			else
			{
				if (n > _cap)
					realloc(n);
				for (int j = 0; j < (n - _size); j++)
					_alloc.construct(tmp++, val);
				_size += n;
			}
		}

		void	reserve(size_type n) {
			if (n > _cap)
				realloc();
		}

	//--------------------------------------<< Element access >>-----------------------------------------------

		reference		operator[](size_type n) {return _arr[n];}
		reference		front() {return _arr[0];}
		reference		back() {return _arr[_size - 1];}
		reference		at(size_type n) {
			if (n >= _size)
				throw std::out_of_range("out of bounds");
			return _arr[n];
		}

		const_reference operator[](size_type n) const {return _arr[n];}
		const_reference	front() const {return _arr[0];}
		const_reference	back()  const {return _arr[_size - 1];}
		const_reference	at(size_type n) const {
			if (n >= _size)
				throw std::out_of_range("out of bounds");
			return _arr[n];
		}

	//-----------------------------------------<< Modifiers >>-------------------------------------------------

		iterator erase(iterator position) {
			iterator tmp = position;
			iterator Rend = rend();

			_alloc.destroy(position);
			for (; position != Rend; position++)
			{
				_alloc.construct(position, *(position + 1));
				_alloc.destroy(position + 1);
			}
			_size--;
			return tmp;
		}	

		iterator erase(iterator first, iterator last) {
			iterator tmp = first;
			iterator Rend = rend();

			for (; tmp != last && tmp != Rend; tmp++)
			{
				_alloc.destroy(tmp);
				_alloc.construct(tmp, *(tmp + 1));
				_alloc.destroy(tmp + 1);
				_size--;
			}
			return first;
		}
		
		void	push_back(const value_type& val) {
			iterator tmp = rend();

			if (_size++ == _cap)
				realloc();
			*tmp = val;
		}

		void	pop_back() {
			iterator tmp = end();
			_alloc.destroy(tmp);
			_size--;
		}

	template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			size_type n = first - last;
			iterator tmp = begin();
			iterator end = end();
			if (n > _cap)
				realloc(n);
			for (; tmp != end && first != last; tmp++)
			{
				_alloc.destroy(tmp);
				*tmp = _alloc.construct(tmp, *first++);
			}
			if (tmp == end)
			{
				for (; first != last; tmp++)
					*tmp = _alloc.construct(tmp, *first++);
			}
			else
			{
				for (; tmp != end; tmp++)
					_alloc.destroy(tmp);
			}
			_size = n;
		  }

		void assign (size_type n, const value_type& val) {
			iterator tmp = begin();
			iterator end = end();
			if (n > _cap)
				realloc(n);
			for (; tmp != end; tmp++)
			{
				_alloc.destroy(tmp);
				*tmp = _alloc.construct(tmp, value_type(val);
			}
			if (tmp == end)
			{
				for (int j = _size; j < n; j++)
				{
					*tmp = _alloc.construct(tmp, value_type(val));
					tmp++;
				}
			}
			else
			{
				for (; tmp != end; tmp++)
					_alloc.destroy(tmp);
			}
		}

		iterator insert(iterator position, const value_type& val) {
			reverse_iterator it = end();
			pointer swap;
			if (_size == _cap)
				realloc(_cap + 1);
			for (; it != position; it++)
			{
				swap = *it;
				*it = *(it + 1);
				*(it + 1) = swap;
			}
			*position = val;
			_size++;
		}

		void insert (iterator position, size_type n, const value_type& val) {
			reverse_iterator it = rend() + n;
			iterator		 rstart = position + n;
			pointer swap;
			if (_size + n >= _cap)
				realloc(_size + n + 1);
			for (; it != rstart; it++)
			{
				swap = *it;
				*it = *(it + n);
				*(it + n) = swap;
			}
			for (size_type j = 0; j < n; j++)
				*position++ = val;
			_size += n;
		}

	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			size_type			n = first - last;
			reverse_iterator	it = rend() + n;
			iterator			rstart = position + n;
			pointer swap;
			if (_size + n >= _cap)
				realloc(_size + n + 1);
			for (; it != rstart; it++)
			{
				swap = *it;
				*it = *(it + n);
				*(it + n) = swap;
			}
			for (size_type j = 0; j < n; j++)
				*position++ = *first++;
			_size += n;
		}

		//void	swap();
		//void	swap();

		allocator_type	get_allocator() const {return Alloc(_alloc);}
	};
}