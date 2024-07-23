#pragma once
class BST
{
private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;
	void AddLeafPrivate(int key, node* ptr);
	void PrintInOrderPrivate(node* ptr);
	node* ReturnNodePrivate(int key, node* ptr);
	int FindSmallestPrivate(node* ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	node* ReturnNode(int key);
	node* CreateLeaf(int key);
	void RemoveSubTree(node* ptr);

public:
	BST();
	~BST();
	void  AddLeaf(int key);
	void  PrintInOrder(void);
	int   ReturnRootKey();
	void  PrintChildren(int key);
	int   FindSmallest();
	void  RemoveNode(int key);
};

