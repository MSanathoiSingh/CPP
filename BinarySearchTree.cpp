#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int value;
    struct node *left,*right;
};
class BST{
public:
    struct node *root;
    int cnt= 454;
    //node *nnode[50];
    int head, tail;
    BST(){
        root= NULL;
        head= -1;
        tail= -1;
    }
    void create(int);
    void insertn(node*,node*);
    void inorder_rec(node*);
    void minim();
    void findmin(node*,int*);
    void searchs(int);
    void search2(node**,int,node*);
    void invert(node*);
    void swap1();
    int depth(node*);
    void longestPath();
};
void BST::create(int data){
    node *tmp= new node();
    tmp->value= data;
    tmp->left= NULL;
    tmp->right= NULL;
    if(root==NULL){
        root= tmp;
        cout<<tmp->value<<" inserted as root node."<<endl;
    }
    else{
        insertn(root,tmp);
    }
}
void BST::insertn(node *RT, node *var){
    if(var->value<RT->value){
        if(RT->left==NULL){
            RT->left= var;
            cout<<"Element inserted at left of "<<RT->value<<endl;
        }
        else{insertn(RT->left,var);}
    }
    if(RT->value<var->value){
        if(RT->right==NULL){
            RT->right= var;
            cout<<"Element inserted at right of "<<RT->value<<endl;
        }
        else{insertn(RT->right,var);}
    }
}
void BST::inorder_rec(node *var0){
    if(var0!=NULL){
        inorder_rec(var0->left);
        cout<<" "<<var0->value;
        inorder_rec(var0->right);
    }
}
void BST::minim(){
    int low= root->value;
    findmin(root,&low);
    cout<<"Minimum value among all the nodes is "<<low<<endl;
}
void BST::findmin(node *var2, int *low){
    if(var2!=NULL){
        findmin(var2->left,low);
        if(var2->value<*low){*low= var2->value;}
        findmin(var2->right,low);
    }
}
void BST::searchs(int key1){
    int rec= key1;
    node *op= new node();
    op= root;
    node *pred;//new node();
    if(op->value==key1){cout<<rec<<" is the root node of BST."<<endl;}
    else{
        search2(&op,rec,pred);
        if(op==NULL){cout<<"Element not found."<<endl;}
        else{cout<<rec<<" is the child of "<<pred->value<<"."<<endl;}
    }
}
void BST::search2(node **op1,int key2,node *vari){
    if(*op1==NULL){cout<<"Tree is empty."<<endl;}
    else{
        //node *tmp;
        while(*op1!=NULL){
            if((*op1)->value==key2){
                cout<<key2<<" found."<<endl;
                break;
            }
            //tmp= *op1;
            vari->value= (*op1)->value;
            if((*op1)->value<key2){
                *op1= (*op1)->right;
            }
            else{*op1= (*op1)->left;}
        }
    }
}
void BST::swap1(){
    //node *ptr;
    //ptr= root;
    invert(root);
    cout<<"The tree after swapping the roles of left and right pointers are: "<<endl;
    inorder_rec(root);
    cout<<"\nReverting back to original form."<<endl;
    invert(root);
}
void BST::invert(node *ptr){
    node *swap1;
    if(ptr!=NULL){
        //cout<<"entered"<<endl;
        if(ptr!=NULL){
            invert(ptr->left);
            invert(ptr->right);
            swap1= ptr->left;
            ptr->left= ptr->right;
            ptr->right= swap1;
        }
    }
}
int BST::depth(node *start){
    if(start==NULL){
        return 0;
    }
    else{
        int lefth= depth(start->left);
        int righth= depth(start->right);
        if(lefth>righth){return lefth+1;}
        else{return righth+1;}
    }
}
void BST::longestPath(){
    node *beg= root;
    int ltree= depth(beg->left);
    int rtree= depth(beg->right);
    if(ltree>rtree)
        cout<<"The longest path is in Left Sub-Tree with "<<ltree+1<<" nodes."<<endl;
    else
        cout<<"The longest path is in Right Sub-Tree with "<<rtree+1<<" nodes."<<endl;
}
int main(){
    cout<<"Implemented by MSanathoiSingh"<<endl;
    BST obj;
    int ch, dat, tmp;
    int key;
    while(ch<7){
        cout<<"\n1. Insert a node."<<endl;
        cout<<"2. Display the tree."<<endl;
        cout<<"3. Find minimum element of tree."<<endl;
        cout<<"4. Find a particular entry."<<endl;
        cout<<"5. Swap the left and right subtree."<<endl;
        cout<<"6. Display the number of node in Longest Path of Tree."<<endl;
        cout<<"Press any other key to exit."<<endl;
        cout<<"\nPlease specify your choice: ";   cin>>ch;
        switch(ch){
            case 1: cout<<"\nPlease enter the data to be stored: ";   cin>>dat;
                obj.create(dat);
                break;
            case 2: cout<<"\nNodes of tree are: ";
                obj.inorder_rec(obj.root);
                cout<<endl;
                break;
            case 3: obj.minim();
                break;
            case 4: cout<<"\nWhich entry to look for?? ";   cin>>key;
                obj.searchs(key);
                break;
            case 5: obj.swap1();
                break;
            case 6: obj.longestPath();
                break;
            default: cout<<"Please re-evaluate your choice."<<endl;
                break;
        }
    }
    return 0;
}

