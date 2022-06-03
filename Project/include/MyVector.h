#pragma once

#include "Utilities.h"

class MyVector 
{
public:
	 explicit MyVector(size_t size = 0, int value = 0);
	 MyVector(const MyVector& other);
	 ~MyVector();

	int& operator[] (size_t i);
	const int& operator[] (size_t i) const;
	MyVector& operator= (const  MyVector& other);

	size_t size() const;
	size_t capacity() const;
	const bool empty() const;
	void clear();
    int* data()  ;
	void swap(MyVector& other);
	void push_back(const int& x);
	void reserve(size_t newCapacity);
	void pop_back();
	void resize(size_t n);
	void resize(size_t n, int val);
	void erase(size_t index);
	void insert(size_t index, int val);

	int* getVector() const;

private:
	size_t m_size;
	size_t m_capacity;
	int* m_vector;

	void allocate(size_t size);
	void clearEmptyCells();
	void copy(int* dest, int* source, size_t start, size_t end) const;
	void copy(int* dest, size_t start, size_t end, int val) const;

	void setVector(int* v, size_t size, size_t cap);
	double getMultiplyCapacity() const;
};
//---------------------------
std::ostream& operator<<(std::ostream& os, MyVector& str);
const bool operator<(const MyVector& vec1, const MyVector& vec2);
const bool operator>(const MyVector& vec1, const MyVector& vec2);
const bool operator==(const MyVector& v1, const MyVector& v2);
const bool operator!=(const MyVector&v1, const MyVector& v2);
const bool operator<=(const MyVector& v1, const MyVector& v2);
const bool operator>=(const MyVector& v1, const MyVector& v2);
