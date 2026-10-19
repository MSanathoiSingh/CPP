#include <iostream>
using namespace std;
int framel, genl;
int frame[15], gen[11];
int tmp[10];
class send{
public:
    void length(){
        cout<<"Enter the length of FRAME: ";       cin>>framel;
        cout<<"Enter the length of GENERATOR: ";    cin>>genl;
    }
    void accept(int l1,int l2){
        cout<<"Enter the MESSAGE: "<<endl;
        for (int i=0;i<l1;i++){
            cout<<"\tEnter the "<<i<<"th bit: ";      cin>>frame[i];
        }
        cout<<"Enter the GENERATOR: "<<endl;
        for(int o=0;o<l2;o++){
            cout<<"\tEnter the "<<o<<"th bit: ";     cin>>gen[o];
        }
    }
    void divS(int div[],int gen0[],int sorl,int divl,int res[]);
    void messageT(int res00[],int l1, int l2,int mes[]){
        cout<<"Final CODEWORD to be transmitted is: ";
        int l02= l2-1;
        for(int i=0;i<l1;i++){
            cout<<mes[i];
        }
        for(int l=0;l<l02;l++){
            mes[l1+l]= res00[l+1];
            cout<<mes[l1+l];
        }
    }
};
void send::divS(int div[],int gen0[],int sorl,int divl,int res[]){
    int app= sorl-1;
    for(int i=0;i<app;i++){
        div[divl+i]=0;
    }
    divl= divl+app;
    for(int p=0;p<sorl;p++){
        res[p]= div[p]^gen0[p];
    }
    for(int r=sorl;r<divl;r++){
        for(int s=0;s<sorl;s++){
            if(s==sorl-1){res[s]= div[r];}
            else{res[s]= res[s+1];}
        }
        if(res[0]==0){
            for(int y=0;y<sorl;y++){
                res[y]= res[y]^0;
            }
        }
        else{
            for(int u=0;u<sorl;u++){
                res[u]= res[u]^gen0[u];
            }
        }
    }
    cout<<"CRC is: ";
    for(int q=1;q<sorl;q++){
        cout<<res[q];
    }
    cout<<endl;
}
class rec{
public:
    void check(int rec01[],int div01[],int tmp01[],int p1,int p2){
        cout<<"\nReceived CODEWORD is: "<<endl;
        int mesl= p1+(p2-1);
        for(int i=0;i<mesl;i++){
            cout<<"Enter the "<<i<<"th bit: ";
            cin>>rec01[i];
        }
        cout<<endl;
        for(int p=0;p<p2;p++){
            tmp01[p]= rec01[p]^div01[p];
        }
        for(int r=p2;r<mesl;r++){
            for(int s=0;s<p2;s++){
                if(s==p2-1){tmp01[s]= rec01[r];}
                else{tmp01[s]= tmp01[s+1]; }
            }
            if(tmp01[0]==0){
                for(int y=0;y<p2;y++){
                    tmp01[y]= tmp01[y]^0;
                }
            }
            else{
                for(int u=0;u<p2;u++){
                    tmp01[u]= tmp01[u]^div01[u];
                }
            }
        }
        bool flag= false;
        for(int w=1;w<p2;w++){
            if (tmp01[w]==0){flag=false;}
            else{flag=true;     break;}
        }
        if(flag!=true){cout<<"The message will be accepted.";}
        else{cout<<"The message will be rejected.";}
    }
};
int main(){
	cout<<"Implemented by MSanathoi"<<endl;
    send obj1;
    int v1,v2;
    obj1.length();
    v1= framel;     v2= genl;
    obj1.accept(v1,v2);
    obj1.divS(frame,gen,v2,v1,tmp);
    obj1.messageT(tmp,v1,v2,frame);
    rec obj2;
    obj2.check(frame,gen,tmp,v1,v2);
}
