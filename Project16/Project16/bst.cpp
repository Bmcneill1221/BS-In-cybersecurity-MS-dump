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

BST::~BST()
{
	DeletePostOrder(Root);
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
			if (newNode->Key < current->Key)  // remove <
				current = current->Lt;
			else
				current = current->Rt;
		}

		//link node to parent
		if (newNode->Key < parent->Key)   // remove <
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

Node* BST::FindParent(Node* child) {

	Node* current = Root;
	//Node* parent = nullptr;
	if (child->Key == Root->Key)
		return current;

	//if ((current->Lt != nullptr && current->Lt->Key == child->Key) || (current->Rt != nullptr && current->Rt->Key == child->Key)) {
	//	return current;
	//}

	while (current->Lt != child && current->Rt != child)
	{

		//parent = current;
		if (child->Key <= current->Key)
			current = current->Lt;
		else
			current = current->Rt;

	}
	return current; //Do I need this?

}

Node* BST::FindNode(string Find) {

	Node* current = Root;
	//Node* parent = nullptr;

	while (current->Key != Find)
	{
		if (current->Key != Find) // was current->Lt != Find && current->Rt != Find
		{

			//parent = current;
			if (Find < current->Key)
				current = current->Lt;
			else
				current = current->Rt;
			if (current == nullptr) {
				cout << Find << " not found in tree" << endl;
				return current;
			}

		}
		if (current->Key == Find)
			return current;
	}
	return current; //Do I need this?

}



void BST::Delete(string dataToDel) {



	Node* del = FindNode(dataToDel);
	/*del = Root;
	del->Key = dataToDel;*/

	if (del != nullptr) {

		// tralier. first is del node. second parent of del node.
		if (del->Rt == nullptr && del->Lt == nullptr)
			DeleteLeaf(del, FindParent(del));

		//first is del node. 2nd is parent of del
		else if (del->Lt != nullptr && del->Rt != nullptr)
			DeleteTwoChild(del);

		//first is del node. 2nd is parent of del
		else if (del->Lt != nullptr || del->Rt != nullptr)
			DeleteOneChild(del, FindParent(del));
	}

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

	if (parent == nullptr)
		Root = nullptr;
	else
	{
		if (parent->Rt == del)
			parent->Rt = saveptr;
		else
		{
			parent->Lt = saveptr;
		}

	}

	delete del;

}

void BST::DeleteTwoChild(Node* del) {

	if (del == Root) {
		Node* newPtr = del->Lt;
		Node* parent = newPtr;

		while (newPtr->Rt != nullptr)
			newPtr = newPtr->Rt;

		del->Key = newPtr->Key;
		parent->Rt = nullptr;
		delete newPtr;
	}
	else
	{
		Node* newPtr = del->Lt;
		while (newPtr->Rt != nullptr)
		{
			newPtr = newPtr->Rt;
		}

		if (newPtr->Lt == nullptr) {
			del->Key = newPtr->Key;
			DeleteLeaf(newPtr, FindParent(newPtr));
		}
		else
		{
			del->Key = newPtr->Key;
			DeleteOneChild(newPtr, FindParent(newPtr));

		}

	}
	

}

void BST::DeletePostOrder(Node* bel) {

	Node* curr = Root;
	Node* parent = Root;

	while (Root != nullptr) {

		while (curr->Lt != nullptr || curr->Rt != nullptr)
		{
			parent = curr;


			if (curr->Lt == nullptr) {
				curr = curr->Rt;
			}
			else
			{
				curr = curr->Lt;
			}

		}

		if (parent->Lt == curr)
			parent->Lt = nullptr;
		else
		{
			parent->Rt = nullptr;
		}

		if (curr == Root) {
			Root = nullptr;
		}

		if (curr->Lt == nullptr && curr->Rt == nullptr) {
			cout << curr->Key << " deleted" << endl;
			delete curr;
			curr = Root;
		}


	}

}