#include "BST.h"
#include <iostream>
#include <cstdlib>

void BST::AddLeafPrivate(int key, node * ptr)
{
	if (root == NULL) // means our tree is empty
	{
		root = CreateLeaf(key);
	}
	else if (key < ptr->key)
	{
		if (ptr->left != NULL)
		{
			AddLeafPrivate(key, ptr->left);
		}
		else
		{
			ptr->left = CreateLeaf(key);
		}
	}

	else if (key > ptr->key)
	{
		if (ptr->right != NULL)
		{
			AddLeafPrivate(key, ptr->right);
		}
		else
		{
			ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		std::cout << "The key " << key << " has already been added to the tree" << std::endl;
	}

}

void BST::PrintInOrderPrivate(node * ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
		{
			PrintInOrderPrivate(ptr->left);
		}
		std::cout << ptr->key << " ";
		if (ptr->right != NULL)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		std::cout << "The tree is empty" << std::endl;
	}
}

BST::node * BST::ReturnNodePrivate(int key, node* ptr)
{
	if (ptr != NULL)
	{
		if (ptr->key == key)
		{
			return ptr;
		}
		else
		{
			if (key < ptr->key)
			{
				return ReturnNodePrivate(key, ptr->left);
			}
			else
			{
				return ReturnNodePrivate(key, ptr->right);
			}
		}
	}
	else
	{
		return nullptr;
	}
}

int BST::FindSmallestPrivate(node* ptr)
{
	if (root == NULL)
	{
		std::cout << "The tree is empty!" << std::endl;
		return -1000;
	}
	else
	{
		if (ptr->left != NULL)
		{
			return FindSmallestPrivate(ptr->left);
		}
		else
		{
			return ptr->key;
		}
	}
}

void BST::RemoveNodePrivate(int key, node * parent)
{
	if (root != NULL) // means its not empty
	{
		if (root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}

			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else
			{
				std::cout << "The key " << key << " was not found in the tree" << std::endl;
			}

		}
	}
	else // if the tree is empty
	{
		std::cout << "The tree is empty" << std::endl;
	}
}

void BST::RemoveRootMatch()
{
	if (root != NULL) // tree not empty
	{
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;

		// case 0 - 0 children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		// case 1 - 1 child 
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			std::cout << "The root node with key " << rootKey << " was deleted. ";
			std::cout << "The new root contains key " << root->key << std::endl;
		}

		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			std::cout << "The root node with key " << rootKey << " was deleted. ";
			std::cout << "The new root contains key " << root->key << std::endl;
		}

		// case 2 - root has 2 children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			std::cout << "The root key containing key " << rootKey;
			std::cout << " was overwritten with key " << root->key << std::endl;
		}

	}
	else
	{
		std::cout << "Can not remove root. The tree is empty" << std::endl;
	}
}

void BST::RemoveMatch(node * parent, node * match, bool left)
{
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;

		// case 0 - 0 children
		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			std::cout << "The node containing key " << matchKey << " was removed" << std::endl;
		}

		// case 1 - 1 child
		// for right
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			std::cout << "The node containing key " << matchKey << " was removed" << std::endl;
		}

		// for left
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			std::cout << "The node containing key " << matchKey << " was removed" << std::endl;
		}

		// case 2 - 2 children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}

	}
	else
	{
		std::cout << "Can not romove match. The tree is empty" << std::endl;
	}
}

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	RemoveSubTree(root);
}

BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::RemoveSubTree(node * ptr)
{
	if (ptr != NULL)
	{
		if (ptr->left != NULL)
		{
			RemoveSubTree(ptr->left);
		}
		if (ptr->right != NULL)
		{
			RemoveSubTree(ptr->right);
		}
		std::cout << "Deleting the node containing key " << ptr->key << std::endl;	
		delete ptr;
	}
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::PrintInOrder(void)
{
	PrintInOrderPrivate(root);
}

BST::node * BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

int BST::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
}

void BST::PrintChildren(int key)
{
	node* ptr = ReturnNode(key);

	if (ptr != NULL)
	{
		std::cout << "Parent Node = " << ptr->key << std::endl;

		ptr->left == NULL ?
		std::cout << "Left Child = NULL" << std::endl :
		std::cout << "Left Child = " << ptr->left->key << std::endl;

		ptr->right == NULL ?
		std::cout << "Right Child = NULL" << std::endl :
		std::cout << "Right Child = " << ptr->right->key << std::endl;

	}
	else
	{
		std::cout << "Key " << key << " is not in the tree" << std::endl;
 	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}
