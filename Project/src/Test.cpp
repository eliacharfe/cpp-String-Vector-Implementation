#include "Test.h"

//------------------------------------
// test NyString class
//-----------------------------------
void testString()
{
	try {
		MyString str1 = MyString();
		MyString str2("hey");
		MyString str3("string3");
		MyString str4 = "aaaa", str5 = "b";

		testConstructors(str1, str2);
		testStringCopy(str1, str2);
		testOperatorsEqualPlus_EqualPlus(str1, str2, str3);
		testOperatorSmallerBiggerOrEqualsOrNotEquals(str4, str5);
		testFunctions(str1, str2, str3, str4, str5);
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}
//------------------------------
void testConstructors(MyString& str1, MyString& str2)
{
	try {
		cout << "str1 = " << str1 << endl;
		cout << "str2 = " << str2 << endl;

		MyString strCopyConstructor(str2);
		cout << "strCopyConstructor = " << strCopyConstructor << endl;

		MyString ch_str('c');
		cout << "ch_str = " << ch_str << endl;

		MyString ch_str2(10, 'x');
		cout << "ch_str2 = " << ch_str2 << endl;

		MyString strTest("sssssssssssss");

		MyString strMove(MyString("abcd"));
		cout << "strMove = " << strMove << endl;
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}
//-----------------------------------------------
void testStringCopy(MyString& str1, MyString& str2)
{
	try {
		const char* stringToCopy = "strcpy copy";
		char* someStr = new char[strlen(stringToCopy)];

		strcpy(someStr, stringToCopy);
		cout << "someStr after strcpy: " << someStr << endl;

		someStr = new char[str2.size()];
		someStr = strcpy(someStr, str2.getString());
		cout << "someStr after strcpy: " << someStr << endl;

		someStr = new char[strlen("bla bla")];
		strcpy(someStr, "bla bla");
		cout << "someStr after strcpy: " << someStr << endl;

		someStr = new char[strlen(" ")];
		strcpy(someStr, " ");
		cout << "someStr after strcpy (copy white-space): " << someStr << endl;

	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}
//---------------------------------
void testOperatorsEqualPlus_EqualPlus(MyString& str1, MyString& str2, MyString& str3)
{
	try {
		str1 = str2;
		cout << "str1 = str2: str1 = " << str1 << endl;
		cout << "size of str1 = " << str1.size() << endl;

		str1 = "string #1";
		cout << "str1 = " << str1 << endl;
		cout << "size of str1 = " << str1.size() << endl;
		cout << "size of str2 = " << str2.size() << endl;

		str3 = str1 + str2;
		cout << "(str3 = str1 + str2): str3 = " << str3 << endl;

		str3 = str1 + " " + str2;
		cout << "(str3 = str1 + " " + str2) = " << str3 << endl;

		str1 += str3;
		cout << "str1 += str3 = " << str1 << endl;
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}

}
//---------------------------------------------------
void testOperatorSmallerBiggerOrEqualsOrNotEquals(MyString& str4, MyString& str5)
{
	try {
		if (str4 < str5)
			cout << "correct1\n";//correct1
		if (str4 > str5)
			cout << "not\n";

		if (str5 < str4)
			cout << "not\n";
		if (str5 > str4)
			cout << "correct2\n";//correct2

		if (str4 < str4)
			cout << "not\n";
		else
			cout << "correct3\n";// correct3

		str4 = "xxxxxxxxxxxxxxxxxxxxxaaaa", str5 = "bbbbbb";

		if (str4 < str5)
			cout << "not\n";
		if (str4 > str5)
			cout << "correct4\n";// correct4

		if (str5 < str4)
			cout << "correct5\n";// correct5
		if (str5 > str4)
			cout << "not\n";

		if (str4 == str4)
			cout << "correct6\n";// correct6
		else {
			cout << "not\n";
		}

		if (str5 == str4)
			cout << "not\n";
		else cout << "correct7\n";

		if (str5 != str4)
			cout << "correct8\n";

		if (str5 != str5)
			cout << "not\n";
		else cout << "correct9\n";

		str4 = "Eli";
		str5 = "Els";

		if (str4 < str5)
			cout << "correct10\n";

		str5 = "Elid";
		if (str4 < str5)
			cout << "correct11\n";

		if (str4 <= str5)
			cout << "correct12\n";

		if (str4 >= str5)
			cout << "not correct\n";

		str5 = "Eli";
		if (str4 <= str5)
			cout << "correct13\n";

		if (str4 >= str5)
			cout << "correct14\n";
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}
//------------------------------
void testFunctions(MyString& str1, MyString& str2, MyString& str3, MyString& str4, MyString& str5)
{
	try {
	
		const char* data = str2.data();
		cout << "data (of str2) = " << data << endl;

		const char* c_str = str2.c_str();
		cout << "c_str (of str2) = " << c_str << endl;

		(str1.empty()) ? cout << "not correct!\n" : cout << "correct\n";;

		MyString str6 = MyString();

		(str6.empty()) ? cout << "correct\n" : cout << "not correct\n";

		cout << "str3 before resize: " << str3 << ", size: " << str3.size() << endl;
		str3.resize(4);
		cout << "str3 after resize to 4: " << str3 << ", size: " << str3.size() << endl;

		str3.resize(8);
		cout << "str3 after resize to 8: " << str3 << ", size: " << str3.size() << endl;

		str3.resize(16, 'x');
		cout << "str3 after resize to 16 with 'x': " << str3 << ", size: " << str3.size() << endl;

		str3.resize(7, 'x');
		cout << "str3 after resize to 7 with 'x': " << str3 << ", size: " << str3.size() << endl;

		str5 = "Meir";
		cout << "Before swap str4 = " << str4 << " str5 = " << str5 << endl;
		str4.swap(str5);
		cout << "After swap str4 = " << str4 << " str5 = " << str5 << endl;

		cout << "str4 size: " << str4.size() << ", str4 = " << str4 << endl;
		str4.clear();
		cout << "after clear str4: " << endl;
		cout << "str4 size: " << str4.size() << ", str4 = " << str4 << endl;

		cout << "================================================\n\n";
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}



//-------------------------------------------------------------------
// test NyVector class
//------------------------------------------------------------------
void testVector()
{
	try {
		MyVector v1 = MyVector();
		MyVector v2(3, 1);
		MyVector v4 = MyVector(5, 4);
		MyVector vec5 = MyVector(3, 1);
		MyVector vec6 = MyVector(7, 9);

		testConstructor(v1, v2, v4);
		testOperatorEqual(v1, v2);
		testFunctions(v1, v2, v4);
		testOperatorSmallerBiggerOrEqualsOrNotEquals(vec5, vec6);
		cout << "End of tests" << endl;
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}
//-------------------------------
void testConstructor(MyVector& v1, MyVector& v2, MyVector& v4)
{
	try {
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;
		cout << "v4 = " << v4 << endl;

		MyVector vec = MyVector(v2);
		cout << "v(v2): " << vec << endl;
	}
	catch (...) { throw; }
}
//-------------------------------------
void testFunctions(MyVector& v1, MyVector& v2, MyVector& v4)
{
	try {
		MyVector v = MyVector();
		(v.empty()) ? cout << "correct\n" : cout << "not correct" << endl;
		(v2.empty()) ? cout << "not correct\n" : cout << "correct" << endl;
		cout << "v2 size: " << v2.size() << endl;

		int* p = v1.data();
		cout << "data: ";
		while (*p != '\0') {
			cout << *p;
			*p++;
		}

		cout << "v4 = " << v4 << endl;

		v1.swap(v4);
		cout << "After swap: v1=" << v1 << ", v4=" << v4 << endl;
		v4.swap(v1);
		cout << "After swap: v1=" << v1 << ", v4=" << v4 << endl;

		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;
		v1.push_back(9);
		cout << "v1 after push_back(9): " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.push_back(1);
		cout << "v1 after push_back(1): " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.push_back(3);
		cout << "v1 after push_back(3): " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.push_back(2);
		cout << "v1 after push_back(2): " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.push_back(55);
		cout << "v1 after push_back(55): " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.push_back(2022);
		cout << "v1 after push_back(2022): " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		cout << "befor::: v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;
		v1.resize(4);
		cout << "v1.resize(4) = " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.resize(10);
		cout << "v1.resize(10) = " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.resize(5);
		cout << "v1.resize(5) = " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.resize(11, 1);
		cout << "v1.resize(11, 1) = " << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		v1.pop_back();
		cout << "v1.pop_back():\n" << v1 << endl;
		cout << "v1.size: " << v1.size() << " v1.capacity: " << v1.capacity() << endl;

		MyVector vect = MyVector(0);
		vect.push_back(0);
		vect.push_back(1);
		vect.push_back(2);
		vect.push_back(3);
		vect.push_back(4);
		vect.push_back(5);

		cout << "vect  before erase = " << vect << ", size: " << vect.size() << ", cap: " << vect.capacity() << endl;
		vect.erase(2);
		cout << "vect after erase(2) = " << vect << ", size: " << vect.size() << ", cap: " << vect.capacity() << endl;

		cout << "vect  before insert = " << vect << ", size: " << vect.size() << ", cap: " << vect.capacity() << endl;
		vect.insert(2, 7);
		cout << "vect after insert(2, 7) = " << vect << ", size: " << vect.size() << ", cap: " << vect.capacity() << endl;

		MyVector bigVec = MyVector(100, 'c');
		cout << "bigVec.size: " << bigVec.size() << " bigVec.capacity: " << bigVec.capacity() << endl;

		for (int i = 0; bigVec.size() != bigVec.capacity() ; i++)
			bigVec.push_back('s');
		bigVec.push_back('a');
		cout << "bigVec.size: " << bigVec.size() << " bigVec.capacity: " << bigVec.capacity() << endl;

		cout << "vect size: " << vect.size() << ", vect = " << vect << ", vect mem: " << &vect << endl;
		vect.clear();
		cout << "after clear vect: " << endl;
		cout << "vect size: " << vect.size() << ", vect = " << vect << ", vect mem: " << &vect << endl;

	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}

}
//-----------------------------------
void testOperatorEqual(MyVector& v1, MyVector& v2)
{
	try {
		v1 = v2;
		cout << "(v1 = v2): v1 = " << v1 << endl;
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}
}
//--------------------------------------------------------
void testOperatorSmallerBiggerOrEqualsOrNotEquals(MyVector& vec5, MyVector& vec6)
{
	try {
		cout << "vec5=" << vec5 << " vec6=" << vec6 << endl;

		if (vec5 < vec6)
			cout << "correct1\n";//correct1
		if (vec5 > vec6)
			cout << "not\n";

		if (vec6 < vec5)
			cout << "not\n";
		if (vec6 > vec5)
			cout << "correct2\n";//correct2

		if (vec5 < vec5)
			cout << "not\n";
		else
			cout << "correct3\n";// correct3

		vec5 = MyVector(10, 9), vec6 = MyVector(3, 2);

		if (vec5 < vec6)
			cout << "not\n";
		if (vec5 > vec6)
			cout << "correct4\n";// correct4

		if (vec6 < vec5)
			cout << "correct5\n";// correct5
		if (vec6 > vec5)
			cout << "not\n";

		if (vec5 == vec5)
			cout << "correct6\n";// correct6
		else {
			cout << "not\n";
		}

		if (vec6 == vec5)
			cout << "not\n";
		else cout << "correct7\n";

		if (vec6 != vec5)
			cout << "correct8\n";

		if (vec6 != vec6)
			cout << "not\n";
		else cout << "correct9\n";

		vec5 = MyVector(2, 1);
		vec6 = MyVector(2, 2);

		if (vec5 <= vec6)
			cout << "correct10\n";

		if (vec5 >= vec6)
			cout << "not correct\n";

		vec6 = MyVector(2, 1);

		if (vec5 <= vec6)
			cout << "correct11\n";

		if (vec5 >= vec6)
			cout << "correct12\n";
	}
	catch (BadAllocation e) {
		cout << e.what() << endl;
	}
	catch (OutOfRange e) {
		cout << e.what() << endl;
	}
	catch (std::exception e) {
		cout << "catch: " << e.what() << endl;
	}

}
