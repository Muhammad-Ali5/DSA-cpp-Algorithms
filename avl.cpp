#include<iostream>
using namespace std;

class Node{
	public:
		int data, height;
		Node* left;
		Node* right;
		
		Node(int val): data(val), height(1), left(nullptr), right(nullptr){
            // this->data = val;
            // this->height = 1;
            // this->left = nullptr;
            // this->right = nullptr;
        }
};
// find the Height of Node
int getHeight(Node* root){
	if(root == nullptr){
		return 0;
	}
	return root->height;
}
// balance factor 
int getBalance(Node* root){
	return getHeight(root->left) - getHeight(root->right);
}
// right rotation
Node* rightRotation(Node* root){
	Node* child = root->left;
	Node* temp = child->right;
	child->right = root;
	root->left = temp;
	// update the height 
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	child->height = 1 + max(getHeight(root->left),getHeight(root->right));
}
// left rotation
Node* leftRotation(Node* root){
	Node* child = root->right;
	Node* temp = child->left;
	child->left = root;
	root->right = temp;
	
	root->height = 1+max(getHeight(root->left), getHeight(root->right));
	child->height = 1+max(getHeight(root->left), getHeight(root->right));
}
// insertion operation
Node* insert(Node* root, int key){
	if(root == nullptr){
		return new Node(key);
	}
	if(key < root->data){
		root->left = insert(root->left, key);
	}
	else if(key > root->data){
		root->right = insert(root->right, key);
	}
	else{
		return root;
	}
	// find the height for balancing the tree
	root->height = 1+max(getHeight(root->left), getHeight(root->right));
	// find the balance factor for the balancing 
	int balance = getBalance(root);
	// now here we have four cases for rotation 
	if(balance > 1 && key < root->left->data){
		return rightRotation(root);
	}
	if(balance > 1 && key > root->left->data){
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	if(balance < -1 && key > root->right->data){
		return leftRotation(root);
	}
	if(balance < -1 && key < root -> right -> data)
	{
		root -> right = rightRotation(root -> right);
	    return leftRotation(root);
	}
	else{
		return root;
	}
}
// minimum number 
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a node in the AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root; // Node to be deleted not found
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp; // Copy the contents of the non-empty child
            }

            delete temp;
        } else {
            // Node with two children: Get the inorder successor
            Node* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) {
        return root; // If the tree had only one node
    }

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if necessary
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotation(root); // LL Case
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotation(root->left); // LR Case
        return rightRotation(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotation(root); // RR Case
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotation(root->right); // RL Case
        return leftRotation(root);
    }

    return root;
}
// Function for in-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main(){
	Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-order traversal of the AVL tree: ";
    inOrder(root);
    cout << endl;
    cout<<"----------------------------------------"<<endl;
	// Delete nodes from the AVL tree
    root = deleteNode(root, 40);
    cout << "In-order traversal after deleting 40: ";
    inOrder(root);
    cout << endl;
    cout<<"----------------------------------------"<<endl;

    root = deleteNode(root, 30);
    cout << "In-order traversal after deleting 30: ";
    inOrder(root);
    cout << endl;
    cout<<"----------------------------------------"<<endl;

    return 0;
}