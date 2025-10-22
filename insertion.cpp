#include<iostream>
//#include <bits/stdc++.h>
//#include<bits/stdc++.h>
using namespace std;
class insertion{
	private:
		int i, j , temp;
	public:
		void insertionSort(int arr[], int n) {
   			for (int i = 1; i < n; i++) {      // Step 1: Iterate over each element starting from index 1
        		int key = arr[i];               // Step 2: Store the current element as the 'key'
       			int j = i - 1;                  // Step 3: Start from the previous element
	
      		 	// Step 4: Shift elements of arr[0..i-1] that are greater than 'key' to one position ahead of their current position
       	 		while (j >= 0 && arr[j] > key) {
            		arr[j + 1] = arr[j];        // Shift element to the right
            		j = j - 1;                  // Move to the previous element
        		}

        	// Step 5: Place the key in its correct position
        	arr[j + 1] = key;
    	}
	}
	void display(int arr[], int size){
		for(i=0; i<size; i++){
			cout<<arr[i]<<" | ";
		}
		cout<<endl;
	}
	
};
int main(){
	insertion is;
	
	int size; 
	cout<<"Enter the Length of Array : ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the Element in Array :  ";
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	is.insertionSort(arr, size);
	is.display(arr, size);
	
	return 0;
}