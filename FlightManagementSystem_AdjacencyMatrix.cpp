#include<iostream>
#include<stdlib.h>
#define MAXX 30
using namespace std;
class admatrix{                                             //user-defined data type for adjacency-matrix
	float info[MAXX][MAXX]={0};                             //matrix for storing flight information
	string origin[MAXX], dest[MAXX];                        //matrix(s) for storing city data
	public:
	int cntct=0;                                            //counters
	int routecnt=0;
	admatrix(){                                             //default constructors
		for(int y=0;y<MAXX;y++){
			origin[y]= "NULL";
			dest[y]="NULL";
		}
	}
	void inserts(string);                                   //methods
	void route(string,string,float);
	void searchs(string,string);
	void display();
	int modify(string,string,float);
	void del(string,string);
};
void admatrix::inserts(string city){                        //inserting a city
	if(origin[0]=="NULL"){                                  //insert first city
		origin[0]=city;
		dest[0]=city;
		cntct++;
	}
	else{                                                   //append new city at end
		origin[cntct]=city;
		dest[cntct]=city;
		cntct++;
	}
	cout<<dest[cntct-1]<<" inserted as city."<<endl;
}
void admatrix::route(string ct1, string ct2, float time){   //inserting a route
	bool flag= false;
	bool flag1= false;
	int index=0;
	int ind=0;
	for(int p=0;p<cntct;p++){                               //traversing for origin city search{sequential search}
		if(origin[p]==ct1){
			flag= true;
			break;}
		index++;
	}
	if(flag!=true){inserts(ct1);	/*index++;*/}           //inserting city if not present initially
	for(int i=0;i<cntct;i++){                               //sequential search for destination city
		if(dest[i]==ct2){
			flag1= true;
			break;}
		ind++;
	}
	if(flag1!=true){inserts(ct2);	/*ind++;*/}              //inserting destination city if not present initially
	info[index][ind]= time;                                  //inserting flight info
	cout<<"Route from "<<origin[index]<<" to "<<dest[ind]<<" inserted."<<endl;
	routecnt++;
}
void admatrix::searchs(string org, string dst){             //route search
	bool flag2= false;
	int index1=0;
	int ind1=0;
	for(int p=0;p<cntct;p++){                               //traverse for origin city
		if(origin[p]==org){
			flag2= true;
			break;}
		index1++;
	}
	if(flag2==true){
		for(int i=0;i<cntct;i++){
		if(dest[i]==dst){break;}
		ind1++;}
		if(info[index1][ind1]!=0){                          //route present and displayed
			cout<<"Time taken to go from "<<origin[index1]<<" to "<<dest[ind1]<<" is "<<info[index1][ind1]<<" hrs."<<endl;}
		else{cout<<"No, such route exists."<<endl;}
	}
	else{cout<<"No, such route exists."<<endl;              //if origin city not found route doesn't exists
	}
}
void admatrix::display(){                                   //display routes available
	bool flag= false;
	for(int outind=0;outind<cntct+1;outind++){              //traverse for origin city
		for(int inind=0;inind<cntct+1;inind++){             //traverse for destination city
			if(info[outind][inind]!=0){cout<<"Time taken to travel from "<<origin[outind]<<" to "<<dest[inind]<<" is "<<info[outind][inind]<<" hrs."<<endl;
            flag= true;
			}
		}
	}
	if(flag==false){cout<<"Sorry, no routes available yet!!"<<endl;}
}
int admatrix::modify(string op1, string op2,float next){   //modify the route info
	bool flag3= false;
	bool flag4= false;
	int ret=-1;
	int index2=0;
	int ind2=0;
	for(int o=0;o<cntct;o++){                               //traverse for origin city
		if(origin[o]==op1){
			flag3= true;
			break;}
		index2++;
	}
	if(flag3!=true){cout<<"Please enter valid city name."<<endl;}   //if origin not found
	else{
		for(int l=0;l<cntct;l++){                           //traverse  for destination city
			if(dest[l]==op2){
				flag4= true;
				break;}
			ind2++;
		}
		if(flag4==true){                                    //modifying data
			if(info[index2][ind2]!=0){
                info[index2][ind2]=next;
                cout<<info[index2][ind2]<<" is the new modified value."<<endl;
                ret=0;
			}
			else{cout<<"Sorry, information doesn't match with records."<<endl;}
		}
		else{cout<<"Please enter valid city name."<<endl;}  //if destination city not found
	}
	return ret;
}
void admatrix::del(string cty1,string cty2){                //delete a route
	string tmp1= cty1;
	string tmp2= cty2;
	int dec= modify(cty1,cty2,0);
	if(dec==0){                                    //deleting
        routecnt--;
        cout<<"Route from "<<tmp1<<" to "<<tmp2<<" removed."<<endl;
	}
}
int main(){
	cout<<"Implemented By MSanathoi"<<endl;
	int ch;
	string ins, org1, dest1, mod1, mod2;
	float tme, n1;
	admatrix obj;                                           //instantiating class admatrix
	cout<<"Please choose operations from below list: "<<endl;
	cout<<"1. Insert a city."<<endl;
	cout<<"2. Insert a route."<<endl;
	cout<<"3. Search particular route."<<endl;
	cout<<"4. Modify route information."<<endl;
	cout<<"5. Delete particular route."<<endl;
	cout<<"6. Display all the routes available."<<endl;
	cout<<"7. Get statistics."<<endl;
	while(ch<8){                                            //menu-driven program
		switch(ch){
			case 1:
				cout<<"\nGive the city to be inserted: ";	cin>>ins;
				obj.inserts(ins);
				break;
			case 2:
				cout<<"\nGive the following: ";	cout<<"Origin city: ";	cin>>org1;	cout<<"Destination city; ";	cin>>dest1;	cout<<"Total journey duration: ";	cin>>tme;
				obj.route(org1,dest1,tme);
				break;
			case 3:
				cout<<"Enter the origin snd destination please: ";	cin>>org1>>dest1;
				obj.searchs(org1,dest1);
				break;
			case 4:
				cout<<"Please enter the origin and destination: ";	cin>>mod1>>mod2;
				cout<<"What's the new time? ";	cin>>n1;
				obj.modify(mod1,mod2,n1);
				break;
			case 5:
				cout<<"Enter the origin and destination city: ";	cin>>mod1>>mod2;
				obj.del(mod1,mod2);
				break;
			case 6:
				obj.display();
				break;
			case 7:
				cout<<"Total cities present are "<<obj.cntct<<" and routes present are "<<obj.routecnt<<endl;
				break;
		}
		cout<<"\nEnter your choice: ";	cin>>ch;
	}
    return 0;
}
