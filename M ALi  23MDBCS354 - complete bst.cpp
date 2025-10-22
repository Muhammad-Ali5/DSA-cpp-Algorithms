#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* lchild;
		Node* rchild;
		
		Node(int v){
			this->data = v;
			this->lchild = nullptr;
			this->rchild = nullptr;
		}	
};
class BST{
	private:
		Node* root;
		// insertion
		Node* insert(Node* root, int key){
			if(root == nullptr){
				return new Node(key);
			}
			if(key < root->data){
				root->lchild = insert(root->lchild, key);
			}
			else if(key > root->data){
				root->rchild = insert(root->rchild, key);
			}
			return root;
		}
		// Searching 
		bool search(Node* root, int key){
			if(root == nullptr){
				cout<<"The Tree is empty!"<<endl;
				return false;
			}
			else if(root->data == key){
				return true;
			}
			else if(key < root->data){
				return search(root->lchild, key);
			}
			else if(key > root->data){
				return search(root->rchild, key);
			}
			return key;
		}
		//1. pre order 
		void preorderTraversal(Node* root){
			if(root == nullptr){
				return ;
			}
			cout<<root->data<<" ";
			preorderTraversal(root->lchild);
			preorderTraversal(root->rchild);
		}
		//2. In order
		void inorderTraversal(Node* root){
			if(root == nullptr){
				return;
			}
			inorderTraversal(root->lchild);
			cout<<root->data<<" ";
			inorderTraversal(root->rchild);
		} 
		//3. Post order
		void postorderTraversal(Node* root){
			if(root == nullptr){
				return ;
			}
			postorderTraversal(root->lchild);
			postorderTraversal(root->rchild);
			cout<<root->data<<" ";
		}
		// Deletion process
		// Find the minimum number
		Node* findMin(Node* root){
			if(root == nullptr){
//				return;
			}
			Node* temp = root;
			while(temp && temp->lchild != nullptr){
				temp = temp->lchild;
			}
			return root;
		}
		// Find the maximum number
		Node* findMax(Node* root){
			if(root == nullptr){
//				return;
			}
			Node* temp = root;
			while(temp && temp->rchild != nullptr){
				temp = temp->rchild;
			}
			return root;
		}
		Node* deleteNode(Node* root, int key){
			if(root == nullptr){
				return root;
			}
			else if(key < root->data){
				root->lchild = deleteNode(root->lchild, key);
			}
			else if(key > root->data){
				root->rchild = deleteNode(root->rchild, key);
			}
			else{
				// root have no child
				if(root->lchild == nullptr && root->rchild == nullptr){
					delete root;
					root = nullptr;
				}
				// root have one child
				else if(root->lchild == nullptr ){
					Node* temp = root;
					root = root->rchild;
					delete temp;
				}
				else if(root->rchild == nullptr){
					Node* temp = root;
					root = root->lchild;
					delete temp;
				}
				// have 2 child node
				else{
					Node* min;
					min = findMin(root->rchild);
					root->data = min->data;
					root->rchild = deleteNode(root->rchild, min->data);
				}
			}
		}
		
	public:
		BST(){
			this->root = nullptr;
		}
		// All function are call from here.
		void insertTraversing(int key){
			root = insert(root, key);
		}
		void inorder(){
			inorderTraversal(root);
		}	
		void preorder(){
			preorderTraversal(root);
		}
		void postorder(){
			postorderTraversal(root);
		}
		bool searching(int key){
			return search(root, key);
		}
		void deletion(int key){
			root = deleteNode(root, key);
		}
};

int main(){
	BST tree;
	int size_bst;
	cout<<"Enter the size of BST : ";
	cin>>size_bst;
	cout<<"Enter the Element in the tree :"<<endl;
	for(int i=0; i<size_bst; i++){
		int value;
		cin>>value;
		tree.insertTraversing(value);
	}
	
	cout<<"In Order "<<endl;
	cout<<"==========="<<endl;
	tree.inorder();
	cout<<"\n------------------------------"<<endl;
	cout<<"Pre Order "<<endl;
	cout<<"==========="<<endl;
	tree.preorder();
	cout<<"\n------------------------------"<<endl;
	cout<<"Post Order "<<endl;
	cout<<"==========="<<endl;
	tree.postorder();
	cout<<"\n------------------------------"<<endl;
	
	cout<<"Searching Process "<<endl;
	cout<<"================="<<endl;
	int key;
	cout<<"Enter the Element to search : ";
	cin>>key;
	if(tree.searching(key)){
		cout<<"Element "<<key<<" found in the tree"<<endl;
	}else{
		cout<<"Element "<<key<<" not found in the tree"<<endl;
	}
	
	cout<<"Deletion Process "<<endl;
	cout<<"================="<<endl;
	int d_key;
	cout<<"Enter the Element to search : ";
	cin>>d_key;
	tree.deletion(d_key);
	cout << "Tree after deletion (Inorder): ";
    tree.inorder();
	
	return 0;
}