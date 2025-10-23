#include<iostream>
using namespace std;

struct Node {
    int data;               // Data part
    Node* next;             // Pointer to next node
    Node* prev;             // Pointer to previous node

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
void insertFront(Node*& head, int value){
	Node* new_node = new Node(value);
	if(head == nullptr){
		head = new_node;
		return;
	}
	new_node->next =head;
	head->prev = new_node;
	head = new_node;
}
void insertEnd(Node*& head, int value){
	Node* new_node = new Node(value);
	if(head == nullptr){
		head = new_node;
		return;
	}
	Node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	
}
void insertAtPosition(Node*& head, int pos, int value) {
    // Create a new node with the given value
    Node* new_node = new Node(value);
    // Case 1: Check for invalid position (negative or zero)
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        delete new_node; // Free allocated memory
        return;
    }
    // Case 2: Handle insertion into an empty list at position 1
    if (head == nullptr && pos == 1) {
        head = new_node;
        return;
    } else if (head == nullptr) { // If list is empty but position is not 1
        cout << "Position out of range." << endl;
        delete new_node;
        return;
    }
    // Case 3: Insert at the front if position is 1
    if (pos == 1) {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    // Case 4: Insert at any other position
    Node* temp = head;
    // Traverse to the (pos-1)th node
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    // If position is out of range
    if (temp == nullptr) {
        cout << "Position out of range." << endl;
        delete new_node;
        return;
    }
    // Insert the new node at the correct position
    new_node->next = temp->next;
    
    if (temp->next != nullptr) { // Update the next node's previous pointer
        temp->next->prev = new_node;
    }

    temp->next = new_node;
    new_node->prev = temp;
}
