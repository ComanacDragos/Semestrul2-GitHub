#pragma once
#include "TrenchCoat.h"
#include <iostream>

typedef TrenchCoat TElem;

class DynamicVector
{
private:
	int length, capacity;
	TElem* elements;

public:

	DynamicVector();

	// copy constructor
	DynamicVector(const DynamicVector& dynamicVector);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& dynamicVector);
	
	void addElement(const TElem& element);

	void removeFromPosition(int position);

	int getLength();

	// returns the element at a given position
	TElem& getElement(int position);

	// returns the position of the element and -1 if the element does not exist
	int findElement(TElem element);

private:
	void increaseSize();

	void shrinkSize();

};

