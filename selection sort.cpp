#include<iostream>
//#include <bits/stdc++.h>

using namespace std;
class insertion{
	private:
		int i, j , temp, min_index;
	public:
		void selectionSort(int arr[], int size){
			for(i=0; i<size-1; i++){
				min_index = i;
				for(j=i+1; j<size; j++){
					if(arr[j] < arr[min_index]){
						min_index = j;
					}
				}
				// Swap the found minimum element with the current element
				if(min_index != i){
					temp = arr[i];
					arr[i] = arr[min_index];
					arr[min_index] = temp;
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
	insertion ss;
	
	int size; 
	cout<<"Enter the Length of Array : ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the Element in Array :  ";
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	ss.selectionSort(arr, size);
	ss.display(arr, size);
	
	return 0;
}