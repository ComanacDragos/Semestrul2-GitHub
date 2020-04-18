#include "SetIterator.h"
#include "Set.h"

//theta(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	this->current = set.head;
}


//theta(1)
void SetIterator::first() {
	//TODO - Implementation
	this->current = set.head;
}


//theta(1)
void SetIterator::next() {
	//TODO - Implementation
	if (this->current == -1)
		throw std::exception("invalid iterator");
	this->current = this->set.nodes[this->current].next;
}


//theta(1)
TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (this->valid() == false)
		throw std::exception("invalid iterator");

	return this->set.nodes[this->current].info;
}

//theta(1)
bool SetIterator::valid() const {
	//TODO - Implementation
	return this->current != -1;
}



