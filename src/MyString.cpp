#include "MyString.h"

MyString::MyString()
	: m_size(0), m_str(nullptr)
{
	m_str = new char[1];
	m_str[0] = '\0';
}
//----------------------
MyString::MyString(char c)
	: MyString(sizeof(c), c) // call MyString::MyString(int size, char c)
{}
//---------------------------
MyString::MyString(size_t size, char c)
{
	try {
		allocate(size);
		copy(m_str, 0, size, c);
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("bad alloc in constructor\n");
	}
	catch (...) { throw; }
}
//-----------------------
MyString::MyString(const char* str)
	: MyString(str, strlen(str)) // call MyString::MyString(const char* str, int size)
{}
//-----------------------------------------
MyString::MyString(const char* str, size_t size)
{
	try {
		if (str == nullptr) {
			allocate(0);
		}
		else {
			allocate(size);
			m_str = strcpy(m_str, str);
		}
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("bad alloc in constructor\n");
	}
	catch (...) { throw; }
}
//-------------------------
MyString::MyString(const MyString& other)
{ // copy constructor
	*this = other;
}
//------------------------
MyString::~MyString()
{
	if (m_str)
		delete[] m_str;
}
//------------------------------------------
char& MyString::operator[](size_t i)
{
	if (i < 0 || i >= m_size)
		throw OutOfRange("out of range");
	return m_str[i];
}
//----------------------------------
const char& MyString::operator[](size_t i) const
{
	if (i < 0 || i >= m_size)
		throw OutOfRange("out of range");
	return m_str[i];
}
//----------------------------------------
MyString& MyString::operator=(const MyString& other)
{
	try {
		if (this == &other)// check addresses
			return *this;

		allocate(strlen(other.getString()));
		m_str = strcpy(m_str, other.getString());

		return *this;
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("bad alloc im operator = \n");
	}
	catch (std::exception e) { cout << e.what(); }
	catch (...) { throw; }
}
//------------------------------------
MyString& MyString::operator=(const char* other)
{
	try {
		allocate(strlen(other));
		copy(m_str, other, 0, m_size);
		return *this;
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("bad alloc im operator = \n");
	}
	catch (...) { throw; }
}
//-----------------------------------------
MyString MyString::operator+(const MyString& str) const
{
	try {
		size_t size = m_size + str.size();
		MyString newString;
		newString.m_size = size;
		newString.m_str = new char[size + 1];

		int i;
		for (i = 0; i < m_size; i++)
			newString.m_str[i] = m_str[i];

		int j = 0;
		for (; i < size; i++) {
			newString.m_str[i] = str[j];
			j++;
		}
		newString.m_str[size] = '\0';
		return newString;

	}
	catch (std::bad_alloc e) {
		throw BadAllocation("bad alloc im operator + \n");
	}
	catch (...) { throw; }
}
//----------------------------------------------
MyString& MyString::operator+=(const MyString& str)
{
	return *this = *this + str;
}
//----------------------------------
int MyString::strlen(const char* str) const
{
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
		length++;
	return length;
}
//------------------------------------------
char* MyString::strcpy(char* dest, const char* source)
{
	try {
		if (dest == nullptr || strlen(dest) < strlen(source))
			return nullptr; 	// if memory is not allocated correctly in destination - return

		int index = 0;
		for (index = 0; index < strlen(source) && source[index] != '\0'; index++)
			dest[index] = source[index];
		dest[index] = '\0';

		return dest;
	}
	catch (std::exception e) {
		throw MyException("in mystrcpy\n");
	}
	catch (...) { throw; }
}
//-----------------------
void MyString::allocate(size_t size)
{
	try {
		m_size = size;
		m_str = nullptr;
		m_str = new char[++size];
		m_str[m_size] = '\0';
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("catch is allocate (bad allocation) \n");
	}
	catch (...) { throw; }
}
//------------------------------------
void MyString::copy(char* dest, const char* source, size_t start, size_t end)
{
	for (size_t i = start; i < end; i++)
		dest[i] = source[i];
	dest[end] = '\0';
}
//----------------------------
void MyString::copy(char* dest, size_t start, size_t end, char val)
{
	for (size_t i = start; i < end; i++)
		dest[i] = val;
}
//---------------------------------
const char* MyString::data() const
{
	return (m_str) ? m_str : nullptr;
}
//--------------------------
const char* MyString::c_str() const
{
	m_str[m_size] = '\0';
	return (m_str) ? m_str : nullptr;
}
//--------------------------
const bool MyString::empty() const
{
	return (m_str == nullptr) || (m_str[0] == '\0') || (m_size == 0);
}
//---------------------------
void MyString::clear()
{
	for (size_t i = 0; i < m_size; i++)
		m_str[i] = '\0';
	m_size = 0;
}
//-------------------------------
void MyString::resize(size_t size)
{
	try {
		resize(size, '\0'); // reuse
	}
	catch (...) { throw; }
}
//---------------------------------
void MyString::resize(size_t size, char c)
{
	if (m_size == size)
		return;
	try {
		MyString temp = *this;

		if (size < m_size) {
			allocate(size);
			copy(m_str, temp.getString(), 0, m_size);
		}
		else {
			allocate(size);
			copy(m_str, temp.getString(), 0, temp.size());
			copy(m_str, temp.size(), m_size, c);
		}
	}
	catch (std::bad_alloc e) {
		throw BadAllocation("cannot resize\n");
	}
	catch (...) {
		throw MyException("Unknown Exception");
	}
}
//----------------------------
void MyString::swap(MyString& other)
{
	MyString temp = *this;
	*this = other;
	other = temp;
}
//-------------------------------
char* MyString::getString() const
{
	return m_str;
}
//----------------------------
size_t MyString::size() const
{
	return m_size;
}
//---------------------------------------------------
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	for (int i = 0; i < str.size(); i++)
		os << str[i];
	return os;
}
//----------------------------------------------
const bool operator<(const MyString& str1, const MyString& str2)
{
	char* s1 = str1.getString();
	char* s2 = str2.getString();

	for (int i = 0; i < std::max(str1.size(), str2.size()); i++)
	{
		if (s1[i] != s2[i])
			return s1[i] < s2[i] ? true : false;

		if (s1[i] == '\0') // if both are equals to NULL (if (s1 == s2) )
			return false;
	}
	return false; // never
}
//---------------------------------------------
const bool operator>(const MyString& str1, const MyString& str2)
{
	if (!(str1 < str2)) { // if str1 >= str2
		for (int i = 0; i < str1.size() && str2[i] != '\0'; i++)
			if (str1[i] != str2[i])
				return true; // if (str1 >= str2) and (str1 != str2)   ==>  str1 > str2
	}
	return false;;
}
//--------------------------------------------
const bool operator==(const MyString& str1, const MyString& str2)
{
	return !(str1 < str2) && !(str1 > str2);
}
////-----------------------------------
const bool operator!=(const MyString& str1, const MyString& str2)
{
	return !(str1 == str2);
}
//-------------------------------
const bool operator<=(const MyString& str1, const MyString& str2)
{
	return !(str1 > str2);
}
//-------------------------------------
const bool operator>=(const MyString& str1, const MyString& str2)
{
	return !(str1 < str2);
}