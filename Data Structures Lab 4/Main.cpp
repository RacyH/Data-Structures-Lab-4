/*Racy Halterman
* Data Structures Spring 2021
* Due: March 3rd
* Lab 3: Recursion
* A general stack program, but allows the user to reverse the order of the stack.
*/

#include "Recursion.h"
using namespace std;

void intro();
void menu();
void additem();
void deleteitem();
void viewitem();
void reverse();
int reversestack();

Recursion slist, rlist, templist;

int main()
{

	intro();
	menu();//sure is passed through, i had it in an earlier implementation, but kept it so that if I wanted to mess around with it a bit more, I could.
	return 0;
}

/*
*Preconditions - Requires iostream and std libraries are loaded. Also must have Recursion.h loaded. (iostream is in Stack.h)
*Postconditions - Ouputs a message so that the user knows what the program does.
*/
void intro()//Just displays the intro to the project for the user.
{
	char e;
	system("cls");
	cout << "This is a simple stack memory program.\n";
	cout << "You will be able add and remove items only from the top of the stack.\n";
	cout << "Items are limited to integers.\n";
	cout << "You will only be able to view the top item in the stack.\n";
	cout << "You will be able to add as many items as the system will allow, which may be different for each computer.\n";
	cout << "You will also be able to reverse the order of the stack.\n";
	cout << "Press E, then enter, to exit this introduction and go into the menu.\n";
	cin >> e;
}

/*
*Preconditions - Requires Recursion.h be loaded, along with all of it's components. Requires a bool to be passed through.
* Also requires that all of the functions work properly.
*Postconditions - Sends the user to complete function, until the user decides to exit.
*/
void menu()
{
	char menuitem;
	bool ex = true;

	while (ex == true)
	{
		system("cls"); //clears the screen.

		cout << "Press the letter corresponding to the menu item that you would like to access.\n";
		cout << "Add item.\tA\n";
		cout << "Delete item.\tD\n";
		cout << "View item.\tV\n";
		cout << "Reverse stack.\tR\n";
		cout << "Exit program.\tE\n";
		cin >> menuitem;
		switch (menuitem)//simple switch of the above menu items, and the users input.
		{
		case 'A': additem();
			break;
		case 'D': deleteitem();
			break;
		case 'V': viewitem();
			break;
		case 'E': ex = false;
			break; //These are in both capital and lowercase letters, just in case the user doesn't want to use capitals.
		case 'a': additem();
			break;
		case 'd': deleteitem();
			break;
		case 'v': viewitem();
			break;
		case 'R': reverse();
			break;
		case 'r': reverse();
			break;
		case 'e': ex = false;
			break;
		default: cout << "Invalid input. Please try again.\n";
			break;
		}
	}
}

/*
*Preconditions - Requires Stack::Push() is functioning, and that std and iostream are loaded. Recursion.h is required.
*Postconditions - Adds the inputted item on top of the stack using the Push() function.
* NOTE!!Can only add integers.
*/
void additem()//Do not try and push the number -404.
{
	int item;
	system("cls");
	cout << "What item do you want to add to the stack?\n";//simple function, asks for the item that they want to be added to the stack, then adds it
	cin >> item;
	slist.Push(item);
}

/*
*Preconditions - Requires iostream and std are loaded. Requires Stack.h.
*Postconditions - Removes the top item from the stack using the Pop() function.
*/
void deleteitem()
{
	char leave;
	cout << slist.Pop() << endl;
	cout << "Press any letter, followed by enter, to exit back to the menu.\n";
	cin >> leave;
}

/*
*Preconditions - Std and iostream are loaded. Requires Recursion.h.
*Postconditions - Outputs the item that is on top of the stack.
*/
void viewitem()
{
	char leave;
	system("cls");
	if (slist.Top() != -404)
	{
		cout << slist.Top() << endl;
		cout << "Press any letter, then enter, to exit back to the menu.\n";
		cin >> leave;
	}
	else
	{
		cout << "Error: " << slist.Top() << "- Not found.\n"; //Error: -404- not found.
		cout << "Press any letter, then enter, to exit back to the menu.\n";
		cin >> leave;
	}
}

/*
*Preconditions - Std and iostream, iostream is in Recursion.h, so that needs to be loaded. reversestack() needs to work correctly.
*Postconditions - Reverses the original stack, and resets the templist and rlist as empty again.
*/
void reverse()
{
	char exit;
	reversestack();

	templist = rlist;
	rlist = slist;
	slist = templist; //These three lines of code make it so that the original list, slist, is now equal to the rlist, and vice-versa.
	cout << "The list has been successfully reversed.\n";
	cout << "Press any letter, followed by enter, to exit back to the menu.\n";
	cin >> exit; //So the user can see that the reverse was successful.
}

/*
*Preconditions - Need Recursion.h to be loaded. Std and iostream.
*Postconditions - Makes a deep copy of slist into rlist, but reverses the order that the items were in.
*/
int reversestack()//Reverses the stack
{
	if (slist.IsEmpty())//If the list becomes empty, returns as 0.
	{
		return 0;
	}
	else
	{
		int temp = slist.Pop();//Pops top item off.
		rlist.Push(temp);//Pushes most recent item to the top of the list, so that the bottom of the slist is now the top of the rlist.
		reversestack();//Calls reversestack() again, does this until it becomes empty, then each of the ones that have been called will start to return digits

		return 1;//Returns once the list is empty, and the bottom of the old list is at the top of the new one.
	}
}
//What happened here is that it called the reversestack inside of reversestack, until the list becomes empty.