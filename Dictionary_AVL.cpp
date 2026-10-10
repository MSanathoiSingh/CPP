#include<iostream>
#include<string.h>
#define MAX 15
using namespace std;
struct node
{
    string key,value;
	node *left;
	node *right;
	int level;
};
class dict
{
    int cmp=0;
public:
	node *root;
	node *itr= NULL;
	dict(){
	    root= NULL;
    }
    int height(node*);
    int balance(node*);
    node *ins(node*,string,string);
    int look(node*,string);
    void change(node*,string,string);
	node *rright(node*);        node *rleft(node*);
	node *singleLL(node*);      node *singleRR(node*);
	node *doubleRL(node*);      node *doubleLR(node*);
	void asc(node*);
	void dsc(node*);
};
int dict::height(node *opr)
{
    int ltree, rtree;
    if(opr->left==NULL){ltree=0;}
	else{ltree= 1+(opr->left->level);}
	if(opr->right==NULL){rtree=0;}
	else{rtree= 1+(opr->right->level);}
	if(ltree<rtree)
		return rtree;
	else
		return ltree;
}
int dict::balance(node *opr2)
{
	int lsub, rsub;
	if(opr2->left==NULL){lsub=0;}
    else{lsub= 1+(opr2->left->level);}
    if(opr2->right==NULL){rsub=0;}
    else{rsub= 1+(opr2->right->level);}
	return(lsub-rsub);
}
node *dict::rright(node *tmp)
{
	node *buf= new node;
	buf= tmp->left;
	tmp->left= buf->right;
	buf->right= tmp;
	tmp->level= height(tmp);
	buf->level= height(buf);
	return buf;
}
node *dict::rleft(node *tmp2)
{
    node *buf2;
	buf2= tmp2->right;
	tmp2->right= buf2->left;
	buf2->left= tmp2;
	tmp2->level= height(tmp2);
	buf2->level= height(buf2);
	return buf2;
}
node *dict::singleLL(node *nnew)
{
    cout<<"\nDoing Single Rotation, ie LL ";
	nnew= rright(nnew);
	return nnew;
}
node *dict::singleRR(node *nnew2)
{
    cout<<"\nDoing Single Rotation, ie RR ";
	nnew2= rleft(nnew2);
	return nnew2;
}
node *dict::doubleLR(node *nnew3)
{
    cout<<"\nDoing double rotation, ie LR ";
	nnew3->left= rleft(nnew3->left);
	nnew3= rright(nnew3);
	return nnew3;
}
node *dict::doubleRL(node *nnew4)
{
    cout<<"\nDoing Double Rotation, ie RL ";
	nnew4->right= rright(nnew4->right);
	nnew4= rleft(nnew4);
	return nnew4;
}
node *dict::ins(node *root,string word,string mean){
    node *tmp99= new node;
    int lh,rh;
	if(root!=NULL){
        root->level= height(root);
	}
    if(root==NULL){
		tmp99->key= word;
		tmp99->value= mean;
		tmp99->left= NULL;
		tmp99->right= NULL;
        root= tmp99;
    }
    else{
		if(word<root->key){
            root->left= ins(root->left,word,mean);
			cout<<"\nBalance Factors: "<<balance(root);
            if(balance(root)==2){
                if(word<root->left->key){
                    root= singleLL(root);
                }
				else{
                    root= doubleLR(root);
                }
            }
		}
		else{
			if(word>root->key){
                root->right= ins(root->right,word,mean);
                cout<<"\nBalance Factors: "<<balance(root);
                if(balance(root)==- 2){
                    if(word>root->right->key){
                        root= singleRR(root);
                    }
					else{
						root= doubleRL(root);
                    }
                }
            }
			else{
                cout<<"\nSame word exists already!!";
			}
		}
    }
	root->level= height(root);
    return root;
}
int dict::look(node *root,string key99)
{
    cmp= 0;
    bool flag= false;
    node *tmp11= root;
    while(tmp11!=NULL){
        if(tmp11->key==key99){
            cmp++;
		    itr= tmp11;
		    flag= true;
            break;
        }
		else{
			if(key99<tmp11->key){
                tmp11= tmp11->left;
            }
			else{
				tmp11= tmp11->right;
            }
        }
    }
	if(flag!=true){
        cout<<"\n"<<key99<<" can't be found!!";
        return 0;
    }
	else{
        cout<<"\nNumber of comparisons needed is: "<<cmp<<endl;
		cout<<"Word:Meaning :: "<<itr->key<<":"<<itr->value<<endl;
		return 1;
    }
}
void dict::change(node *root,string old,string nkey){
	int ans= look(root,old);
	if(ans!=0){
        itr->value= nkey;
        cout<<"\nAfter updation (Word:Meaning :: "<<itr->key<<":"<<itr->value<<")";
	}
}
void dict::asc(node *root){
	if(root!=NULL){
        asc(root->left);
        if(root->value!=""){
		cout<<root->key<<":"<<root->value<<endl;
        }
		asc(root->right);
	}
}
void dict::dsc(node *root){
	if(root!=NULL){
		dsc(root->right);
		if(root->value!=""){
		cout<<root->key<<":"<<root->value<<endl;
		}
		dsc(root->left);
	}
}
int main()
{
	cout<<"Improvised by MSanathoi"<<endl;
	dict obj;
	int choice;
	//,no_of_nodes,f;
	string word, eqvl;
	cout<<"\n1. Enter new word in dictionary.";
	cout<<"\n2. Update the meaning of a word.";
	cout<<"\n3. Delete a particular entry.";
	cout<<"\n4. Look for a word.";
    cout<<"\n5. Sort dictionary in (A-Z) fashion.";
	cout<<"\n6. Sort dictionary in (Z-A) fashion.";
	cout<<"\nPress any other key to exit.";
	cout<<"\n\nPlease specify your choice: ";   cin>>choice;
	while(choice<7){
		switch(choice){
            case 1: {cout<<"\nEnter the (Word:Meaning) pair: ";  cin>>word>>eqvl;
                obj.root= obj.ins(obj.root,word,eqvl);
                break;}
            case 2: {cout<<"\nWhich word to update? What will be the new meaning?"<<endl;
                cin>>word>>eqvl;
                obj.change(obj.root,word,eqvl);
                break;}
            case 3: {cout<<"\nWhich word to delete? ";       cin>>word;
                string val= "";
                obj.change(obj.root,word,val);
                break;}
            case 4: {cout<<"\nWhat is the word to be searched: ";
                cin>>word;
                obj.look(obj.root,word);
                break;}
            case 5: {cout<<"\nWords in (A-Z) fashion: ";
			    obj.asc(obj.root);
                break;}
            case 6: {cout<<"\nWords win (Z-A) fashion: ";
                obj.dsc(obj.root);
                break;}
		}
		cout<<"\nPlease specify your choice: ";   cin>>choice;
	}
	return 0;
}
