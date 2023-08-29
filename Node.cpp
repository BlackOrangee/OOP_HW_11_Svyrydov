#include "Node.h"
#include <iostream>

using namespace std;

// Default constructor
Node::Node()
{
	value = 0;
	next = nullptr;
}

// Constructor with value parameter
Node::Node(int value)
{
	this->value = value;
	next = nullptr;
}

// Constructor with next and value parameters
Node::Node(Node* next, int value)
{
	this->next = next;
	this->value = value;
}

// Function to set value to the tail node of the linked list
void setValueToTail(Node*& head, int value)
{
	Node* n = new Node(value); // Create a new node with the given value

	if (head == nullptr) // If the linked list is empty
	{
		head = n; // Make the new node the head of the linked list
		return;
	}
	Node* slider = head; // Create a slider node to traverse the linked list

	while (slider->next != nullptr) // Traverse until the last node (tail)
	{
		slider = slider->next; // Move to the next node
	}
	slider->next = n; // Set the new node as the next node of the tail node
}

// Display the value of the node and its linked nodes
void Node::display()
{
	Node* slider = this; // Create a slider node to traverse the linked list starting from 'this' node

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		cout << slider->value << " "; // Display the value of the current node
		slider = slider->next; // Move to the next node
	}
}

// Function to calculate the number of negative elements in the linked list
int calculateNegativeElements(Node* head)
{
	int counter = 0; // Initialize a counter to keep track of negative elements
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head'

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		if (slider->value < 0) // Check if the value of the current node is negative
		{
			counter++; // Increment the counter if the value is negative
		}
		slider = slider->next; // Move to the next node
	}
	return counter; // Return the total count of negative elements
}

// Function to add a specific value to all elements in the linked list
void addToAllValue(Node* head, int value)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head'

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		slider->value += value; // Add the specified value to the current node's value
		slider = slider->next; // Move to the next node
	}
}

// Function to delete elements with a specific value from the linked list
void deleteElements(Node*& head, int value)
{
	// Remove elements from the beginning with the specified value
	while (head->value == value)
	{
		head = head->next; // Move 'head' to the next node
	}

	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head'

	while (slider->next != nullptr) // Traverse until the second last node
	{
		if (slider->next->value == value && slider->next->next == nullptr)
		{
			slider->next = nullptr; // If the last node has the specified value, remove it
			break; // Exit the loop
		}
		if (slider->next->value == value)
		{
			slider->next = slider->next->next; // Skip the next node with the specified value
		}
		slider = slider->next; // Move to the next node
	}
}

// Function to add new elements with a specific value after selected nodes in the linked list
void addElementsAfterSelected(Node* head, int value1, int value2)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head'

	while (slider != nullptr) // Traverse the linked list
	{
		if (slider->value == value1) // Check if the current node's value matches 'value1'
		{
			// Create a new node with 'value2' and insert it after the current node
			slider->next = new Node(slider->next, value2);
		}
		slider = slider->next; // Move to the next node
	}
}

// Function to reverse the linked list and return the new head node
Node* reverse(Node*& head)
{
	Node* slider = head; // Initialize a slider node to traverse the linked list starting from 'head'
	Node* prew = new Node(); // Initialize a 'prew' node to keep track of the previous node
	Node* next = slider->next; // Initialize a 'next' node to keep track of the next node

	while (next != nullptr) // Traverse the linked list
	{
		prew = slider; // Save the current node as the previous node
		slider = next; // Move the slider to the next node
		next = slider->next; // Move the 'next' node to the next node

		// Reverse the direction of 'next' pointer to point to the previous node
		slider->next = prew;
	}
	head->next = nullptr; // Set the 'next' pointer of the original head node to nullptr to mark the end of the reversed list

	return slider; // Return the new head node of the reversed list
}
