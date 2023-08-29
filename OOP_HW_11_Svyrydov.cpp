// Task 
// Implement a singly linked list :
// 
// Create the specified list(s).
// Print the list(s) – display the values of the elements on the screen.
// Perform the actions specified in the task.
// Display the results on the screen.
// Calculate the number of elements in the list with negative values in the data field.
// Increase the value of the data field for each element in the list by a value specified by the user.
// Remove each element from the list with a data field value specified by the user.
// After each element in the list with a data field value of V1, insert a new element with a data field value of V2.
// Reverse a linked list :
// Implement a function to reverse a linked list.
// In other words, the initial list should be modified so that its last element becomes the first,
//  the second - to - last becomes the second, and so on.
//

#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
    // Creating nodes and building a linked list
    Node* node = new Node(9);
    setValueToTail(node, 2);
    setValueToTail(node, 3);
    setValueToTail(node, -4);
    setValueToTail(node, 5);
    setValueToTail(node, 8);
    setValueToTail(node, 3);
    setValueToTail(node, 2);
    setValueToTail(node, 10);
    setValueToTail(node, 9);

    // Display the original linked list
    node->display();

    // Calculate the number of negative elements
    cout << "\nNegative elements: " << calculateNegativeElements(node);
    
    // Delete elements with value "9"
    deleteElements(node, 9);
    cout << "\n\nDelete \"9\"\n";
    node->display();

    // Add element with value "9" after element with value "3"
    addElementsAfterSelected(node, 3, 9);
    cout << "\n\nAdd \"9\" after \"3\"\n";
    node->display();

    // Reverse the linked list
    node = reverse(node);
    cout << "\n\nReverse\n";
    node->display();

    // Add value "3" to all elements
    addToAllValue(node, 3);
    cout << "\n\nAdd \"3\" to all values\n";
    node->display();

    cout << "\n\n\n";
}