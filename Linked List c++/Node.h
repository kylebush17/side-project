#pragma once
#include <iostream>
class Node
{
public:
	Node();
	~Node();
	
	void setValue(int value);
	int getValue();

	void setNext(Node* node);
	void setPrev(Node*node);

	Node * getNext();
	Node * getPrev();

	
private:
	int mValue;
	Node* pNext;
	Node * pPrev;

};