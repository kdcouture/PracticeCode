#include <iostream>

using namespace std;

typedef struct BinaryTreeNodeTag		// Binary Tree Structure
{
	int Data;							// Node data
	struct BinaryTreeNodeTag* Left;		// Left Child
	struct BinaryTreeNodeTag* Right;	// Right Child
}BTNode;

// Prototypes

BTNode* createRoot(int data);
int insertNode(BTNode* root, int data);
BTNode* search(BTNode* root, int data);
int deleteNode(BTNode* root, int data);
int height(BTNode* current, int count);
void printPreOrder(BTNode* current);
void printInOrder(BTNode* current);
void printPostOrder(BTNode* current);


// Main

int main() {

	BTNode* testTree = createRoot(7);
	insertNode(testTree, 3);
	insertNode(testTree, 9);
	insertNode(testTree, 1);
	insertNode(testTree, 4);

	cout << "The height is: " << height(testTree, 0) << endl;
	cout << "Pre-Order: ";
	printPreOrder(testTree);
	cout << "\nIn-Order: ";
	printInOrder(testTree);
	cout << "\nPost-Order: ";
	printPostOrder(testTree);
	cout << endl;

	system("pause");
	return 0;
}


// Functions

/*
	@func createRoot
	@param int data
	@ret BTNode *newRoot
	@desc Returns created node with the given data.
*/
BTNode* createRoot(int data) {
	BTNode* newRoot = new BTNode;
	newRoot->Data = data;
	newRoot->Left = NULL;
	newRoot->Right = NULL;
	cout << "Created a new Tree!" << endl;
	return newRoot;
}

/*
	@func insertNode
	@param BTNode* root int data
	@ret int DEBUG
	@desc Inserts a node into the tree, returns used for debuging.
*/
int insertNode(BTNode* root, int data) {
	// Create the new node.
	BTNode* newNode = new BTNode;
	newNode->Data = data;
	newNode->Left = NULL;
	newNode->Right = NULL;

	// Place the node in the tree
	BTNode* current = root;		// use an iterate to travers the tree

	while (current != NULL)

	if (data <= current->Data) { // Move Left
		// Check for Null, if yes add the insert the new node
		if (current->Left == NULL) {
			current->Left = newNode;
			return 1;
		}
		// Not null, continue traversing
		else {
			current = current->Left;
		}
	}

	else {	// Move Right
		// Check for Null, if yes add the insert the new node
		if (current->Right == NULL) {
			current->Right = newNode;
			return 2;
		}
		// Not null, continue traversing
		else {
			current = current->Right;
		}
	}
	return 3;
}

/*
	@func seach
	@param BTNode* root int data
	@ret BTNode* foundNode
	@desc Searches tree for the given data and returns the first node
	that contains the desired data.

*/
BTNode* search(BTNode* root, int data) {
	// Create iterator
	BTNode* current = root;

	// Search thorugh array
	while (current != NULL) {
		if (data < current->Data) {	// Check Left
			current = current->Left;
		}
		else if (data > current->Data) { // Check Right
			current = current->Right;
		}
		else if (data = current->Data) { // Found and return
			return current;
		}
	}
	return NULL; // Not found, reutrn NULL
}

/*
	@func deletNode
	@param BTNode* root int data
	@ret int DEBUG
	@desc Seaches for a given value and then deletes the first node
	containing the value. If only the root exists, it is set to NULL.
*/
int deleteNode(BTNode* root, int data) {

	// Single element tree edge case
	if (root->Left == NULL && root->Right == NULL) {
		if (root->Data == data) {
			root = NULL;
		}
		else return 0;
	}

	// Create iterator
	BTNode* current = root;
	// Create parent tracker
	BTNode* parentNode = root;

	// Seach thorugh array keeping track of parent nodes.
	while (current != NULL) {
		if (data < current->Data) {	// Check Left
			parentNode = current;
			current = current->Left;
			if (current->Data = data) {	// Found left
				parentNode->Left = current->Left;
				delete current;
				return 1;
			}
		}
		else if (data > current->Data) {	// Check Right
			parentNode = current;
			current = current->Right;
			if (current->Data = data) {	// Found right
				parentNode->Right = current->Right;
				delete current;
				return 2;
			}
		}

	}
	return 3;
}

/*
	@func height
	@param BTNode* Current int count
	@ret int treeHeight
	@desc Makes recursive calls to check all paths to see 
	which is the longest path.
*/
int height(BTNode* current, int count) {
	// Base case
	if (current == NULL) {
		return count;
	}
	// Root/Internal/Leaf case
	else {
		int leftcount;
		int rightcount;
		count++;
		leftcount = height(current->Left, count);	// Recursive call
		rightcount = height(current->Right, count);	// Recursive call
		if (leftcount >= rightcount) {
			return leftcount;
		}
		else {
			return rightcount;
		}
	}
}

/*
	@func printPreOrder
	@param BTNode* current
	@ret VOID
	@desc Print the tree in Pre-Order.
*/
void printPreOrder(BTNode* current) {
	// Pre-Order traversal
	if (current == NULL) {
		return;
	}
	cout << current->Data << " ";
	printPreOrder(current->Left);
	printPreOrder(current->Right);
}

/*
	@func printInOrder
	@param BTNode* current
	@ret VOID
	@desc Print the tree In-Order.
*/
void printInOrder(BTNode* current) {
	// Pre-Order traversal
	if (current == NULL) {
		return;
	}
	printPreOrder(current->Left);
	cout << current->Data << " ";
	printPreOrder(current->Right);
}

/*
	@func printPostOrder
	@param BTNode* current
	@ret VOID
	@desc Prints the given tree in Post-Order.
*/
void printPostOrder(BTNode* current) {
	// Pre-Order traversal
	if (current == NULL) {
		return;
	}
	printPreOrder(current->Left);
	printPreOrder(current->Right);
	cout << current->Data << " ";
}