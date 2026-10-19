#include<iostream>
using namespace std;
int circularque[5];														/*initializing queque*/
int n=5;																/*defining max size*/
int start= -1;															/*declaring front flag*/
int rear= -1;															/*declaring rear flag*/
void enqueque(){														/*function to insert element*/
    int val;
    cout<<"May I have your order, please ";
    cin>>val;															/*accepting value to be inserted*/
    if(start==0 && rear==n-1){    										/*checking for full queque*/
        cout<<"Sorry, no more orders please!"<<endl;
    }
    else if(start==-1){     											/*inserting element at index 0*/
        start=0;
        rear=1;
        circularque[rear]=val;
    }
    else if(rear==n-1){													/*inserting element at index 4*/
        rear=0;
        circularque[rear]=val;
    }
    else{rear=rear+1;													/*inserting element at other location*/
    circularque[rear]=val;};
}
void getfront(){														/*function to get front element*/
    if(start==5){start=0;}												/*resetting the front flag*/
    cout<<"Front is "<<circularque[start]<<endl;}
void dequeque(){														/*function to display element*/
    if(start==5){start=0;};												/*resetting front flag*/
    cout<<"Fulfilled order is: "<<circularque[start]<<endl;
    start++;
}
void display(){															/*function to display circularque*/
    cout<<"Pending orders are; "<<endl;
    if(start<=rear){													/*iterates from index 0 to 4*/
        for(int i=start; i<=rear; i++){
                cout<<circularque[i]<<" ";
        }
    }
    else{
        for(int y=start; y<n; y++){cout<<circularque[y]<<" ";}			/*iterates from front flag to index 4*/
        for(int p=0; p<rear; p++){cout<<circularque[p]<<" ";}			/*iterates from index 0 to rear flag*/
    }
}
int main(){
	cout<<"Code by MSanathoi"<<endl;
    int choice;
    cout<<"How can we help you?"<<endl;									/*displaying menu for users*/
    cout<<"1. Place an order"<<endl;
    cout<<"2. Confirm order fulfillment"<<endl;
    cout<<"3. Get list of pending orders"<<endl;
    cout<<"4. Get front element."<<endl;
    while(choice<5){													/*making program recursive*/
    cout<<endl<<"Enter your choice"<<endl;
    cin>>choice;														/*accepting user's choice*/
    switch(choice){														/*initializing switch block*/
    case 1: enqueque();
    break;
    case 2: dequeque();
    break;
    case 3: display();
    break;
    case 4: getfront();
    break;
    }
    }
    return 0;
}
