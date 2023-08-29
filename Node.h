#pragma once

class Node
{
public:
	int value;
	Node* next;
	// Node* next2;

	Node(); // Default constructor
	Node(int); // Constructor with value parameter
	Node(Node*, int); // Constructor with next and value parameters

	void display(); // Display the linked list
};

// Function to set value to the tail node of the linked list
void setValueToTail(Node*&, int);

// Function to calculate the number of negative elements in the linked list
int calculateNegativeElements(Node*);

// Function to add a specific value to all elements in the linked list
void addToAllValue(Node*, int);

// Function to delete elements with a specific value from the linked list
void deleteElements(Node*&, int);

// Function to add new elements with a specific value after selected nodes in the linked list
void addElementsAfterSelected(Node*, int, int);

// Function to reverse the linked list and return the new head node
Node* reverse(Node*&);
