//Test app for the BST functions Insert, Delete, Print, Destructor

#include <iostream>
#include "bst.h"
#include <string>
using namespace std;

int main()
{
	//create BST wordlist object
	BST wordlist;

	//insert several states and rankings into the bst
	wordlist.Insert("Georgia");
	wordlist.Insert("New York");
	wordlist.Insert("California");
	wordlist.Insert("Arkansas");
	wordlist.Insert("Minnesota");
	wordlist.Insert("Alaska");
	wordlist.Insert("Missouri");
	wordlist.Insert("Delaware");
	wordlist.Insert("Rhode Island");


	//proof of concept - print the states in an orderly fashion
	wordlist.Print();

	//ask for a value to delete - check the four cases
	string valueToDelete;
	getline(cin, valueToDelete);
	wordlist.Delete(valueToDelete);

	//proof of concept - print the states after deletion or no deletion if valueToDelete not found
	cout << "AFTER DELETION - " << valueToDelete << endl;
	wordlist.Print();

	//destructor implicity called upon program exit - print value of each node as it is deleted.
	cout << "CALLING DESTRUCTOR" << endl;
	return 0;
}