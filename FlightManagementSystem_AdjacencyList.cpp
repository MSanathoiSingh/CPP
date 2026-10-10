#include <iostream>
using namespace std;
struct node{
	string city;
	float fl, time;
	struct node *nlink, *dlink;
};
class adlist{
	struct node *head, *tail;
	public:
    int cnt= 0;
	int cntr= 0;
	adlist(){
		head= NULL;
		tail= NULL;
	}
	node* insert(string);
	void route(string, string, float, float);
	void search(string, string);
	void display(string);
	void info(node *ptr);
	bool connecting(node*,string);
};
node* adlist::insert(string name){
	node *tmp= new node();
	if(head==NULL){
		tmp->city= name;
		tmp->nlink=NULL;
		tmp->dlink=NULL;
		head= tmp;
		tail= tmp;
	}
	else{
		tmp->city= name;
		tmp->nlink=NULL;
		tmp->dlink=NULL;
		tail->dlink= tmp;
		tail= tmp;
	}
	cnt++;
	cout<<tmp->city<<" inserted as city."<<endl;
	return tmp;
};
void adlist::route(string from, string to, float fuel, float tme){
    string ct1= from;
    string ct2= to;
	node *tmp= new node();
	node *data= new node();
	tmp= head;
	bool enc= false;
	while(tmp!=NULL){
		if(tmp->city==from){
            enc=true;
            break;
        }
		else{tmp= tmp->dlink;}
	}
	if(enc==false){
        tmp= insert(from);
	}
	data->city= to;
	data->fl= fuel;
	data->time= tme;
	data->nlink= NULL;
	data->dlink= NULL;
	if(tmp->nlink==NULL){
		tmp->nlink= data;
	}
	else{
		while(tmp->nlink!=NULL){
			tmp= tmp->nlink;}
		tmp->nlink= data;
	}
	cntr++;
	cout<<"Route from "<<ct1<<" to "<<ct2<<" inserted."<<endl;
}
void adlist::info(node *temp){
	cout<<"Destination city: "<<temp->city<<endl;
	cout<<"Fuel consumed and time taken are: "<<temp->fl<<"kg and "<<temp->time<<"hrs respectively."<<endl;
}
void adlist::search(string origin, string dest){
	struct node *temp, *dorigin, *connect;
	string dest1= dest;
	temp= head;
	bool flag= false;
	bool flag1= false;
	for(int i=0; i<cnt; i++){
		if(temp->city==origin){
			dorigin= temp;
			connect= temp;
			flag= true;
			break;
        }
		temp= temp->dlink;
	}
	if(flag==false){
		cout<<"Origin city not present."<<endl;
	}
	else{
		if(dorigin->nlink==NULL){cout<<"No routes originate from here."<<endl;}
		else{
			while(dorigin!=NULL){
				if(dorigin->city==dest){
					flag1= true;
					break;
				}
				dorigin= dorigin->nlink;
			}
			if(flag1==true){
                info(dorigin);
			}
			else{
                bool flag2= false;
                connect= connect->nlink;
                while(flag2!=true||dorigin->nlink!=NULL){
                    flag2= connecting(connect,dest1);
                    if(flag2){
                        info(connect);
                        cout<<"Connecting flight from "<<connect->city<<" to "<<dest1<<endl;
                    }
                    break;
                    connect= connect->nlink;
                }
                if(flag2==false){cout<<"No flight is available to "<<dest1<<endl;}
			}
		}
	}
}
bool adlist::connecting(node *org, string to){
    string dest= to;
    node *ptr;
    ptr= head;
    bool flag4, flag8= false;
    for(int i=0; i<cnt; i++){
        if(ptr->city==org->city){
            flag4= true;
            break;
        }
        else{ptr= ptr->dlink;}
	}
	if(flag4==false){return false;}
	else{
        ptr= ptr->nlink;
        while(ptr!=NULL){
            if(ptr->city==dest){
                info(ptr);
                flag8= true;
                return true;
                break;
            }
        }
        if(flag8==false){return false;}
	}
}
void adlist::display(string key){
	node *tmp2;
	tmp2= head;
	int flag2= 0;
	while(tmp2!=NULL){
		if(tmp2->city==key){
			flag2= 1;
			break;
        }
		else{tmp2= tmp2->dlink;}
	}
	if(flag2==1){
		if(tmp2->nlink==NULL){
			cout<<"No outbound flight from the said city."<<endl;
		}
		else{
			int flag3=0;
			tmp2= tmp2->nlink;
			while(tmp2!=NULL){
				info(tmp2);
				tmp2= tmp2->nlink;
			}
			cout<<"Above are the connected cities from "<<key<<endl;
		}
	}
	else{cout<<"There are no cities matching the said origin."<<endl;}
}
int main()
{
    cout<<"Implemented By MSanathoi"<<endl;
	int choice, tmp;
	string orgct,key;
	string cto,ctd;
	string city1, city2;
	float fuell, ttaken;
	adlist obj;
	cout<<"Which operation is to be done?"<<endl;
	cout<<"1. Insert a city to the list."<<endl;
	cout<<"2. Enter a route."<<endl;
	cout<<"3. Search a route."<<endl;
	cout<<"4. Get list of destinations available."<<endl;
	cout<<"5. Get Statistics."<<endl;
	do{
		cout<<"Specify choice as 1/2/3/4/5: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter the city: ";
				cin>>orgct;
				obj.insert(orgct);
				break;
			case 2:
				cout<<"\nEnter the following: ";
				cout<<"OriginCity: ";  cin>>city1;
				cout<<" DestinationCity: ";  cin>>city2;
				cout<<" FuelConsumed: "; cin>>fuell;
				cout<<" TimeTaken: "; cin>>ttaken;
				obj.route(city1,city2,fuell,ttaken);
				break;
			case 3:
				cout<<"\nRoute to search"<<endl;
				cin>>cto>>ctd;
				obj.search(cto,ctd);
				break;
			case 4:
				cout<<"\nEnter the origin city:"<<endl;
				cin>>key;
				obj.display(key);
				break;
			case 5:
				cout<<"\nTotal cities registered are "<<obj.cnt<<" while total routes present are "<<obj.cntr;
				break;
			default: cout<<"\nPlease give valid choice.";
		}
		cout<<"\nWant to do more operations, enter 0 to exit else 1."<<endl;
		cin>>tmp;
	}while(tmp==1);
	return 0;
}
