#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			this->data = val;
			this->next =nullptr;
		}
};
class singleLinkedlist{
	private:
		node* head;
	public:
		singleLinkedlist(){
			this->head = nullptr;
		}
		 // Insert at the Head 
		void insertAtHead(int value){
			node* new_node = new node(value);
			new_node->next = head;
			head = new_node;
		}
		
		 // Isert at the End
		void insertAtEnd(int value){
			node* new_node = new node(value);
			if(head == nullptr){
				head = new_node;
				return;
		}
		node* temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = new_node;
		}
		 // Insert at the Any position
		void insertAtAnyposition(int value, int pos){
			node* new_node = new node(value);
			
			if(pos == 1){
		 		new_node->next = head;
		 		head = new_node;
		 		return;
			}
			 node* temp = head;
			 for(int i=1; temp != nullptr && i<pos-1; i++){
			 	temp = temp->next;
			}
			 new_node->next = temp->next;
			 temp->next = new_node;
		}
		 //delete form head.
		void deleteAthead(){
			if(head==nullptr){
		 		cout<<"The list is empty";
		 		return;
			}
			node* temp = head;
			head = head->next;
			delete temp;			 
		}
		 //delete from end.
		void deleteAtend(){
			if(head == nullptr){
				cout<<"The list is empty";
		 		return;
			}
			if(head->next == nullptr){
				delete head;
				head = nullptr;
				return;
			}
			
			node* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
		 //delete at any position.
		void deletePosition(int pos){
			if(head == nullptr || pos <= 0){
				cout<<"Invalid position . Enter the valid position..."<<endl;
				return;
			}
			if(pos == 1){
				node* temp = head;
				head = temp->next;
				delete temp;
				return;
			}
			node* temp = head;
			for(int i=1; temp != nullptr && i<pos; i++){
				temp = temp->next;
			}
    		node* nodeToDelete = temp->next;
 			temp->next = temp->next->next;
    		delete nodeToDelete;
		}
		// search a value
		int search(int value){
			node* temp = head;
			while(temp != nullptr){
				if(temp->data == value){
					return true;
				}
			}
			return false;
		}
		void display(){
		 	node* temp = head;
		 	while(temp != nullptr){
		 		cout<<temp->data<<" -> ";
		 		temp = temp->next;
			}
			cout<<" NULL"<<endl;
		}
};
int main(){
	singleLinkedlist sll;
	cout<<"Insertion At Head "<<endl;
	cout<<"-----------------"<<endl;
	sll.insertAtHead(10);
	sll.insertAtHead(20);
	sll.insertAtHead(30);
	sll.insertAtHead(40);
	sll.display();
	cout<<"========================="<<endl;
	cout<<"Insertion At End "<<endl;
	cout<<"-----------------"<<endl;
	sll.insertAtEnd(70);
	sll.insertAtEnd(80);
	sll.display();
	cout<<"*******************************"<<endl;
	cout<<"Insertion At Any Position "<<endl;
	cout<<"-----------------"<<endl;
	sll.insertAtAnyposition(200,3);
	sll.display();
	cout<<"========================="<<endl;
	cout<<"Delete Element At Head "<<endl;
	cout<<"-----------------"<<endl;
	sll.deleteAthead();
	sll.display();
	cout<<"========================="<<endl;
	cout<<"Delete Element At End "<<endl;
	cout<<"-----------------"<<endl;
	sll.deleteAtend();
	sll.display();
	
	cout << "Element found: " << (sll.search(30) ? "Yes" : "No") << endl;
	 
	return 0;
}



