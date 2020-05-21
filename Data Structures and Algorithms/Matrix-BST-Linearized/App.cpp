
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;

#include <assert.h>

int main() {

	int size = 2000;
	Matrix m(size / 2, size);
	for (int i = 0; i < size / 2; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				m.modify(i, j, 11);
			}
			else if (i == 100 * j) {
				m.modify(i, j, 111);
			}
			else if ((i + j) % 1111 == 0) {
				m.modify(i, j, 1111);
			}
		}
	}

	for (int i = 0; i < size / 2; i++) {
		int k = 0;
		for (int j = 0; j < size; j++) {
			if (j == 1112)
			{
				int a;
				a = 0;
				a += 1;

			}
			if (i == j) {
				TElem old = m.modify(i, j, NULL_TELEM);
				assert(old == 11);
			}
			else if (i == 100 * j) {
				TElem old = m.modify(i, j, -111);
				assert(old == 111);
			}
			else if ((i + j) % 1111 == 3) {
				m.modify(i, j, 1);
			}
		}
	}
	for (int i = 0; i < size / 2; i++) {
		for (int j = 0; j < size; j++) {
			TElem e = m.element(i, j);
			if (i == j) {
				assert(e == NULL_TELEM);
			}
			else if (i == 100 * j) {
				assert(e == -111);
			}
			else if ((i + j) % 1111 == 3) {
				assert(e == 1);
			}
			else if ((i + j) % 1111 == 0) {
				assert(e == 1111);
			}
			else {
				assert(e == NULL_TELEM);
			}
		}
	}

	testAll();
	testAllExtended();
	cout << "Test End" << endl;
	system("pause");
}