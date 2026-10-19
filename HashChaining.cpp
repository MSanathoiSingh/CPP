#include <iostream>
#include <conio.h>
#include <string>
#define MAXX 10
using namespace std;
class HashTable{
    int cnt= 0;
public:
    string arr[MAXX][3];
    HashTable(){
        for(int i=0; i<MAXX; i++){
            for(int cl=0; cl<3; cl++){
                arr[i][cl]= "-1";
            }
        }
    }
    int hashfn(int);
    void ins(int,string);
    void reins(int,string);
    int linearprob(int);
    bool belong(int,string);
    void disp();
    void del(int);
    int findk(int);
};
int HashTable::hashfn(int key){
    return (key%MAXX);
}
bool HashTable::belong(int orkey, string tempk){
    string var= tempk;
    if(orkey==hashfn(stoi(var))){return true;}
    else{return false;}
}
int HashTable::linearprob(int ind){
    int ret;
    for(int r=ind+1; r<MAXX; r++){
        if(arr[r][1]=="-1"){
            ret= r;
            break;
        }
    }
    return ret;
}
void HashTable::ins(int key, string value){
    int k1= key;
    string skey= to_string(k1);
    int index= hashfn(k1);
    if(cnt<MAXX){
        if(arr[index][0]=="-1"){
            arr[index][0]= skey;
            arr[index][1]= value;
        }
        else{
            if(arr[index][2]=="-1"){
                int nind= linearprob(index);
                string snind= to_string(nind);
                arr[index][2]= snind;
                arr[nind][0]= skey;
                arr[nind][1]= value;
            }
            else{
                int temp= stoi(arr[index][2]);
                bool flag= false;
                while(flag==false){
                    if(arr[temp][2]!="-1"){
                        temp= stoi(arr[temp][2]);
                    }
                    else{
                        string stemp= to_string(temp);
                        flag= true;
                    }
                }
                int free= linearprob(temp);
                arr[temp][2]= to_string(free);
                arr[free][0]= skey;
                arr[free][1]= value;
            }
        }
    }
    cnt++;
    cout<<skey<<" inserted."<<endl;
}
void HashTable::reins(int key, string val){
    int sk2= key;
    int ind= hashfn(sk2);
    if(cnt<MAXX){
        if(arr[ind][0]=="-1"){
            arr[ind][0]= to_string(sk2);
            arr[ind][1]= val;
        }
        else{
            int tpind;
            if(belong(ind,arr[ind][0])){
                if(arr[ind][2]=="-1"){
                    tpind= linearprob(ind);
                    arr[ind][2]= to_string(tpind);
                    arr[tpind][0]= to_string(sk2);
                    arr[tpind][1]= val;
                }
                else{
                    bool flag2= false;
                    int chain= stoi(arr[ind][2]);
                    while(flag2==false){
                        if(arr[chain][2]=="-1"){
                            flag2= true;
                        }
                        else{chain= stoi(arr[chain][2]);}
                    }
                    tpind= linearprob(chain);
                    arr[chain][2]= to_string(tpind);
                    arr[tpind][0]= to_string(sk2);
                    arr[tpind][1]= val;
                }
            }
            else{
                string tmpk, tmpv, tmpc;
                tmpk= arr[ind][0];          tmpv= arr[ind][1];      tmpc= arr[ind][2];
                arr[ind][0]= to_string(sk2);
                arr[ind][1]= val;
                arr[ind][2]= "-1";
                bool flag3= false;
                int backind= hashfn(stoi(tmpk));
                while(flag3==false){
                    if(arr[backind][2]==to_string(ind)){
                        arr[backind][2]= "-1";
                        int changed= linearprob(backind);
                        arr[backind][2]= to_string(changed);
                        arr[changed][0]= tmpk;
                        arr[changed][1]= tmpv;
                        arr[changed][2]= tmpc;
                        flag3= true;
                    }
                    else{
                        backind= stoi(arr[backind][2]);
                    }
                }
            }
        }
    }
    cnt++;
    cout<<sk2<<" inserted by replacement."<<endl;
}
void HashTable::disp(){
    cout<<" The table entries goes like this: "<<endl;
    for(int a=0; a<MAXX; a++){
        cout<<a<<"\t"<<arr[a][0]<<"\t"<<arr[a][1]<<"\t"<<arr[a][2]<<endl;
    }
}
int HashTable::findk(int rec){
    int tmp= rec;
    int ret= -1;
    bool iflag= false;
    int kind= hashfn(tmp);
    if(arr[kind][0]==to_string(tmp)){
        cout<<"Index:"<<kind<<"   "<<arr[kind][0]<<"  "<<arr[kind][1]<<endl;
        cout<<tmp<<" found in the table."<<endl;
        ret= kind;
    }
    else if(arr[kind][0]=="-1"){
        cout<<tmp<<" not found."<<endl;
    }
    else{
        int tmp2= stoi(arr[kind][2]);
        while(iflag==false){
            if(to_string(tmp)==arr[tmp2][0]){
                cout<<"Index:"<<tmp2<<"   "<<arr[tmp2][0]<<"  "<<arr[tmp2][1]<<endl;
                cout<<tmp<<" found in the table."<<endl;
                iflag= true;
                ret= tmp2;
            }
            else if(arr[tmp2][2]=="-1"){
                cout<<tmp<<" not found."<<endl;
                iflag= true;
            }
            else{
                tmp2= stoi(arr[tmp2][2]);
            }
        }
    }
    return ret;
}
void HashTable::del(int dkey){
    int tmp= dkey;
    bool fl= false;
    int tval= findk(tmp);
    if(tval==-1){cout<<tmp<<" can't be deleted."<<endl;}
    else{
        if(hashfn(tmp)==tval){
            arr[tval][0]= "-1";  arr[tval][1]= "-1";
            if(arr[tval][2]!="-1"){
                int var1= stoi(arr[tval][2]);
                arr[tval][0]= arr[var1][0];     arr[tval][1]= arr[var1][1];     arr[tval][2]= arr[var1][2];
                arr[var1][0]= "-1";     arr[var1][1]= "-1";     arr[var1][2]= "-1";
            }
        }
        else{
            int chain= stoi(arr[tval][2]);
            int original= hashfn(tmp);
            while(fl==false){
                if(arr[original][2]==to_string(tval)){
                    arr[original][2]= to_string(chain);
                    arr[tval][0]= "-1";     arr[tval][1]= "-1";        arr[tval][2]= "-1";
                    fl= true;
                }
                else{
                    original= stoi(arr[original][2]);
                }
            }
        }
        cout<<tmp<<" deleted from "<<tval<<endl;
    }
}
int main(){
    cout<<"Implemented by MSanathoiSingh"<<endl;
    int key1, key2, reck, rem;
    string data, val;
    HashTable obj;
    cout<<"Please choose the operation: "<<endl;
    cout<<"1. Insert (key,value) pair without replacement."<<endl;
    cout<<"2. Insert (key,value) pair with replacement."<<endl;
    cout<<"3. Find a entry using its key."<<endl;
    cout<<"4. Delete a entry via the key."<<endl;
    cout<<"5. Display the table."<<endl;
    int choice;
    while(choice<6){
        switch(choice){
            case 1: cout<<"\nEnter the data as (key,value): ";    cin>>key1>>data;
                obj.ins(key1,data);
                break;
            case 2: cout<<"\nEnter the data as (key,value){with replacement): ";       cin>>key2>>val;
                obj.reins(key2,val);
                break;
            case 3: cout<<"\nEnter the key to be searched: ";       cin>>reck;
                obj.findk(reck);
                break;
            case 4: cout<<"\nEnter the key to be deleted: ";       cin>>rem;
                obj.del(rem);
                break;
            case 5: obj.disp();
                break;
        }
        cout<<"\n---Press any key >6 to EXIT else give choice: ";    cin>>choice;
    }
    return 0;
}
