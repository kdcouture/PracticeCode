/*
gStack.cpp

@desc This file contains the functionality of the generic stack class.

*/
#include "gStack.h"
#include <iostream>

// Constructor
template <class T>
gStack<T>::gStack()
{
	this->count = 0;
	this->top = NULL;
}

// Destructor
template <class T>
gStack<T>::~gStack()
{
	std::cout << "Stack Destroyed" << std::endl;
}

/*
@func Push
@param T data
@ret VOID
@desc Places the given generic data on top of the given stack.
*/
template <class T>
void gStack<T>::Push(T data) {
	// Create new node with parameter data
	struct stackNode<T>* newNode = new struct stackNode<T>;
	newNode->data = data;
	newNode->next = this->top;
	// Replace stack top with new top
	this->top = newNode;
	// Increment count;
	this->count++;
}

/*
@func Pop
@param VOID
@ret T data
@desc Removes the top element from stack while grabing its data.
*/
template <class T>
T gStack<T>::Pop() {
	// Store data in a temporary location
	T temp = this->top->data;
	// Store the node to remove in a temporary location
	struct stackNode<T>* toRemove = this->top;
	// Set the next element as the top of the stack
	this->top = this->top->next;
	// Free memory
	delete toRemove;
	toRemove = NULL;
	// Decrement count
	this->count--;
	// Return original top data
	return temp;
}

/*
@func StackHeight
@param VOID
@ret int count
@desc Returns the Stack element count.
*/
template <class T>
int gStack<T>::StackHeight() {
	// Returns counter data
	return this->count;
}

/*
@func Peek
@param VOID
@ret T top of stack data
@dec Checks the top value of the stack without modifiying stack.
*/
template <class T>
T gStack<T>::Peek() {
	return this->top->data;
}

/*
@func PrintStack
@param VOID
@ret VOID
@desc Prints the given Stack's current elements from top to bottom.
*/
template <class T>
void gStack<T>::PrintStack() {
	// Iterator
	struct stackNode<T>* current = this->top;
	std::cout << "The current Stack: ";
	while (current != NULL) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}