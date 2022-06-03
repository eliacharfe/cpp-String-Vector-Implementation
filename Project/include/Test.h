#pragma once
#include "MyString.h"
#include "MyVector.h"

void testString();
void testConstructors(MyString& str1, MyString& str2);
void testStringCopy(MyString& str1, MyString& str2);
void testOperatorsEqualPlus_EqualPlus(MyString& str1, MyString& str2, MyString& str3);
void testOperatorSmallerBiggerOrEqualsOrNotEquals(MyString& str4, MyString& str5);
void testFunctions(MyString& str1, MyString& str2, MyString& str3, MyString& str4, MyString& str5);

void testVector();
void testConstructor(MyVector& v1, MyVector& v2, MyVector& v4);
void testFunctions(MyVector& v1, MyVector& v2, MyVector& v4);
void testOperatorEqual(MyVector& v1, MyVector& v2);
void testOperatorSmallerBiggerOrEqualsOrNotEquals(MyVector& vec5, MyVector& vec6);
