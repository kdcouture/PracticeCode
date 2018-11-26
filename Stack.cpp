/*
Kevin Couture

Stack

@desc Contains the stack structure and
all related functions. Tests are 
preformed in the main. 

Stack is implemented as a linked list.

*/
#include <iostream>

using namespace std;

// Stack Node struct
typedef struct StackNodeTag
{
	int Data;
	struct StackNodeTag* next;

}StackNode;

// Stack Struct
typedef struct StackTag {
	struct StackNodeTag* top;
	int count;
}Stack;

// Prototypes

Stack* CreateStack();
void Push(Stack* s, int data);
int Pop(Stack* s);
int StackHeight(Stack* s);
int Peek(Stack* s);
void PrintStack(Stack* s);


// Main
int main() {

	Stack* ourStack = CreateStack();
	Push(ourStack, 1);
	Push(ourStack, 2);
	Push(ourStack, 3);
	PrintStack(ourStack);
	cout << "Pop: " << Pop(ourStack) << endl;
	PrintStack(ourStack);
	cout << StackHeight(ourStack) << endl;

	system("pause");
	return 0;
}

/*
@func CreatStack
@param VOID
@ret Stack* s
@desc Creates a pointer to an empty stack.
*/
Stack* CreateStack() {
	Stack* s = new Stack;
	s->count = 0;
	s->top = NULL;
	return s;
}

/*
@func Push
@param Stack*s, int data
@ret VOID
@desc Places the given data on top of the given stack.
*/
void Push(Stack* s, int data) {
	// Create new node with parameter data
	StackNode* newNode = new StackNode;
	newNode->Data = data;
	newNode->next = s->top;
	// Replace stack top with new top
	s->top = newNode;
	// Increment count;
	s->count++;
}


/*
@func Pop
@param Stack* s
@ret int data
@desc Removes the top element from stack while grabing its data.
*/
int Pop(Stack* s) {
	// Store data in a temporary location
	int temp = s->top->Data;
	// Store the node to remove in a temporary location
	StackNode* toRemove = s->top;
	// Set the next element as the top of the stack
	s->top = s->top->next;
	// Free memory
	delete toRemove;
	toRemove = NULL;
	// Decrement count
	s->count--;
	// Return original top data
	return temp;
}

/*
@func StackHeight
@param Stack* s
@ret int count
@desc Returns the Stack element count.
*/
int StackHeight(Stack* s) {
	// Returns counter data
	return s->count;
}

/*
@func Peek
@param Stack* s
@ret int top of stack data
@dec Checks the top value of the stack without modifiying stack.
*/
int Peek(Stack* s)  {
	return s->top->Data;
}

/*
@func PrintStack
@param Stack* s
@ret VOID
@desc Prints the given Stack's current elements from top to bottom.
*/
void PrintStack(Stack* s) {
	// Iterator
	StackNode* current = s->top;
	cout << "The current Stack: ";
	while (current != NULL) {
		cout << current->Data << " ";
		current = current->next;
	}
	cout << endl;
}