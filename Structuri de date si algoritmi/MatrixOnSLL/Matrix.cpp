#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	//TODO - Implementation
	length = 0;
	lines = nrLines;
	columns = nrCols;
	head = NULL;
}


int Matrix::nrLines() const {
	//TODO - Implementation
	return lines;
}


int Matrix::nrColumns() const {
	//TODO - Implementation
	return columns;
}


TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
	if (i < 0 || j < 0 || i >= lines || j >= columns)
		throw exception("Bad position");
	if (head == NULL)
		return 0;
	Node* p = head;
	while (p != NULL)
	{
		if (p->line == i && p->column == j)
			return p->value;
		p = p->next;
	}
	return 0;
}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
	if (i < 0 || j < 0 || i >= lines || j >= columns)
		throw exception("Bad position");

	Node* p = head;
	while (p!=NULL && (p->next->line < i || p->next->column < j))
	{
		if (p->line == i && p->column == j)
		{
			TElem aux = p->value;
			p->value = e;
			return aux;
		}
	}

	if (p->next->line == i && p->next->column == j)
	{
		TElem aux = p->next->value;
		p->next->value = e;
		return aux;
	}

	Node* new_node = new Node;
	new_node->line = i;
	new_node->column = j;
	new_node->value = e;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		return;
	}



	
	

}


