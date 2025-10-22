//#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class insertion{
	private:
		int i, j , temp;
	public:
		// place biggest element on proper position.
		void bubbleSort(int arr[], int size){
			for(i=0; i<size-1; i++){
				for(j=0; j<size-1-i; j++){
					if(arr[j] > arr[j+1]){
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
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
	insertion bs;
	int size; 
	cout<<"Enter the Length of Array : ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the Element in Array :  ";
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	bs.bubbleSort(arr, size);
	bs.display(arr, size);
	
	return 0;
}