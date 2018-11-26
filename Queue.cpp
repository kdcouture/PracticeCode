#include <iostream>

using namespace std;

// Data structs

typedef struct QueueNodeTag {
	int data;
	struct QueueNodeTag* next;

}QNode;

typedef struct QueueTag {
	struct QueueNodeTag* front;
	int count;
}Queue;

//Prototypes

Queue* CreateQueue();
int Dequeue(Queue* q);
void Enqueue(Queue* q, int data);
void PrintQueue(Queue* q);

// Main
int main() {

	Queue* q = CreateQueue();
	Enqueue(q, 1);
	Enqueue(q, 2);
	Enqueue(q, 3);
	PrintQueue(q);
	Dequeue(q);
	PrintQueue(q);

	system("pause");
	return 0;
}

Queue* CreateQueue()
{
	Queue* q = new Queue;
	q->front = NULL;
	q->count = 0;
	return q;
}

int Dequeue(Queue * q)
{
	// Temp location for front node to dequeue
	QNode* qn = q->front;
	// Temp data holder
	int data = qn->data;
	// Adjust queue
	q->front = qn->next;
	// Free memory
	delete qn;
	qn = NULL;
	// Decrement queue count
	q->count--;
	// Return data from front of queue
	return data;
}

void Enqueue(Queue * q, int data)
{
	// Create new QNode
	QNode* newNode = new QNode;
	// Initilize values
	newNode->data = data;
	newNode->next = NULL;
	// Increment queue count
	q->count++;
	// Check for empty queue
	if (q->front == NULL) {
		q->front = newNode;
		return;
	}
	// Place element at back of queue
	else {
		// Create itereator
		QNode* current = q->front;
		// Find end of queue
		while (current->next != NULL) {
			current = current->next;
		}
		// Place new node
		current->next = newNode;
	}
}

void PrintQueue(Queue * q)
{
	// Create itereator
	QNode* current = q->front;
	// Print queue
	cout << "The queue is: ";
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
