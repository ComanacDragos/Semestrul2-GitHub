#include "Matrix.h"
#include <exception>
using namespace std;

//Thera
Matrix::Matrix(int nrLines, int nrCols) {
	   
	//TODO - Implementation
	this->lines = nrLines;
	this->columns = nrCols;
	this->size = 0;
	this->root = nullptr;
}


int Matrix::nrLines() const {
	//TODO - Implementation
	return this->lines;
}


int Matrix::nrColumns() const {
	//TODO - Implementation
	return this->columns;
}

TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
	if (i < 0 || j < 0 || j >= this->columns || i >= this->lines)
		throw std::exception("Invalid position");

	if (this->root == nullptr)
		return NULL_TELEM;

	Node* current = this->root;

	int stackSize = 1;
	int stackCapacity = 2;
	Node** stack = new Node*[stackCapacity];
	
	stack[0] = this->root;

	
	while (stackSize != 0)
	{
		Node* current = stack[stackSize];
		stackSize -= 1;
		if (current->line == i && current->column == j)
		{
			delete[] stack;
			return current->value;
		}

		if (stackCapacity - 1 <= stackSize)
		{
			stackCapacity *= 2;
			Node** largerStack = new Node * [stackCapacity];
			for (int i = 0; i < stackSize; i++)
				largerStack[i] = stack[i];

			delete[] stack;
			stack = largerStack;
		}

		stack[stackSize] = current->leftChild;
		stack[stackSize + 1] = current->rightChild;

		stackSize += 2;		
	}

	delete[] stack;
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
	if (this->root == nullptr)
	{
		if (e == NULL_TELEM)
			return NULL_TELEM;

		Node* newNode = new Node;
		newNode->line = i;
		newNode->column = j;
		newNode->value = e;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
		newNode->parent = nullptr;

		this->root = newNode;
		return NULL_TELEM;
	}

	Node* current = this->root;

	while (current != nullptr)
	{
		
	}
}


