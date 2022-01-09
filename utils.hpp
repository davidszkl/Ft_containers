	#pragma once
	#include <iostream>
	#include <type_traits>
	namespace ft
	{
	
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	template<typename T> struct is_integral_base: std::false_type {};

	template<> struct is_integral_base<bool>						: public std::true_type {};
	template<> struct is_integral_base<char>						: public std::true_type {};
	template<> struct is_integral_base<unsigned char>				: public std::true_type {};
	template<> struct is_integral_base<char16_t>					: public std::true_type {};
	template<> struct is_integral_base<char32_t>					: public std::true_type {};
	template<> struct is_integral_base<wchar_t>						: public std::true_type {};
	template<> struct is_integral_base<unsigned wchar_t>			: public std::true_type {};
	template<> struct is_integral_base<short>						: public std::true_type {};
	template<> struct is_integral_base<unsigned short>				: public std::true_type {};
	template<> struct is_integral_base<int>							: public std::true_type {};
	template<> struct is_integral_base<long>						: public std::true_type {};
	template<> struct is_integral_base<unsigned long>				: public std::true_type {};
	template<> struct is_integral_base<long long>					: public std::true_type {};
	template<> struct is_integral_base<unsigned long long>			: public std::true_type {};



	template<> struct is_integral_base<const bool>						: public std::true_type {};
	template<> struct is_integral_base<const char>						: public std::true_type {};
	template<> struct is_integral_base<const unsigned char>				: public std::true_type {};
	template<> struct is_integral_base<const char16_t>					: public std::true_type {};
	template<> struct is_integral_base<const char32_t>					: public std::true_type {};
	template<> struct is_integral_base<const wchar_t>					: public std::true_type {};
	template<> struct is_integral_base<const unsigned wchar_t>			: public std::true_type {};
	template<> struct is_integral_base<const short>						: public std::true_type {};
	template<> struct is_integral_base<const unsigned short>			: public std::true_type {};
	template<> struct is_integral_base<const int>						: public std::true_type {};
	template<> struct is_integral_base<const long>						: public std::true_type {};
	template<> struct is_integral_base<const unsigned long>				: public std::true_type {};
	template<> struct is_integral_base<const long long>					: public std::true_type {};
	template<> struct is_integral_base<const unsigned long long>		: public std::true_type {};



	template<> struct is_integral_base<volatile bool>						: public std::true_type {};
	template<> struct is_integral_base<volatile char>						: public std::true_type {};
	template<> struct is_integral_base<volatile unsigned char>				: public std::true_type {};
	template<> struct is_integral_base<volatile char16_t>					: public std::true_type {};
	template<> struct is_integral_base<volatile char32_t>					: public std::true_type {};
	template<> struct is_integral_base<volatile wchar_t>					: public std::true_type {};
	template<> struct is_integral_base<volatile unsigned wchar_t>			: public std::true_type {};
	template<> struct is_integral_base<volatile short>						: public std::true_type {};
	template<> struct is_integral_base<volatile unsigned short>				: public std::true_type {};
	template<> struct is_integral_base<volatile int>						: public std::true_type {};
	template<> struct is_integral_base<volatile long>						: public std::true_type {};
	template<> struct is_integral_base<volatile unsigned long>				: public std::true_type {};
	template<> struct is_integral_base<volatile long long>					: public std::true_type {};
	template<> struct is_integral_base<volatile unsigned long long>			: public std::true_type {};


	template<class T> struct is_integral : public is_integral_base<T> {};

	}