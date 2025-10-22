#include<iostream>
#include<list>
using namespace std;
// hash table class 
class HashTable{
	private:
		int capacity;
		list<int>* table; // each index have linked list in the array of hashtable
//		Each element in this array is a list<int>.
				
		// Hash function to calculate the index for a given key
    	int hashFunction(int key){
    		return key % capacity;    // Simple modulo-based hash function
		}
		
	public:
		HashTable(int size){
			capacity = size;
			table = new list<int>[capacity]; 	// Create an array of lists
		}
		// insertion
		void insert(int key){
			int index = hashFunction(key);
			table[index].push_back(key);
		}
		// remove element
		void remove(int key){
			int index = hashFunction(key);
			table[index].remove(key);
		}
		// Searching
		bool search(int key){
			int index = hashFunction(key);
			for (int element : table[index]){
				if(element == key){
					return true;
				}
			}
			return false;
		}
		// Display al the Hash table value
		void display(){
			for(int i=0; i<capacity; i++){		// Iterate through all buckets
				cout<<"Bucket "<<i<<" : ";
				for(int element : table[i]){ 	// Display all elements in the bucket
					cout<<element<<" ";
				}
				cout<<endl;
			}
		}
		// Destructor to free the dynamically allocated memory
		~HashTable(){
			delete[] table;		// Free the memory used by the array of lists
		}
};
int main(){
	int capacity = 7;			// Size of the hash table (number of buckets)
	HashTable ht(capacity);		// Create a hash table
	
	ht.insert(10);
	ht.insert(20);
	ht.insert(15);
	ht.insert(8);
	ht.insert(10);
	
	// Display the hash table
    cout << "Hash table contents:" << endl;
    ht.display();
    cout<<"--------------------------------"<<endl;
	// searching operation
	int searchKey;
	cout<<"Enter the element to search : ";
	cin>>searchKey;
	if(ht.search(searchKey)){
		cout<<"Key "<<searchKey<<" found in the hash table."<<endl;
	}else{
		cout<<"Key "<<searchKey<<" not found in the hash table."<<endl;
	}
	cout<<"--------------------------------"<<endl;
	// deletion a key from hash table.
	int removeKey;
	cout<<"Enter the element to delete : ";
	cin>>removeKey;
	ht.remove(removeKey);
	cout << "Hash table contents after deleting key :"<<removeKey<< endl;
    ht.display();
    cout<<"--------------------------------"<<endl;
	return 0;
}