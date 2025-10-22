#include<iostream>
using namespace std;

int stack[5] , top=-1 , value ;
void push()
{

	if(top >= -1 && top<5){	
		
		++top; // pre i
		cout<<"Enter the value of stack : "<<endl;
		cin>>value;
		stack[top] = value;
//		cout<<"element : "<<stack[top]<<" push on index : "<<top<<endl;					
	}
	else{
		cout<<"Stack is full..."<<endl;
	}
}
void display(){
	for (top = 0; top<5; top++){	
		cout<<"element : "<<stack[top]<<" push on index : "<<top<<endl;					
	}
}
void pop(){
	if(top<=0 ){							// or --> if (top == -1)
		cout<<"Stack is empty ..."<<endl;
	}else{
		for(top=4; top>2; top--){
			cout<<"Element : "<<stack[top]<<" is popped on index : "<<top<<endl;
		}
	}
}
void peek(){
	if(top==-1){
		cout<<"Stack is Empty!"<<endl;
	}else{
		cout<<"The peek element is : "<<stack[top]<<endl;
	}	
}

int main(){
	
	int num;
	
	while(true){
		cout<<"==============================="<<endl;
		cout<<"Press 1. For Push Operation..."<<endl;
		cout<<"Press 2. For Pop Operation..."<<endl;
		cout<<"Press 3. For Peek Operation..."<<endl;
		cout<<"Press 4. For Dispaly Operation..."<<endl;
		cout<<"Press 5. For Exit the program2!"<<endl;
		cout<<"================================"<<endl;
		cin>>num;
		switch(num){
			case 1:
				cout<<"Push Operation..."<<endl;
				cout<<"========================"<<endl;
				push();
				push();
				push();
				push();
				push();
				push();
				push();
				break;
			case 2:
				cout<<"Pop Operation..."<<endl;
				cout<<"========================"<<endl;
				pop();
				break;
			case 3:
				cout<<"Peek Operation..."<<endl;
				cout<<"========================"<<endl;
				peek();
				break;			
			case 4:
				cout<<"Stack elements are ..."<<endl;
				display();
				cout<<"========================"<<endl;
				break;
			case 5:
				cout<<"Program terminated!"<<endl;
				exit(0);
				break;
			default:
				cout<<"jani ta derr bara lary ..."<<endl;
				exit(0);
				break;
		}
			
	}
	
	return 0;
}