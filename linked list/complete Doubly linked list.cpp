#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the list
    DoublyLinkedList() {
        head = nullptr;
    }
    
    void insertFront( int value){
	Node* new_node = new Node(value);
	if(head == nullptr){
		head = new_node;
		return;
	}
	new_node->next =head;
	head->prev = new_node;
	head = new_node;
	}
	
	void insertEnd(int value){
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
	
	void insertAtPosition(int pos, int value){
		Node* new_node = new Node(value);
		if(head == nullptr && pos <= 0){
			cout<<"Invalid position "<<endl;
			return;
		}
		//empty linked list
		if(head == nullptr){
			head = new_node;
			return;
		}
		// Insert at the front if position is 1
		if(pos == 1){
			new_node->next = head;
			if(head != nullptr){
				head->prev = new_node;
			}
			head = new_node;
			return;
		}
		// Have other then 1 position
		Node* temp = head;
		for(int i=1; temp != nullptr && i < pos-1; i++){
			temp = temp->next;
		}	
		if(temp == nullptr){
			cout<<"Position out of range "<<endl;
			delete new_node;  // Free the memory allocated for the new node
			return;
		}
		new_node->next = temp->next;
		if (temp->next != nullptr) {
	        temp->next->prev = new_node;
	    }
	    temp->next = new_node;
	    new_node->prev = temp;	
		}
		// 1. delete At Front 
		void deleteFront(){
			if(head == nullptr){
				cout<<"Linked list is empty "<<endl;
				return;
			}
			Node* temp = head; 
			head = head->next;
			if(head != nullptr){
				head->prev = nullptr;
			}
			delete temp;
		}
		// 2. delete At End
		int deleteEnd(){
			if(head == nullptr){
				cout<<"Linked list is empty "<<endl;
//				return;  //exit the function
			}
			Node* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			if(temp->prev != nullptr){
				temp->prev->next = nullptr;
			}else{
				head = nullptr;  // If there's only one node
			}
			delete temp;
		}
		// 3. delete At Any position.
		
		// Display Function
	void display(){
		Node* temp = head;
		while(temp != nullptr){
			cout<<temp->data<<" <--> ";
			temp = temp->next;
		}
		cout<<" NULL"<<endl;
	}
    
};

int main(){
 	DoublyLinkedList list;

    // Insertion operations
    list.insertFront(10); // Insert 10 at the front
    list.insertEnd(20);   // Insert 20 at the end
    list.insertAtPosition(2, 15); // Insert 15 at position 2
    list.insertEnd(25);   // Insert 25 at the end
    list.display();
    
    cout << "List after insertion: ";
    list.display();

    // Deletion operations
    cout << "Deleting from front." << endl;
    list.deleteFront();

    cout << "Deleting from end." << endl;
    list.deleteEnd();

    cout << "List after deletion: ";
    list.display();

    cout << "Deleting at position 2." << endl;
//    list.deleteAtPosition(2);

    cout << "List after final deletion: ";
    list.display();
    
	return 0;
}

