#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class record
{
public:
    int rollNo;
    char name[50];
    char div;
    char loc[50];
    void input();
    void disp();
};
void record::input(){
    cout<<"\nRoll No: ";       cin>>rollNo;
    cout<<"\nStudent's Name: ";     cin>>name;
    cout<<"\nDivision: ";       cin>>div;
    cout<<"\nStudent's Address: ";      cin>>loc;
}
void record::disp(){
    cout<<"\n\tRollNo: "<<rollNo<<"\tName: "<<name<<"\tDivision: "<<div<<"\tAddress: "<<loc;
}
int main(){
    int cnt=0, add0= 1;
    int choice, del;
    bool flag= false;
    bool fl2= false;
    char val[50];
    record obj;
    fstream rec, buf;
    cout<<"\n1. Create a new record.";
    cout<<"\n2. Display Records.";
    cout<<"\n3. Search for a particular student (by NAME).";
    cout<<"\n4. Delete a particular entry of student.";
    cout<<"\n\nPress any other key to exit.";
    cout<<"\nPlease specify a choice: ";    cin>>choice;
    while(choice<5){
        switch(choice){
            case 1: rec.open("Record.txt",ios::out);
                while(add0==1){
                    obj.input();
                    rec.write((char*)&obj,sizeof(obj));
                    cnt++;
                    cout<<"\nWant to make another entry?\t1. Yes, I want to.\t2. No, thanks ";   cin>>add0;
                }
                rec.close();
                break;
            case 2: rec.open("Record.txt",ios::in);
                cout<<"\nTotal entries are "<<cnt<<", which goes as ";
                while(!rec.eof()){
                    rec.read((char*)&obj,sizeof(obj));
                    obj.disp();
                }
                rec.close();
                break;
            case 3: rec.open("Record.txt",ios::in);
                cout<<"\nWhich student to check for?? ";    cin>>val;
                while(!rec.eof()){
                    rec.read((char*)&obj,sizeof(obj));
                    if(strcmp(val,obj.name)==0){
                        cout<<"\n"<<obj.name<<" present in the record."<<endl;
                        obj.disp();
                        flag= true;
                        break;
                    }
                }
                if(flag!=true){
                    cout<<"No matching entries found."<<endl;
                }
                rec.close();
                break;
            case 4: rec.open("Record.txt",ios::in);     buf.open("tmp.txt",ios::out);
                rec.read((char*)&obj,sizeof(obj));
                cout<<"\nRollNo of Student to remove: ";      cin>>del;
                while(!rec.eof()){
                    if(del!=obj.rollNo){
                        buf.write((char*)&obj,sizeof(obj));
                    }
                    else{
                        fl2= true;
                    }
                    rec.read((char*)&obj,sizeof(obj));
                }
                rec.close();        buf.close();
                remove("Record.txt");       rename("tmp.txt","Record.txt");
                if(fl2!=true){
                    cout<<"\nNo entry with Roll No as "<<del<<" as found."<<endl;
                }
                else{
                    cnt--;
                    cout<<"\nRoll No. "<<del<<" deleted successfully."<<endl;
                }
                break;
        }
        cout<<"\nPlease specify a choice: ";    cin>>choice;
    }
    return 0;
}
