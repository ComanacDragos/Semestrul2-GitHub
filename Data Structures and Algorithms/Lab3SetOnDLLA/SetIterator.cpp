#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	this->current = set.head;
}


void SetIterator::first() {
	//TODO - Implementation
	this->current = set.head;
}


void SetIterator::next() {
	//TODO - Implementation
	if (this->current == -1)
		throw std::exception("invalid iterator");
	this->current = set.nodes[this->current].next;
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (this->valid() == false)
		throw std::exception("invalid iterator");

	return set.nodes[this->current].info;
}

bool SetIterator::valid() const {
	//TODO - Implementation
	return this->current != -1;
}



