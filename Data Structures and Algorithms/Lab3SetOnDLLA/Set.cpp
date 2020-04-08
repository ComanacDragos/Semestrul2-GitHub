#include "Set.h"
#include "SetITerator.h"

#include <iostream>
//Theta(1) (the two loops execute once always)
Set::Set() {
	//TODO - Implementation
	this->capacity = 2;
	this->length = 0;
	this->nodes = new DLLANode[this->capacity];

	this->head = -1;
	this->tail = -1;
	this->firstEmpty = 0;
	
	for (int i = 0; i < this->capacity - 1; i++)
		this->nodes[i].next = i + 1;
	this->nodes[this->capacity - 1].next = -1;

	this->nodes[0].prev = -1;
	for (int i = 1; i < this->capacity; i++)
		this->nodes[i].prev = i - 1;
}


bool Set::add(TElem elem) {
	//TODO - Implementation
	if (this->head == -1)
	{
		this->head = this->firstEmpty;
		this->tail = this->firstEmpty;
		
		this->firstEmpty = this->nodes[firstEmpty].next;

		this->nodes[this->head].next = -1;
		this->nodes[this->head].prev = -1;
		this->nodes[this->head].info = elem;
		this->length += 1;
		
		return true;
	}

	if (this->search(elem) == true)
		return false;

	if (this->length == this->capacity)
	{
		this->capacity *= 2;
		DLLANode* largerNodes = new DLLANode[this->capacity+1];

		for (int i = 0; i < this->length; i++)
			largerNodes[i] = this->nodes[i];

		delete[] this->nodes;
		this->nodes = largerNodes;
		
		this->firstEmpty = this->length;

		this->nodes[this->length].next = this->length + 1;
		this->nodes[this->length].prev = tail;
		
		for (int i = this->length + 1; i < this->capacity - 1; i++)
		{
			this->nodes[i].next = i + 1;
			this->nodes[i].prev = i - 1;
		}
		this->nodes[this->capacity - 1].next = -1;
		this->nodes[this->capacity - 1].prev = this->capacity - 2;

	}

	int aux = this->nodes[firstEmpty].next;
	this->nodes[tail].next = this->firstEmpty;

	this->nodes[this->firstEmpty].info = elem;
	this->nodes[this->firstEmpty].next = -1;
	this->nodes[this->firstEmpty].prev = tail;

	tail = firstEmpty;
	firstEmpty = aux;

	this->length += 1;

	/*
	std::cout << '\n';
	std::cout << "\n\nelems: ";
	for (int i = 0; i < this->capacity; i++)
	{
		std::cout << this->nodes[i].info << ' ';
	}
	
	std::cout << "\nnext: ";
	for (int i = 0; i < this->capacity; i++)
	{
		std::cout << this->nodes[i].next << ' ';
	}

	std::cout << '\n';
	std::cout << "prev: ";
	for (int i = 0; i < this->capacity; i++)
	{
		std::cout << this->nodes[i].prev << ' ';
	}

	std::cout << "\nFirst empty: " << this->firstEmpty << "\nHead: " << this->head << "\nTail: " << this->tail;
	*/

	return true;
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
	int current = this->head;

	if (this->length == 1)
	{
		if (this->nodes[this->head].info != elem)
			return false;

		this->nodes[this->head].next = this->firstEmpty;
		this->firstEmpty = this->head;

		this->head = -1;
		this->tail = -1;

		this->length -= 1;


		/*
		std::cout << '\n';
		std::cout << "\n\nelems: ";
		for (int i = 0; i < this->capacity; i++)
		{
			std::cout << this->nodes[i].info << ' ';
		}

		std::cout << "\nnext: ";
		for (int i = 0; i < this->capacity; i++)
		{
			std::cout << this->nodes[i].next << ' ';
		}

		std::cout << '\n';
		std::cout << "prev: ";
		for (int i = 0; i < this->capacity; i++)
		{
			std::cout << this->nodes[i].prev << ' ';
		}

		std::cout << "\nFirst empty: " << this->firstEmpty << "\nHead: " << this->head << "\nTail: " << this->tail;
		*/

		return true;
	}

	while (current != -1)
	{
		if (this->nodes[current].info == elem)
		{
			if (current == this->head)
			{
				this->head = this->nodes[this->head].next;
				this->nodes[this->head].prev = -1;

				this->nodes[current].next = this->firstEmpty;
				this->firstEmpty = current;
				this->nodes[this->firstEmpty].prev = this->tail;

				this->length -= 1;


				/*
				std::cout << '\n';
				std::cout << "\n\nelems: ";
				for (int i = 0; i < this->capacity; i++)
				{
					std::cout << this->nodes[i].info << ' ';
				}

				std::cout << "\nnext: ";
				for (int i = 0; i < this->capacity; i++)
				{
					std::cout << this->nodes[i].next << ' ';
				}

				std::cout << '\n';
				std::cout << "prev: ";
				for (int i = 0; i < this->capacity; i++)
				{
					std::cout << this->nodes[i].prev << ' ';
				}

				std::cout << "\nFirst empty: " << this->firstEmpty << "\nHead: " << this->head << "\nTail: " << this->tail;
				*/

				return true;
			}

			if (current == this->tail)
			{
				this->tail = this->nodes[this->tail].prev;
				this->nodes[this->tail].next = -1;

				this->nodes[current].next = this->firstEmpty;
				this->firstEmpty = current;
				this->nodes[this->firstEmpty].prev = this->tail;

				this->length -= 1;


				/*
				std::cout << '\n';
				std::cout << "\n\nelems: ";
				for (int i = 0; i < this->capacity; i++)
				{
					std::cout << this->nodes[i].info << ' ';
				}

				std::cout << "\nnext: ";
				for (int i = 0; i < this->capacity; i++)
				{
					std::cout << this->nodes[i].next << ' ';
				}

				std::cout << '\n';
				std::cout << "prev: ";
				for (int i = 0; i < this->capacity; i++)
				{
					std::cout << this->nodes[i].prev << ' ';
				}

				std::cout << "\nFirst empty: " << this->firstEmpty << "\nHead: " << this->head << "\nTail: " << this->tail;
				*/


				return true;
			}

			int previous = this->nodes[current].prev;
			int next = this->nodes[current].next;

			this->nodes[current].next = this->firstEmpty;
			this->firstEmpty = current;

			this->nodes[previous].next = next;
			this->nodes[next].prev = previous;

			this->length -= 1;


			/*
			std::cout << '\n';
			std::cout << "\n\nelems: ";
			for (int i = 0; i < this->capacity; i++)
			{
				std::cout << this->nodes[i].info << ' ';
			}

			std::cout << "\nnext: ";
			for (int i = 0; i < this->capacity; i++)
			{
				std::cout << this->nodes[i].next << ' ';
			}

			std::cout << '\n';
			std::cout << "prev: ";
			for (int i = 0; i < this->capacity; i++)
			{
				std::cout << this->nodes[i].prev << ' ';
			}

			std::cout << "\nFirst empty: " << this->firstEmpty << "\nHead: " << this->head << "\nTail: " << this->tail;
			*/

			return true;
		}
		current = this->nodes[current].next;
	}

	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
	int current = this->head;

	while (current != -1)
	{
		if (this->nodes[current].info == elem)
			return true;
		current = this->nodes[current].next;
	}

	return false;
}


int Set::size() const {
	//TODO - Implementation
	return this->length;
}


bool Set::isEmpty() const {
	//TODO - Implementation
	return this->head == -1;
}


Set::~Set() {
	//TODO - Implementation
	delete[] this->nodes;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


