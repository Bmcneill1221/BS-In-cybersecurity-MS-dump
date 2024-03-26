/********************************************************************
This is the implementation file (Insert and Print) for a binary search tree.
Lab 4.13
********************************************************************/

//destructor needed????

#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

Node::Node(string k)
{
	Key = k;
	Lt = Rt = nullptr;
}

/************* Constructor **************************/

BST::BST()
{
	Root = nullptr;
}

/**** Insert node to tree Iteratively (loop) using trailer (parent) technique ********/

void BST::Insert(string k)
{
	//get dynamic memory, if unable return message to client
	Node* newNode = new Node(k);
	if (newNode == nullptr)
	{
		cout << "Error allocating memory" << endl;
		return;
	}

	//insert node in tree, if tree empty this becomes the root
	if (Root == nullptr)
		Root = newNode;
	else
	{
		//tree not empty, find insertion point and insert as leaf
		Node* current = Root;
		Node* parent = nullptr;

		//find insertion spot, parent will point to insertion node
		while (current != nullptr)
		{
			parent = current;
			if (newNode->Key == current->Key)  // remove <
				current = current->Lt;
			else
				current = current->Rt;
		}

		//link node to parent
		if (newNode->Key == parent->Key)   // remove <
			parent->Lt = newNode;
		else
			parent->Rt = newNode;

	}
	//confirmation
	cout << newNode->Key << " inserted" << endl;
}

/**** Insert a node to the tree Iteratively (loop) w/o a trailer (parent) ****/

//void BST::Insert(string k)
//{
//	//get dynamic memory, if unable return message to client
//	Node* newNode = new Node(k);
//	if (newNode == nullptr)
//	{
//		cout << "Error allocating memory" << endl;
//		return;
//	}
//
//	//insert node in tree, if tree empty this becomes the root
//	if (Root == nullptr)
//		Root = newNode;
//	else
//	{
//		//tree not empty, find insertion point and insert as leaf
//		Node* current = Root;
//
//		//find insertion spot, see if Lt/Rt pointer null, if so, attach to current
//		while (current != nullptr)
//		{
//			//does new value belong on left of current node?
//			if (newNode->Key < current->Key)
//				//can I attach it here (Lt) or keep searching?
//				if (current->Lt == nullptr)
//				{
//					current->Lt = newNode;
//					current = nullptr;
//				}
//				else
//					current = current->Lt;
//			else
//				//can I attach here (Rt) or keep searching?
//				if (current->Rt == nullptr)
//				{
//					current->Rt = newNode;
//					current = nullptr;
//				}
//				else
//					current = current->Rt;
//		}
//	}
//	//confirmation
//	cout << newNode->Key << " inserted" << endl;
//}

/****** Insert a node to the tree recursively using a helper function ********/

//void BST::Insert(string k)
//{
//	Node* newNode = new Node(k);
//	if (newNode == nullptr)
//	{
//		cout << "Error allocating memory" << endl;
//		return;
//	}
//
//	if (Root == nullptr)
//		Root = newNode;
//	else
//		recInsert(newNode, Root);
//
//	//confirmation
//	cout << newNode->Key << " inserted" << endl;
//}
//
////Helper function for recursive insert
//void BST::recInsert(Node* newNode, Node* cur)
//{
//	if (newNode->Key < cur->Key)
//	{
//		if (cur->Lt == nullptr)
//			cur->Lt = newNode;
//		else
//			recInsert(newNode, cur->Lt);
//	}
//	else
//	{
//		if (cur->Rt == nullptr)
//			cur->Rt = newNode;
//		else
//			recInsert(newNode, cur->Rt);
//	}
//}

void BST::PrintInorder(Node* current)
{
	//LVR
	if (current != nullptr)
	{
		PrintInorder(current->Lt);
		cout << current->Key << endl;
		PrintInorder(current->Rt);
	}
}

/*********** Print out the entire tree ***************/

void BST::Print()
{
	PrintInorder(Root);
}

//void BST::FindParent(Node* child) { // was Node* child
//
//	//Node* child = nullptr; // new
//	//child->Key= chld; // new
//	Node* current = Root;
//	Node* parent = nullptr;
//
//	while (current != nullptr)
//	{
//		if (current->Lt != child && current->Rt != child)
//		{
//
//			//parent = current;
//			if (child->Key == current->Key)  
//				current = current->Lt;
//			else
//				current = current->Rt;
//
//		}
//	}
//	//return parent; //Do I need this?
//
//}

void BST::Delete(string dataToDel) {

	Node* del = nullptr;
	del->Key=dataToDel;
	Node* child = del;

	Node* current = Root;
	Node* parent = nullptr;

	while (current != nullptr)
	{
		if (current->Lt != child && current->Rt != child)
		{

			//parent = current;
			if (child->Key == current->Key)
				current = current->Lt;
			else
				current = current->Rt;

		}
	}
	
	

// tralier. first is del node. second parent of del node.
	if (del->Rt == nullptr && del->Lt == nullptr) 
		DeleteLeaf(del,child ); //FindParent(del)

//first is del node. 2nd is parent of del
	if (del->Lt != nullptr || del->Rt != nullptr)
		DeleteOneChild(del, child ); //was FindParent(del)

	//first is del node. 2nd is parent of del
	if (del->Lt != nullptr && del->Rt != nullptr)
		DeleteTwoChild(del);

}

void BST::DeleteLeaf(Node* del, Node* Parent) {

	//check for root
	if (Parent == NULL)
		Root = NULL;
	else
		if (Parent->Lt == del)
			Parent->Lt = NULL;
		else
			Parent->Rt = NULL;
	delete del;

}

void BST::DeleteOneChild(Node* del, Node* parent) {

	Node* saveptr = nullptr;
	if (del->Lt == nullptr)
		saveptr = del->Rt;
	else
		saveptr = del->Lt;

	/*if (parent == nullptr)
		Root = nullptr;
	else
	{*/
		if (parent->Rt == del)
			parent->Rt = saveptr;
		else
		{
			parent->Lt = saveptr;
		}

	//}

	delete del;

}

void BST::DeleteTwoChild(Node* del) {

	Node* savePtrL = del->Lt;
	Node* savePtrR = del->Rt;
	Node* newLeft = savePtrL;
	bool out =0;
	while (out != 1)
	{
		if (newLeft->Rt != nullptr)
			newLeft = newLeft->Rt;

		else
		{
			newLeft->Lt = savePtrL;
			newLeft->Rt = savePtrR;
			out = 1;
		}

	}



}

void BST::DeletePostOrder(Node*) {


}