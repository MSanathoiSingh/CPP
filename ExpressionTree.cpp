#include<iostream>
#include<string>
#include<stack>
//#include <stdlib.h>
using namespace std;
struct node{
    string data;
    struct node *left;
    struct node *right;
};
class stack0{
private:
    int n=14;
    int top, top2;
public:
    node* arr1[10];
    //struct node *root,*root1;
    string arr0[14];
    stack0(){
        top= -1;
        top2= -1;
        for(int t=0;t<10;t++){arr1[t]=NULL;}
        for(int i=0;i<14;i++){arr0[i]= "@";}
    }
    void reset(){
        top=-1;
        for(int p=0;p<14;p++){arr0[p]= "@";}
    }
    void pushN(node*);
    node* getopN();
    void popN();
    string push0(string);
    void pop0();
    string getop();
    string toPost(string);
    bool isOP(char);
    node* crNew(string);
    void construct(string);
    string postorder();
    void delTree();
};
string stack0::push0(string val){
    arr0[++top]= val;
    return arr0[top];
}
void stack0::pop0(){
    arr0[top]= "@";
    top= --top;
}
string stack0::getop(){
    string tmp1= arr0[top];
    return tmp1;
}
bool stack0::isOP(char val0){
    if(val0=='/'||val0=='*'||val0=='-'||val0=='+'||val0=='^')
        return true;
    else
        return false;
};
string stack0::toPost(string prefix){
    int len= prefix.size();
    for(int i=len-1;i>=0;i--){
        if(isOP(prefix[i])){
            string op1= getop();       pop0();
            string op2= getop();       pop0();
            string tmp3= op1+op2+prefix[i];
            push0(tmp3);
        }
        else{
            push0(string(1,prefix[i]));
        }
    }
    return getop();
    reset();
};
void stack0::pushN(node* dat2){
    arr1[++top2]= dat2;
}
node* stack0::getopN(){
    node* tmp22= new node;
    tmp22= arr1[top2];
    return tmp22;
}
void stack0::popN(){
    arr1[top2]= NULL;
    top2= --top2;
}
node* stack0::crNew(string val5){
    struct node* tmp4= new node;
    tmp4->data= val5;
    tmp4->left= NULL;
    tmp4->right= NULL;
    return tmp4;
}
void stack0::construct(string exp2){
    int len2= exp2.size();
    struct node* tmp11= new node;
    for(int l=0;l<len2;l++){
        if(isOP(exp2[l])){
            tmp11= crNew(string(1,exp2[l]));
            if(top==0){
                if(arr1[top2]==NULL){
                    popN();
                    tmp11->left= getopN();    popN();
                    tmp11->right= crNew(getop());
                    pop0();
                    pushN(tmp11);
                    //arr1[top2]= tmp11;
                }
                else{
                    tmp11->left= crNew(getop());
                    tmp11->right= getopN();     popN();
                    pop0();
                    pushN(tmp11);
                    //arr1[top2]= tmp11;
                }
            }
            else if(top==-1){
                struct node* rptr= getopN();    popN();
                struct node* lptr= getopN();    popN();
                tmp11->left= lptr;
                tmp11->right= rptr;
                pushN(tmp11);
                //arr1[top2]= tmp11;
                pushN(NULL);
                //arr1[top2]= NULL;
            }
            else{
                string rop= getop();    pop0();
                string lop= getop();    pop0();
                tmp11->left= crNew(lop);
                tmp11->right= crNew(rop);
                pushN(tmp11);//arr1[top2]= tmp11;
            }
        }
        else{
            push0(string(1,exp2[l]));
        }
    }
    cout<<"\tExpression Tree constructed!!"<<endl;
}
string stack0::postorder(){
    //int ind= top;
    reset();
    if(top2==-1){cout<<"Sorry, nothing to traverse"<<endl;}
    struct node* pst= arr1[top2];
    if(pst==NULL){
        if(top2==0){cout<<"Sorry, nothing to traverse!!"<<endl;}
        else{
            popN();
            pst= arr1[top2];
        }
    }
    stack<node*> work;
    work.push(pst);
    while(!work.empty()){
        node* print= work.top();        work.pop();
        push0(print->data);
        if(print->left!=NULL){
            work.push(print->left);
        }
        if(print->right!=NULL){
            work.push(print->right);
        }
    }
    cout<<"Post-Order Traversal of Expression Tree yields: "<<getop()<<endl;
    /*cout<<"entering for"<<top<<endl;
    for(int y=top;y>=0;y--){
        cout<<"display"<<endl;
        cout<<arr0[y]<<" ";
    }
    cout<<"exited for"<<endl;*/
}
void stack0::delTree(){
    for(int r=0;r<10;r++){
        arr1[r]= NULL;
    }
    top2= -1;
    cout<<"\tWhole tree deleted!!"<<endl;
}
int main()
{
    cout<<"Implemented by MSanathoi"<<endl;
    stack0 obj2;
    string exp= "+--a*bc/def";
    cout<<"The prefix operation to operate on is: "<<exp<<endl;
    string conv= obj2.toPost(exp);
    obj2.construct(conv);
    obj2.postorder();
    obj2.delTree();
    obj2.postorder();
    return 0;
}
