#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{															/*defining structure node*/
    int PRN;															/*flag for PRN*/
    string name;														/*flag for name*/
    struct node* next;													/*flag for next pointer*/
};
class linkedlist{														/*class for linkedlist*/
private:
    struct node *head, *mid, *tail;										/*declaring node pointers*/
    int counter;														/*declaring counter flag*/
public:
    void presec(int, string);
    void addmember(int,int, string);
    void removepresec();
    void removemem(string xy);
    void show();
    void total();
    linkedlist(){														/*class constructor*/
        head= NULL;														/*defining default values*/
        tail= NULL;
        counter=0;
    }
};
void linkedlist::presec(int x, string xy){								/*function to add president or secretary*/
    struct node *temp;													/*declaring temporary node*/
    temp= new struct node;
    temp->PRN= x;														/*giving values to temp. node*/
    temp->name= xy;
    int choice;
    cout<<"Do you want to change 1)President, or 2)Secretary."<<endl;	/*user-driven menu*/
    cin>>choice;
    switch(choice){														/*switch cases*/
    case 1: if(head==NULL){												/*adding president, as sole element*/
        head= temp;
        tail= temp;
        tail->next=NULL;
        //temp=NULL;
        counter++;
        cout<<head->name<<" is added as President."<<endl;
    }
    else{
        temp->next= head;												/*changing the president*/
        head= temp;
        cout<<head->name<<" is the new President."<<endl;
        counter++;
    }
    break;
    case 2: if(tail==NULL){												/*adding secretary as sole element*/
        head= temp;
        tail= temp;
        tail->next=NULL;
        //temp=NULL;
        counter++;
        cout<<head->name<<" is added as Secretary."<<endl;
    }
    else{																/*changing the secretary*/
        struct node *curr= new struct node;								/*declaring new nodes*/
        struct node *prev= new struct node;
        curr= head;														/*initializing current pointer to head*/
        while(curr!=NULL){												/*iterates till last member*/
            prev= curr;
            curr= curr->next;
        }
        prev->next= temp;												/*setting next of previous member to new secretary*/
        temp->next= NULL;												/*setting next of new secretary to NULL*/
        cout<<temp->name<<" is the new secretary."<<endl;
        counter++;
    }
    break;
    default: cout<<"Please give valid input"<<endl;						/*default case*/
    }
}
void linkedlist::addmember(int l, int p, string n){						/*function to add members*/
    struct node *prev, *cur, *temp2;
    temp2= new struct node;												/*saving data to temporary node*/
    temp2->name= n;
    temp2->PRN= p;
    cur= head;															/*initializing current pointer to head*/
    if(l<counter){
        for(int i=0; i<l; i++){												/*iterates upto pre-set position in list*/
            prev= cur;
            cur= cur->next;
        }
        prev->next= temp2;													/*setting previous node of newly added node*/
        temp2->next= cur;													/*setting next node of newly added node*/
        cout<<temp2->name<<" is the new member."<<endl;
        counter++;
    }
    else{cout<<"Please give valid input."<<endl;}						/*defining alt text*/
}
void linkedlist::show(){												/*function to display element*/
    struct node *it= new struct node;									/*declaring flag node*/
    it= head;															/*initializing flag to head node*/
    cout<<"The list is: "<<endl;
    while(it!=NULL){													/*iterates upto tail node*/
        cout<<" "<<it->name<<" "<<it->PRN<<endl;						/*printing current info*/
        it= it->next;
    }
}
void linkedlist::removepresec(){										/*function to remove president or secretary*/
    int pr;
    cout<<"Remove 1)President, or 2)Secretary "<<endl;					/*user-driven menu*/
    while(pr<3){
        cout<<"Give the choice: "<<endl;
        cin>>pr;														/*accepting choice of user*/
        switch(pr){														/*switch cases*/
        case 1: {struct node *temp;
        temp= new struct node;
        temp= head;														/*storing head in temporary node*/
        head= head->next;												/*shifting head to next element*/
        delete temp;													/*deleting temporary node*/
        cout<<"President removed."<<endl;
        counter--;
        break;}
        case 2: {struct node *pre= new struct node;						/*declaring nodes pointer*/
        struct node *curr= new struct node;
        curr =head;														/*initializing current pointer*/
        while(curr->next!=NULL){										/*iterating upto last element*/
            pre= curr;
            curr= curr->next;
        }
        tail= pre;														/*setting 2nd last member as tail*/
        pre->next=NULL;
        cout<<"Secretary removed."<<endl;
        counter--;
        break;}
        default: cout<<"Please give valid input."<<endl;				/*setting default values*/
        }
    }
}
void linkedlist::removemem(string p){									/*function to remove member*/
    struct node *prev= new struct node;									/*declaring new node pointer*/
    struct node *curt= new struct node;
    curt= head;															/*initializing current pointer to head node*/
    while(curt->name!=p){												/*iterates upto said member*/
        prev= curt;
        curt= curt->next;												/*incrementing current pointer*/
    }
    prev->next= curt->next;												/*skipping the said element*/
    delete curt;														/*deleting the said element*/
    cout<<p<<" removed successfully."<<endl;
    counter--;
}
void linkedlist::total(){												/*function to display total member*/
    cout<<"There are total "<<counter<<" members including president and secretary."<<endl;
}
int main(){
    cout<<"Code by MSanathoi"<<endl;
    linkedlist trial;													/*instantiating linkedlist class*/
    int prn, ch, pos;													/*declaring variables*/
    string var, name;
    cout<<"Choose your preference: "<<endl;								/*displaying menu for user*/
    cout<<"1. Add president or secretary of club."<<endl;
    cout<<"2. Add members of club."<<endl;
    cout<<"3. Remove president or secretary."<<endl;
    cout<<"4. Remove members of the club."<<endl;
    cout<<"5. Show total club members."<<endl;
    cout<<"6. Display the list."<<endl;
    ch= 0;																/*initializing flag*/
    while(ch<7){														/*loop to repeat switch case*/
        cout<<"Give your choice: "<<endl;								/*accepting user choice*/
        cin>>ch;
        switch(ch){														/*switch block*/
        case 1: {cout<<"Enter the details i.e. Name(without spaces) and PRN: "<<endl;
        cin>>name>>prn;													/*accepting member details*/
        trial.presec(prn, name);										/*adding president, secretary*/
        break;}
        case 2: {cout<<"Enter the details i.e. Name(without spaces) and PRN, along with position: "<<endl;
        cin>>name>>prn>>pos;											/*taking member info*/
        trial.addmember(pos,prn,name);									/*adding member*/
        break;}
        case 3: trial.removepresec();									/*removing president, secretary*/
        break;
        case 4: {cout<<"Whom to delete? "<<endl;
        cin>>var;														/*accepting member name from user*/
        trial.removemem(var);											/*removing said member*/
        break;}
        case 5: trial.total();											/*displaying total number of members*/
        break;
        case 6: trial.show();											/*displaying members*/
        break;
        }}
    return 0;
}
