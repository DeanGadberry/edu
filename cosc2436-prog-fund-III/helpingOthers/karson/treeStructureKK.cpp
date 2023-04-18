#include <iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class IntBinaryTree {
private:
	struct TreeNode
	{
		int value;           // The value in the node
		TreeNode * left;   // Pointer to left child node
		TreeNode * right;  // Pointer to right child node
	};

	TreeNode * root;       // Pointer to the root node
	
	void insert(TreeNode*& nodePtr, TreeNode*& newNode)
	{
		if (nodePtr == nullptr)
			nodePtr = newNode;  // Insert the node.
		else if (newNode->value < nodePtr->value)
			insert(nodePtr->left, newNode); // Search the left branch.
		else
			insert(nodePtr->right, newNode); // Search the right branch.
	}
	
	void displayPreOrder(TreeNode* nodePtr) const
	{
		if (nodePtr)
		{
			cout << nodePtr->value << endl;
			displayPreOrder(nodePtr->left);
			displayPreOrder(nodePtr->right);

		}
	}
public:
	// Constructor
	IntBinaryTree()
	{ root = nullptr; }

	void insertNode(int num)
	{
		TreeNode* newNode = nullptr;     // Pointer to a new node.

		// Create a new node and store num in it.
		newNode = new TreeNode;
		newNode->value = num;
		newNode->left = newNode->right = nullptr;

		// Insert the node.
		insert(root, newNode);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}
};


int main()
{	
	IntBinaryTree tree1;
	IntBinaryTree tree2;
	string input1;
	string input2;
	
	
	cout << "Enter tree 1: ";
	getline(cin, input1);
	
	stringstream ss(input1);
	
	auto start = istream_iterator<int>{ ss };
	auto end = istream_iterator<int>{ };
	vector<int>input11(start, end);

	for (int k = 0; k < input11.size(); k++)
	{
		tree1.insertNode(input11[k]);
	}
	
	
	cout << "Enter tree 2: ";
	getline(cin, input2);

	stringstream pp(input2);

	auto startt = istream_iterator<int>{ pp };
	auto endd = istream_iterator<int>{ };
	vector<int>input22(startt, endd);

	for (int k = 0; k < input22.size(); k++)
	{
		tree2.insertNode(input22[k]);
	}
	
	
	



	tree1.displayPreOrder();
	cout << endl;
	tree2.displayPreOrder();
	
	
}
