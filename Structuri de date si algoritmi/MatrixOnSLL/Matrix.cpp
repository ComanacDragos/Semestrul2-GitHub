#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	//TODO - Implementation
	length = 0;
	lines = nrLines;
	columns = nrCols;
	head = '\0';
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
	if (head == '\0')
		return 0;
	Node* p = head;
	while (p != '\0')
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
	while (p != '\0')
	{
		if (p->line == i && p->column == j)
		{
			TElem aux = p->value;
			p->value = e;
			return aux;
		}
		p = p->next;
	}


}


