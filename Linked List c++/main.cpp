//this code works for a singly linked list, however the backwards links are
//giving me trouble.

#include "List.h"
#include "Node.h"


int main()
{
	List l;

	l.insert(2);
	l.insert(3);
	l.insert(10);
	l.insert(44);
	l.insert(9);

	l.sort();
	l.printList();

	l.insert(22);
	l.insert(35);

	l.sort();
	l.printList();
	
    return 0;
}

