#include "DynamicVector.h"

DynamicVector::DynamicVector()
{
	this->capacity = 2;
	this->length = 0;
	this->elements = new TElem[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector& dynamicVector)
{
	this->capacity = dynamicVector.capacity;
	this->length = dynamicVector.length;
	this->elements = new TElem[this->capacity];

	for (int i = 0; i < this->length; i++)
		this->elements[i] = dynamicVector.elements[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elements;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& dynamicVector)
{
	if (this == &dynamicVector)
		return *this;

	this->capacity = dynamicVector.capacity;
	this->length = dynamicVector.length;
	delete[] this->elements;

	this->elements = new TElem[this->capacity];

	for (int i = 0; i < this->length; i++)
		this->elements[i] = dynamicVector.elements[i];

	return *this;
}

void DynamicVector::addElement(const TElem& element)
{	
	if (this->capacity == this->length)
		this->increaseSize();

	this->elements[this->length] = element;
	this->length += 1;
}

void DynamicVector::removeFromPosition(int position)
{
	
	for (int i = position; i < this->length; i++)
		this->elements[i] = this->elements[i + 1];
	
	this->length -= 1;

	if (this->length == this->capacity / 2)
		this->shrinkSize();
}

int DynamicVector::getLength()
{
	return this->length;
}

TElem& DynamicVector::getElement(int position)
{
	return this->elements[position];
}

int DynamicVector::findElement(TElem element)
{
	for (int i = 0; i < this->length; i++)
		if (this->elements[i] == element)
			return i;
	return -1;
}

void DynamicVector::increaseSize()
{
	this->capacity *= 2;
	TElem* largerElements = new TElem[this->capacity];
	
	for (int i = 0; i < this->length; i++)
		largerElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = largerElements;

}

void DynamicVector::shrinkSize()
{
	this->capacity /= 2;
	TElem* smallerElements = new TElem[this->capacity];

	for (int i = 0; i < this->length; i++)
		smallerElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = smallerElements;
}