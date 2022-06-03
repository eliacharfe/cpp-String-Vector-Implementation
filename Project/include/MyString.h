#pragma once

#include "Utilities.h"

class MyString
{
public:
	MyString();
	MyString(char c);
	MyString(size_t size, char c);
	MyString(const char* str);
	MyString(const char* str, size_t size);
	MyString(const MyString& other);
	~MyString();

	char& operator[] (size_t i);
	const char& operator[] (size_t i) const;

	MyString& operator= (const  MyString& other);
	MyString& operator= (const char* str);

	MyString operator+(const MyString& other) const;
    MyString& operator+= (const MyString& other);

	const char* data() const;
	const char* c_str() const;
	const bool empty() const;
	void clear();
	void resize(size_t n);
	void resize(size_t n, char c);
	void swap(MyString& other);

	char* getString() const;
	size_t size() const;

	int strlen(const char* str) const;
	char* strcpy(char* dest, const char* source);

private:
	char* m_str;
	size_t m_size;

	void allocate(size_t size);
	void copy(char* dest, const char* source, size_t start, size_t end) ;
	void copy(char* dest, size_t start, size_t end, char val) ;

};
//------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const MyString& str);

const bool operator<(const MyString& str1, const MyString& str2);
const bool operator>(const MyString& str1, const MyString& str2);
const bool operator==(const MyString& str1, const MyString& str2);
const bool operator!=(const MyString& str1, const MyString& str2);
const bool operator<=(const MyString& str1, const MyString& str2);
const bool operator>=(const MyString& str1, const MyString& str2);





//template< class T >
//class MyStr
//{
//public:
//	MyString(T first, T last);
//
//
//private:
//
//};

//template<class T>
//inline MyStr<T>::MyString(T first, T last)
//{
//}
