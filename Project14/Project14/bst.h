/********************************************************************
	File: BST.h
	Des:  This file contains a partial class definition for a Binary Search
	Tree (A)bstract (D)ata (T)ype.


	Author: Coach Rags
********************************************************************/
#include <string>
using namespace std;

class Node
{
public:
	string Key; //ordering element
	Node* Lt;
	Node* Rt;

	Node(string);
};

//Class definition for a Binary Search Tree
class BST
{
public:

	//constructor
	BST();

	//add a node to the BST
	void Insert(string);

	//print out the entire list
	void Print();

private:

	//helper functions
	void PrintInorder(Node*);

	Node* Root;
};

