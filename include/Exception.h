#pragma once

#pragma once

class BadAllocation : public std::bad_alloc
{
public:
	BadAllocation(const char* str) : m_str(str) {}
	const char* what() const noexcept { return m_str; }

private:
	const char* m_str;
};
//--------------------------------------------
class OutOfRange : public std::exception
{
public:
	OutOfRange(const char* str) : m_str(str) {}
	const char* what() const noexcept { return m_str; }

private:
	const char* m_str;
};
//------------------------------------------
class MyException : public std::exception
{
public:
	MyException(const char* str) : m_str(str) {}
	const char* what() const noexcept { return m_str; }

private:
	const char* m_str;
};
