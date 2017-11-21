#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class List
{
public:
	List();
	~List();

	Node * makeNode(int value);

	bool isEmpty();

	
	bool insert(int value);

	

	Node * sort(Node * head);

	bool sort();

	void printList();
private:
	Node * pHead;

	void insert(Node ** head, int value);

	Node * split(Node* head);

	Node * merge(Node * L1, Node * L2);

	void printList(Node* head);
	
};