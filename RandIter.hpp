/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:14:28 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/29 10:14:33 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RANDITER_HPP
# define RANDITER_HPP
#include <iostream>

template <typename T>
class RandIter
{
public:

	typedef T 				value_type;
    typedef std::ptrdiff_t	difference_type;
    typedef T*				pointer;
    typedef T&				ref;

// CONSTRUCTORS, DESTRUCTORS ===================================================

	RandIter(){
		ptr = nullptr;
	}

	RandIter(T *ptr1){
		ptr = ptr1;
	}

	RandIter(const RandIter &src){
		*this = src;
	}

	virtual ~RandIter(){}

	RandIter<T> &operator=(const RandIter&rhs)
	{
		this->ptr = rhs.ptr;
		return *this;
	}

//OPERATOR OVERLOADS ==========================================================

	ref 		operator*(void)		const	{return *ptr;}
    pointer 	operator->(void)	const	{return ptr;}

    RandIter<T> &operator++(){
		ptr++;
		return *this;
	}

    RandIter<T> &operator--(){
		ptr--;
		return *this;
	}

    RandIter<T> operator++(int dummy){
		(void)dummy;
		RandIter<T> tmp = *this;
		operator++();
		return tmp;
	}

    RandIter<T>	operator--(int dummy){
		(void)dummy;
		RandIter<T> tmp = *this;
		operator--();
		return tmp;
	}

    RandIter<T>	&operator+=(const difference_type &offset){
		ptr += offset;
		return *this;
	}

    RandIter<T> &operator-=(const difference_type &offset){
		ptr -= offset;
		return *this;
	}

    RandIter<T>	operator+(difference_type offset) 	const{
		RandIter<T> tmp(*this);
		tmp.ptr += offset;
		return tmp;
	}

    RandIter<T> operator-(difference_type offset)	const{
		RandIter<T> tmp(*this);
		tmp.ptr -= offset;
		return tmp;
	}

	difference_type	operator-(RandIter<T> const& rhs)	const{
		difference_type diff = 0;
		RandIter<T> tmp(*this);
		while (tmp++ != rhs)
			diff++;
		return diff;
	}

	T&	operator[](difference_type offset)	const{
		return ptr[offset];
	}

	bool operator<(const RandIter<T> &rhs) 	{return ptr < rhs.ptr;}
	bool operator<=(const RandIter<T> &rhs)	{return ptr <= rhs.ptr;}
	bool operator>(const RandIter<T> &rhs)	{return ptr > rhs.ptr;}
	bool operator>=(const RandIter<T> &rhs)	{return ptr >= rhs.ptr;}
	bool operator==(const RandIter<T> &rhs)	{return ptr == rhs.ptr;}
	bool operator!=(const RandIter<T> &rhs)	{return ptr != rhs.ptr;}
	pointer ptr;
};
#endif