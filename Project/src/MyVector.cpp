#include "MyVector.h"


MyVector::MyVector(size_t size, int value)
	:m_size(size), m_capacity(m_size * NORMAL_CAP + 1), m_vector(nullptr)
{
	try {
		allocate(m_size);
		copy(m_vector, 0, m_size, value);
	}
	catch (std::bad_alloc e) { throw BadAllocation("bad allocation in constructor\n"); }
	catch (...) { throw; }
}
//------------------------------------
MyVector::MyVector(const MyVector& other)
{
	*this = other;
}
//-------------------------
MyVector::~MyVector()
{
	if (m_vector)
		delete[] m_vector;
}
//--------------------------------------
int& MyVector::operator[](size_t i)
{
	if (i < 0 || i >= m_size)
		throw OutOfRange("out of range");
	return m_vector[i];
}
//------------------------------------
const int& MyVector::operator[](size_t i) const
{
	if (i < 0 || i >= m_size)
		throw OutOfRange("out of range");
	return m_vector[i];
}
//-----------------------------------------
MyVector& MyVector::operator=(const MyVector& other)
{
	try {
		if (this == &other)// check addresses
			return *this;

		allocate(other.size());
		copy(m_vector, other.getVector(), 0, m_size);

		return *this;
	}
	catch (std::bad_alloc e) { throw BadAllocation("bad alloc im operator = \n"); }
	catch (...) { throw; }
}
//-------------------------------
int* MyVector::getVector() const
{
	return m_vector;
}
//-------------------------
size_t MyVector::size() const
{
	return m_size;
}
//-------------------------------
size_t MyVector::capacity() const
{
	return m_capacity;
}
//--------------------------
const bool MyVector::empty() const
{
	return (m_vector[0] == '\0') || (m_size == 0);
}
//---------------------------
void MyVector::clear()
{
	for (size_t i = 0; i < m_size; i++)
		m_vector[i] = '\0';
	m_size = 0;
}
//-----------------------------
int* MyVector::data() 
{
	return (m_vector) ? m_vector : nullptr;
}
//--------------------------------
void MyVector::swap(MyVector& other)
{
	try {
		int* temp_vec = m_vector;
		size_t temp_size = m_size;
		size_t temp_cap = m_capacity;

		m_vector = other.getVector();
		m_size = other.size();
		m_capacity = other.capacity();

		other.setVector(temp_vec, temp_size, temp_cap);
	}
	catch (...) { throw; }
}
//------------------------------------
void MyVector::push_back(const int& x)
{ // push x at the end of the vector
	if (m_size >= m_capacity)
		reserve(std::ceil(getMultiplyCapacity() * m_size) + 1);

	m_vector[m_size++] = x;
}
//-----------------------
void MyVector::reserve(size_t newCapacity)
{
	if (newCapacity < m_size)
		return;

	try {
		int* newStr = new int[newCapacity + 1];
		copy(newStr, m_vector, 0, m_size);
		m_capacity = newCapacity;
		m_vector = new  int[m_capacity + 1];
		copy(m_vector, newStr, 0, m_size);
		delete[] newStr;
	}
	catch (std::out_of_range e) { throw OutOfRange("in reserve: out of range\n"); }
	catch (std::bad_alloc e) { throw BadAllocation("in reserve: bad allocation\n"); }
	catch (...) { throw; }
}
//-----------------------------
void MyVector::pop_back()
{ // erase the last element of the vector
	try {
		size_t size = m_size;
		m_vector[m_size] = '\0';
		resize(--size);
	}
	catch (...) { throw; }
}
//--------------------------------
void MyVector::resize(size_t size)
{
	try {
		resize(size, '\0');
	}
	catch (...) { throw; }
}
//-----------------------------
void MyVector::resize(size_t size, int val)
{
	if (size == m_size)
		return;
	try {
		MyVector temp = *this;

		if (size < m_size)
		{
			m_size = m_capacity = size;
			allocate(m_size);
			copy(m_vector, temp.getVector(), 0, m_size);
		}
		else {
			m_size = size;
			allocate(m_size);
			copy(m_vector, temp.getVector(), 0, temp.size());
			copy(m_vector, temp.size(), m_size, val);
			clearEmptyCells();
		}
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("cannot resize\n");
	}
	catch (...) {
		throw MyException("Unknown Exception");
	}
}
//-----------------------------
void MyVector::erase(size_t index)
{
	if (index > m_capacity)
		throw OutOfRange("index requird is out of range");

	for (size_t i = index; i < m_size; i++)
		m_vector[i] = m_vector[i + 1];
	--m_size;
	m_vector[m_size] = '\0';
}
//----------------------------------
void MyVector::insert(size_t index, int val)
{
	if (index > m_capacity)
		throw OutOfRange("index required is out of range");

	m_size++;
	if (m_size == m_capacity)
		reserve((std::ceil(getMultiplyCapacity()) * m_capacity) + 1);

	for (size_t i = m_size; i >= index; i--)
		m_vector[i] = m_vector[i - 1];

	m_vector[index] = val;
}
//-----------------------------------
void MyVector::setVector(int* newVector, size_t size, size_t capacity)
{
	try {
		allocate(size);
		m_vector = newVector;
		m_size = size;
		m_capacity = capacity;
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("catch is allocate (bad allocation)\n");
	}
	catch (...) { throw; }
}
//--------------------------------
void MyVector::allocate(size_t size)
{ // allocate the vector to a new empty vector of size given,
	//and change its size and capacity according to new size
	try {
		m_size = size;
		m_capacity = (size * NORMAL_CAP) + 1;
		m_vector = new int[m_capacity + 1];
		m_vector[m_capacity] = '\0';
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("catch is allocate (bad allocation)\n");
	}
	catch (...) { throw; }
}
//--------------------------
void MyVector::clearEmptyCells()
{
	for (size_t i = m_size; i < m_capacity; i++)
		m_vector[i] = '\0';
}
//----------------------------------
void MyVector::copy(int* dest, int* source, size_t start, size_t end) const
{ // get destiny vector and source and copy the source to destiny from index start to index end passed
	if (start > end)
		throw OutOfRange("start is bigger than end\n");
	if (dest == nullptr)
		throw OutOfRange("memory is not allocated in destiny correctly\n");// if memory is not allocated correctly in destination - return

	for (size_t i = start; i < end; i++)
		dest[i] = source[i];
	dest[end] = '\0';
}
//--------------------------------------------------
void MyVector::copy(int* dest, size_t start, size_t end, int value) const
{ // copy the value passed to the vector from index start to index end
	if (start > end)
		throw OutOfRange("start is bigger than end\n");

	for (size_t i = start; i < end; i++)
		dest[i] = value;
}
//---------------------------------------
double MyVector::getMultiplyCapacity() const
{
	return (m_capacity < BIG_CAPACITY) ? NORMAL_CAP : LARGE_CAP; // return 2 or 1.5
}
//---------------------------------------------------------
std::ostream& operator<<(std::ostream& os, MyVector& vector)
{
	for (int i = 0; i < vector.size(); i++)
		os << vector[i];
	return os;
}
//----------------------------------------------
const bool operator<(const MyVector& vec1, const MyVector& vec2)
{
	try {
		int* v1 = vec1.getVector();
		int* v2 = vec2.getVector();

		for (int i = 0; i < std::max(vec1.size(), vec2.size()); i++)
		{
			if (v1[i] != v2[i])
				return v1[i] < v2[i] ? true : false;

			if (v1[i] == '\0')
				return false;
		}
		return false;
	}
	catch (...) {
		cout << "error in operator <" << endl;
		throw;
	}
}
//-----------------------------------------
const bool operator>(const MyVector& vec1, const MyVector& vec2)
{
	if (!(vec1 < vec2)) { // if v1 >= v2
		for (int i = 0; i < vec1.size() && vec2[i] != '\0'; i++)
			if (vec1[i] != vec2[i])
				return true; // if (v1 >= str2) and (v1 != str2)   ==>  v1 > v2
	}
	return false;;
}
//----------------------------
const bool operator==(const MyVector& vec1, const MyVector& vec2)
{
	return !(vec1 < vec2) && !(vec1 > vec2);
}
//-----------------------------
const bool operator!=(const MyVector& vec1, const MyVector& vec2)
{
	return !(vec1 == vec2);
}
//------------------------------------
const bool operator<=(const MyVector& v1, const MyVector& v2)
{
	return !(v1 > v2);
}
//------------------------------------------
const bool operator>=(const MyVector& v1, const MyVector& v2)
{
	return !(v1 < v2);
}
//----------------------------
