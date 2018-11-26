/*
Graph_List.cpp

@desc This file contains the data structures needed to implement
 a undirected weighted graph in c++ using linked lists. Includes 
 utility functions such as Dijkstras shortest path finding.
*/

#include <iostream>

using namespace std;


// Structures

// Adjacency list node
typedef struct AdjListNodeTag {
	int edgeDest;
	int edgeWeight;
	struct AdjListNodeTag* next;
}AdjListNode;

// Adjacency list (edge list)
typedef struct AdjListTag {
	struct AdjListNodeTag* head;
}AdjList;

// Graph (Weighted, Undirected)
typedef struct GraphTag {
	int vertCount;
	struct AdjListTag* lists;
}Graph;

// Prototypes
Graph* CreateGraph(int numVert);
AdjListNode* CreateNewAdjNode(int dest, int weight);
void AddEdge(Graph* g, int src, int dest, int weight);
void PrintGraph(Graph* g);
int minDistHelper(Graph* g, int* distArray, bool* visitedArray);
void Dijkstras(Graph* g, int start, int dest);

// Main
int main() {

	int vertcount = 5;
	Graph* g = CreateGraph(vertcount);
	AddEdge(g, 0, 1, 1);
	AddEdge(g, 0, 2, 3);
	AddEdge(g, 2, 1, 2);
	AddEdge(g, 3, 2, 11);
	AddEdge(g, 3, 1, 5);
	AddEdge(g, 4, 3, 2);
	AddEdge(g, 4, 2, 1);
	AddEdge(g, 4, 0, 12);

	PrintGraph(g);
	Dijkstras(g, 1, 4);


	system("pause");
	return 0;
}

/*
@func CreateNewAdjNode
@param int dest, int weight
@ret AdjListNode* newNode
@desc A function to create and initilize the node with a dest and weight.
*/
Graph* CreateGraph(int numVert) {
	// Create a new graph
	Graph* g = new Graph;
	// Initilize number of vertices
	g->vertCount = numVert;
	// Initilize list of edges
	g->lists = new AdjList[numVert];
	// Initilize lists to null
	for (int i = 0; i < numVert; i++) {
		g->lists[i].head = NULL;
	}
	// Return graph pointer
	return g;
}

/*
@func CreateNewAdjNode
@param int dest, int weight
@ret AdjListNode* newNode
@desc A function to create and initilize the node with a dest and weight.
*/
AdjListNode* CreateNewAdjNode(int dest, int weight) {
	AdjListNode* newNode = new AdjListNode;
	newNode->edgeDest = dest;
	newNode->edgeWeight = weight;
	newNode->next = NULL;
	return newNode;
}

/*
@func AddEdge
@param Graph* g, int src, int dest, int weight
@ret VOID
@desc A function to add an edge between two nodes of the given weighted graph.
*/
void AddEdge(Graph* g, int src, int dest, int weight) {
	// Create the new node
	AdjListNode* newNode = CreateNewAdjNode(dest, weight);
	// Add new node to front of edge list
	newNode->next = g->lists[src].head;
	g->lists[src].head = newNode;

	// Undirected graph, must add edge to dest list as well
	newNode = CreateNewAdjNode(src, weight);
	newNode->next = g->lists[dest].head;
	g->lists[dest].head = newNode;
}

/*
@func PrintGraph
@param Graph* g
@ret VOID
@desc A function to print the adjacent list for the given graph.
*/
void PrintGraph(Graph* g) {
	cout << "Pringing Adjacent lists" << endl;
	for (int i = 0; i < g->vertCount; i++) {
		AdjListNode* current = g->lists[i].head;
		cout << "Adj list for vertex " << i << " is | ";
		while (current != NULL) {
			cout << "dest: " << current->edgeDest << ", W: " << current->edgeWeight << " | ";
			current = current->next;
		}
		cout << endl;
	}
}

/*
@func minDistHelper
@param Graph* g, int* distArray, bool* visitedArray
@ret int minIndex
@desc A heleper function that finds the next minimum path to a vertex that 
hasnt been visited.
*/
int minDistHelper(Graph* g, int* distArray, bool* visitedArray) {
	int minDist = 1000, minIndex;
	for (int i = 0; i < g->vertCount; i++) {
		if (visitedArray[i] == false && distArray[i] <= minDist) {
			minDist = distArray[i];
			minIndex = i;
		}
	}
	return minIndex;
}

/*
@func  Dijkstras
@param Graph* g, int start, int dest
@ret VOID
@desc An implementation of Dijkstras Algorithim using a link list structured  weighted graph.
*/
void Dijkstras(Graph* g, int start, int dest) {
	// Create an array to store distances
	int* distArray = new int[g->vertCount];
	// Create an array to store visited nodes
	bool* visited = new bool[g->vertCount];
	// Initilize arrays
	for (int i = 0; i < g->vertCount; i++) {
		distArray[i] = 999;
		visited[i] = false;
	}
	// Initilize start vertex
	distArray[start] = 0;
	// Storage for current vertex
	int currentV;
	// Find shortest path for all remaining vertices
	for (int j = 0; j < (g->vertCount - 1); j++) {
		// Find next vertex
		currentV = minDistHelper(g, distArray, visited);
		// Set as visted
		visited[currentV] = true;
		// Iterate through connected edges
		AdjListNode* temp = g->lists[currentV].head;
		while (temp != NULL) {
			// if dest vertex is not visted and (edge weight + path weight) is less than the current weight to dist
				if ((visited[temp->edgeDest] == 0) && ((temp->edgeWeight + distArray[currentV]) < distArray[temp->edgeDest]) && (distArray[currentV] != 999) ) {
					distArray[temp->edgeDest] = (temp->edgeWeight + distArray[currentV]);
				}
			temp = temp->next;
		}
	}
	// Print results
	cout << "Dijkstras completed, printing results..." << endl;
	cout << "Source: " << start << " Dest: " << dest << endl;
	cout << "Distance to dest from source: " << distArray[dest] << endl;
	for (int k = 0; k < g->vertCount; k++) {
		cout << k << ": " << distArray[k] << " ";
	}
	cout << endl;
	return;
}
