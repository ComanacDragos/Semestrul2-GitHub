
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;

#include <assert.h>

int main() {

	testAll();
	testAllExtended();
	cout << "Test End" << endl;
	system("pause");
}