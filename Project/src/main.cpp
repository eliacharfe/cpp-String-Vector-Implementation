#include <iostream>
#include "Test.h"

#define StringTest 1 // 0 will turn it off / 1  will turn it on
#define VectorTest 1 // 0 will turn it off / 1  will turn it on

int main()
{
#if StringTest
	try {
		testString();
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
#endif

#if VectorTest

	try {
		testVector();
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
	catch (...) {
		cout << "catch ..." << endl;
	}


#endif

	return EXIT_SUCCESS;
}