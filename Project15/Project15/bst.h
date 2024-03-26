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

	//destructor
	~BST();

	//add a node to the BST
	void Insert(string);

	//print out the entire list
	void Print();

	//delete a node from the BST
	void Delete(string); // ******** Not DONE // think works

private:

	//helper function for public Print function
	void PrintInorder(Node*);

	//helper function for public Delete function, first parameter is a pointer to the 
	//node to delete, second parameter is a pointer to the parent of node to be deleted
	void DeleteLeaf(Node*, Node*); // ******************* NOT DONE // think works

	//helper function for public Delete function, first parameter is a pointer to the 
	//node to delete, second parameter is a pointer to the parent of node to be deleted
	void DeleteOneChild(Node*, Node*); // ****************** NOT DONE // tink works

	//helper function for public Delete function, first parameter is a pointer to the 
	//node to delete only
	void DeleteTwoChild(Node*); // ********************* NOT DONE // think works

	//helper function for Destructor - utilizes a postorder traversal
	void DeletePostOrder(Node*); // *********************** NOT DONE // what is this?

	//void FindParent(Node*); // find the parent of a node

	Node* Root;
};
