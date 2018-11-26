/*
gStack.h

@desc This is the header file for the generic stack class.

*/
#pragma once
#ifndef GSTACK_H_
#define GSTACK_H_

template <class T>
struct stackNode {
	T data;
	struct stackNode* next;
};

template <class T>
class gStack
{
	int count;
	struct stackNode<T>* top;
public:
	gStack();
	~gStack();
	void Push(T data);
	T Pop();
	int StackHeight();
	T Peek();
	void PrintStack();
};

#endif // !GSTACK_H_