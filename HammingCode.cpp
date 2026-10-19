#include <iostream>
using namespace std;
int datab[10];
int parb[8];
int messb[15];
int datal;
int mesl;
class sender{
public:
    void data(int l00,int arr00[],int l01){
        cout<<"Length of Hamming Code to be generated: ";   cin>>l01;
        cout<<"Number of data bits will be: ";  cin>>l00;
        for(int i=0;i<l00;i++){
            cout<<"Enter the "<<i+1<<"th bit: ";
            cin>>arr00[i];
        }
    }
    void gen(int l02,int l03,int data[],int trans[],int parity[]){
        if(l02==7){
            int ind;
            for(int p=0;p<l02;p++){            //calculating parity bit location
                if(2^p>l02){break;}
                else{parity[p]= 2^p;    ind=p;}
            }
            int id=0;
            for(int t=l02;t>=1;t--){            //traversing message bit
                for(int pl=ind;pl>=0;pl--){
                    if(t!=parity[pl]){
                        trans[l02]= data[id];
                    }
                }
                id++;
            }
        }
    }
    void show(){
        cout<<"Code "<<endl;
        for(int l=0;l<7;l++){
            cout<<messb[l];
        }
    }
};
int main(){
    cout<<"Implemented by MSanathoi"<<endl;
    sender sobj;
    sobj.data(datal,datab,mesl);
    sobj.gen(mesl,datal,datab,messb,parb);
    sobj.show();
    return 0;
}
