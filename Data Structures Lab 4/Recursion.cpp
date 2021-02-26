/*Racy Halterman
* Data Structures Spring 2021
* Due: March 3rd
* Lab 3: Recursion
* A general stack program, but allows the user to reverse the order of the stack.
*/

#include "Recursion.h"

Recursion::Recursion()
{
	topitem = nullptr; //Sets the topitem to be null
}

Recursion::~Recursion()
{
	while (!(IsEmpty())) //Goes through the list and destroys the items in it.
	{
		Pop();
	}
}

bool Recursion::IsEmpty()
{
	return (topitem == NULL);
}

bool Recursion::IsFull()
{
	try
	{
		node* attempt = new node;
		delete attempt;
		return false;//If it can do this, then it returns false.
	}
	catch (std::bad_alloc& ba) //Pulled this off D. Busch's example. It works, so why not?
	{
		return true;
	}
}

int Recursion::Pop()
{
	node* temp; //creat temp node.
	int p;
	temp = topitem; //set temp node to the top.
	p = temp->data; //sets p as the temp's data.
	topitem = topitem->next; //moves topitem to the next item.
	free(temp); //I saw this somewhere, and thought it was cool, and so I tried it. Basically, it just deallocates the memory.
	return p; //returns the value that was deleted.
}

void Recursion::Push(int value)
{
	if (!(IsFull()))
	{
		node* temp = new node;
		temp->data = value;
		temp->next = topitem; //Sets the new node next to the most previous top item.
		topitem = temp; //Sets the top item as the temp node.
	}
}

int Recursion::Top()
{
	if (!(IsEmpty()))
	{
		return topitem->data;
	}
	else
		return -404;
}