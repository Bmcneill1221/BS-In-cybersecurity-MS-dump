/********************************************************************
This is the implementation file (Insert and Print) for a binary search tree.
Lab 4.13
********************************************************************/

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
			if (newNode->Key <= current->Key)
				current = current->Lt;
			else
				current = current->Rt;
		}

		//link node to parent
		if (newNode->Key <= parent->Key)
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



///* This file contains the code for the necessary constructors, along with Insert and Print functionality */
//#include "bst.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//Node::Node(string k) {
//
//	Key = k;
//	Lt = Rt = nullptr;
//
//}
//
//
//BST::BST() {
//
//	Root = nullptr;
//	//Lt = nullptr;
//	//Rt = nullptr;
//}
//
//
//void BST::Insert(string ins) {
//
//	Node* newNode = new Node(ins);
//
//	if (newNode == nullptr) {
//		cout << "memeory alocation error";
//		exit(EXIT_FAILURE);
//
//
//	}
//
//	if (Root != nullptr) {
//		Node* C = Root;
//		Node* P = nullptr;
//
//		while (C != nullptr) {
//			P = C;
//			if (newNode->Key < C->Key)
//				C = C->Lt;
//			else
//				C = C->Rt;
//		}
//		if (P->Key > newNode->Key)
//			P->Lt = newNode;
//		else
//			P->Rt = newNode;
//
//	}
//	else {
//		Root = newNode;
//	}
//
//	cout << newNode->Key << " inserted" << endl;
//
//	
//}
//
//
//void BST::PrintInorder(Node* P) {
//
//	Node* prevOut = nullptr;
//	P = Root;
//	bool out = false;
//	bool lft = true;
//
//	while (P != NULL)
//	{
//		while (/*out != true &&*/ P->Lt != nullptr || P->Rt != nullptr) // removed P != nullptr || 
//		{
//
//			if (P->Lt != prevOut && P->Lt != nullptr && out != true && lft != false)
//			{
//				P = P->Lt;
//			}
//			if (P->Lt == nullptr || P->Lt == prevOut) {
//				cout << P->Key << endl;
//
//				if (P->Key == Root->Key) {
//
//					P = Root->Rt;
//					while (P != NULL)
//					{
//
//
//						if (P->Lt != prevOut && P->Lt != nullptr && out != true && lft != false)
//						{
//							P = P->Lt;
//						}
//						if (Root->Rt == prevOut){
//								P = NULL;
//								return;
//							}
//						if (P->Lt == nullptr || P->Lt == prevOut) {
//							cout << P->Key << endl;
//							
//							
//							prevOut = P;
//							P = Root->Rt;
//						}
//					}
//					/*out = true;
//					lft = false;*/ //old
//
//				}
//				prevOut = P;
//				P = Root;
//			}
//			/*else if (P->Rt != prevOut && P->Rt != nullptr) {
//
//				P = P->Rt;
//				out = false;
//				lft = true;
//
//					if (P->Lt == nullptr || P->Lt == prevOut) {
//						cout << P->Key << endl;
//						if (P == Root)
//							out = true;
//						prevOut = P;
//						P = Root;
//					}
//
//				else out == false;
//
//			}*/
//			////out = 0;
//
//
//			//if (P == Root) {
//
//			//	while (out != true && P->Lt != nullptr || P->Rt != nullptr) // removed P != nullptr || 
//			//	{
//
//			//		if (P->Lt != nullptr && P->Lt != prevOut) 
//			//		{
//			//			P = P->Lt;
//			//		}
//			//		else if (P->Rt != nullptr && P->Rt != prevOut) {
//			//			P = P->Rt;
//			//		}
//			//		else
//			//		{
//			//			out = true;
//			//		}
//
//			//	}
//			//	out = 0;
//			//	if (P != prevOut) {
//			//		cout << P->Key << endl;
//			//		prevOut = P;
//			//		P = Root;
//			//	}
//			//	
//
//			//}
//
//			////P = NULL; where does this go?
//
//		}
//
//
//		//while (P != NULL)
//		//{
//		//	while (out!=true && P->Lt != nullptr || P->Rt != nullptr) // removed P != nullptr || 
//		//	{
//
//		//		if (P->Lt != nullptr && P->Lt != prevOut) 
//		//		{
//		//			P = P->Lt;
//		//		}
//		//		else if (P->Rt != nullptr && P->Rt != prevOut) {
//		//				P = P->Rt;
//		//		}
//		//		else
//		//		{
//		//			out = true;
//		//		}
//
//		//	}
//		//	out = 0;
//		//	if (P != prevOut) {
//		//		cout << P->Key << endl;
//		//		prevOut = P;
//		//		P = Root;
//		//	}
//
//		//	//if (P == Root) {
//
//		//	//	while (out != true && P->Lt != nullptr || P->Rt != nullptr) // removed P != nullptr || 
//		//	//	{
//
//		//	//		if (P->Lt != nullptr && P->Lt != prevOut) 
//		//	//		{
//		//	//			P = P->Lt;
//		//	//		}
//		//	//		else if (P->Rt != nullptr && P->Rt != prevOut) {
//		//	//			P = P->Rt;
//		//	//		}
//		//	//		else
//		//	//		{
//		//	//			out = true;
//		//	//		}
//
//		//	//	}
//		//	//	out = 0;
//		//	//	if (P != prevOut) {
//		//	//		cout << P->Key << endl;
//		//	//		prevOut = P;
//		//	//		P = Root;
//		//	//	}
//		//	//	
//
//		//	//}
//
//		//	////P = NULL; where does this go?
//
//		//}
//
//
//
//
//
//	//Node* cur = PTR;
//	////Node* prev2 = nullptr;
//	//Node* prev = nullptr;
//
//	////Do I need this if statemane ? if (nullptr == cur->Key) {// deos it have to be ->Key
//
//	//	while (cur != nullptr)
//	//	{
//	//		//prev2 = prev;
//	//		prev = cur;
//	//		if (cur->Lt != nullptr)
//	//			cur = cur->Lt;
//
//	//		else {
//	//			cur = cur->Rt;
//	//		}
//
//	//	}
//	//	if(cur != nullptr){
//	//		cout << cur->Key << endl;
//	//		if (cur != prev)
//	//			cout << prev->Key << endl;
//	//		cout << PTR << endl;
//	//	}
//	//	cur = PTR->Rt;
//
//	//	while (cur != nullptr)
//	//	{
//	//		//prev2 = prev;
//	//		prev = cur;
//	//		if (cur->Lt != nullptr)
//	//			cur = cur->Lt;
//
//	//		else {
//	//			cur = cur->Rt;
//	//		}
//
//	//	}
//
//
//	}
//}
//
//
//void BST::Print() {
//	PrintInorder(Root);
//}