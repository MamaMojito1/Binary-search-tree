#include "BST.cpp"

using namespace std;

int main()
{
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };

	BST myTree;
	int input = 0;

	cout << "Printing the tree in order" << endl;
	cout << "Before adding numbers" << endl;

	myTree.PrintInOrder();

	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order" << endl;
	cout << "After adding numbers" << endl;

	myTree.PrintInOrder();

	cout << endl;

	cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;

	cout << "Enter a key value to delete. Enter -1 to stop the process" << endl;


	while (input != -1)
	{
		cout << "Delete node: ";
		cin >> input;
		{
			if (input != -1)
			{
				cout << endl;
				myTree.RemoveNode(input);
				myTree.PrintInOrder();
				cout << endl;
			}
		}
	}


	cout << endl;

	return 0;
}