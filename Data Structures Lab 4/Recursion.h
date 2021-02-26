/*Racy Halterman
* Data Structures Spring 2021
* Due: March 3rd
* Lab 3: Recursion
* A general stack program, but allows the user to reverse the order of the stack.
*/
#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
/*I had created the Recursion class before I knew we were just supposed to copy our stack.h and stack.cpp over.
* So, the name remains Recursion.*/
class Recursion
{
private:
	struct node
	{
		int data; //Holds the data of the node.
		node* next; //Holds the value of the next node.
	};

	node* topitem;

public:

	/*
	*Preconditions - Requires the node struct is correct. Iostream as well.
	*Postconditions - Constructs the stack.
	*/
	Recursion();

	/*
	*Preconditions - Requires Pop and IsEmpty are loaded. Also iostream.
	*Postconditions - Destroys the stack.
	*/
	~Recursion();

	/*
	*Preconditions - Requires iostream and the node struct, and the node topitem.
	*Postconditions - Returns true if the topitem is null, false if it doesn't.
	*/
	bool IsEmpty();

	/*
	*Preconditions - Requires the node struct and iostream.
	*Postconditions - Returns true if the stack has hit max capacity in the computers memory. False if otherwise.
	*/
	bool IsFull();

	/*
	*Preconditions - Requires node struct, topitem, and iostream.
	*Postconditions - Returns the new top value of the stack after destroying the top item.
	*/
	int Pop();

	/*
	*Preconditions - Requires IsFull, iostream, node, and topitem.
	*Postconditions - Places the number inputted on top of the stack.
	*/
	void Push(int value);

	/*
	*Preconditions - Iostream, node struct, and topitem.
	*Postconditions - Returns the data within the topitem of the stack.
	*/
	int Top();
};

#endif //RECURSION_H