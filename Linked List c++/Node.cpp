#include "Node.h"

Node::Node()
{
	pNext = nullptr;
	pPrev = nullptr;
}
Node::~Node()
{
	//write destructor code
}

void Node::setValue(int value)
{
	mValue = value;
}

int Node::getValue()
{
	return mValue; 
}

void Node::setNext(Node *node)
{
	pNext = node;
}

void Node::setPrev(Node *node)
{
	pPrev = node;
}



Node* Node::getNext()
{
	return pNext;
}

Node* Node::getPrev()
{
	return pPrev;
}