#include "List.h"

List::List()
{
	pHead = nullptr;
}

List::~List()
{

}

Node* List::makeNode(int value)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->setValue(value);
	newNode->setNext(nullptr);
	newNode->setPrev(nullptr);
	return newNode;
}

bool List::isEmpty()
{
	if (pHead)
	{
		return false;
	}
	return true;
}

void List::insert(Node ** head, int value)
{
	Node* pMem = makeNode(value);

	if (!(*head))
	{
		*head = pMem;
	}

	//the list is not empty
	else
	{
		pMem->setNext((*head));
		(*head)->setPrev(pMem);
		(*head) = pMem;
	}

}

bool List::insert(int value)
{
	insert(&pHead, value);
	if (pHead)
	{
		return true;
	}
	return false;

}

//utility function to split a linked list into two separate lists.
//to be used with the merge sort algorithm.
Node * List::split(Node* head)
{
	Node * L1 = head, *L2 = head;
	while (L1->getNext() && L1->getNext()->getNext())
	{
		L1 = L1->getNext()->getNext();
		L2 = L2->getNext();
	}

	Node * pMem = L2->getNext();
	L2->setNext(nullptr);
	return pMem;
}

//utility function to physically perform the merge of two linked lists
Node * List::merge(Node * L1, Node * L2)
{
	//if first list is empty
	if (!L1)
	{
		return L2;
	}

	//if second list is empty
	if (!L2)
	{
		return L1;
	}

	//if inserting before...
	if (L1->getValue() < L2->getValue())
	{
		L1->setNext(merge(L1->getNext(), L2));
		L1->getNext()->setPrev(L1);
		L2->setPrev(nullptr);
		return L1;
	}
	//if inserting after...
	else
	{
		L2->setNext(merge(L1,L2->getNext()));
		L2->getNext()->setPrev(L2);
		L2->setPrev(nullptr);
		return L2;
	}

}

bool List::sort()
{
	Node * head = pHead;
	pHead = sort(head);
	return true;
}
//function that uses the merge sort algorithm to sort the nodes
//in a doubly linked list.
Node * List::sort(Node * head)
{
	if (!head || !head->getNext())
	{
		return head;
	}

	//split the list into two halves
	Node * L2 = split(head);

	//recursive case for left and right halves of the split list
	//continue to split until we have several lists of size one, then 
	//merge them.
	head = sort(head);
	L2 = sort(L2);

	return merge(head, L2);
	
}
void List::printList(Node * head)
{
	Node * temp = head;
	while (head)
	{
		std::cout << head->getValue() << " ";
		head = head->getNext();
	}
	std::cout << std::endl;
	while (temp)
	{
		std::cout << temp->getValue() << " ";
		temp = temp->getPrev();
	}
	std::cout << std::endl;
}
void List::printList()
{
	Node * head = pHead;
	printList(head);
}