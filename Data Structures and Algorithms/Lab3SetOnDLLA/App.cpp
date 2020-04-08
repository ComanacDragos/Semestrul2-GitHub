#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
using namespace std;




int main() {

	testAll();
	testAllExtended();

	Set s;

	for (int i = 0; i < 5; i++)
		s.add(i);


	/*
	for (int i = 0; i < 1050; i++)
		s.add(i);
	
	for (int i = 0; i < 1050; i++)
		s.remove(1050-i-1);
	

	cout << "\n\nRemovals\n";
	s.remove(4);
	s.remove(3);
	s.remove(2);
	s.remove(1);
	s.remove(0);
	*/
	
	cout << "\n\n";
	cout << "That's all!" << endl;
	system("pause");

}



