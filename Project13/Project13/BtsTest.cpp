//Test app for the BST functions Insert and Print

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
	wordlist.Insert("Louisiana");


	//proof of concept - print the states in an orderly fashion
	wordlist.Print();

	return 0;
}