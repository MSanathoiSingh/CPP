#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<string>
using namespace std;
struct node{
    int freq;
    string name;
    int sym;
    struct node *nxt,*prv;
};
class Huffman{
public:
    struct node *head= NULL;
    void buildt(vector<tuple<int,string>>& vect){
         while(vect.size()!=2){
            sort(vect.begin(),vect.end());
            tree(get<0>(vct[0]),get<1>(vct[0]),get<0>(vct[1]),get<1>(vct[1]));
            vct.push_back(make_tuple(get<0>(vct[0])+get<0>(vct[1]),get<1>(vct[0])+get<1>(vct[1])));
            vct.erase(vct.begin());
            vct.erase(vct.begin());
         }
    }
    void tree(int n1, string s1, int n2, string s2){
        struct node *tmp2= new struct node;
        struct node *tmp1= new struct node;
        struct node *tmp= new struct node;
        if(head==NULL){
            tmp2->freq= n2;
            tmp2->name= s2;
            tmp2->sym= 1;
            tmp2->nxt= NULL;
            tmp1->freq= n1;
            tmp1->name= s1;
            tmp1->sym= 0;
            tmp1->nxt= tmp2;
            tmp->freq= n1+n2;
            tmp->name= "internal";
            tmp->sym= -1;
            tmp->nxt= tmp1;
            tmp->prv= NULL;
            tmp1->prv= tmp;
            tmp2->prv= tmp1;
            head= tmp;
        }
        else if(s1.length()>1 || s2.length()>1){
            if(s1.length()>1 && s2.length()>1){

            }
        }
        else{
            struct node *itr= new struct node;
            itr= head;
            while(itr->nxt!=NULL){
                itr= itr->nxt;
            }
            tmp2->freq= n2;
            tmp2->name= s2;
            tmp2->sym= 1;
            tmp2->nxt= NULL;
            tmp1->freq= n1;
            tmp1->name= s1;
            tmp1->sym= 0;
            tmp1->nxt= tmp2;
            tmp->freq= n1+n2;
            tmp->name= "internal";
            tmp->sym= -1;
            tmp->nxt= tmp1;
            tmp->prv= itr;
            tmp1->prv= tmp;
            tmp2->prv= tmp1;
            itr->nxt= tmp;
        }
        delete tmp,tmp1,tmp2;
    }
};
int main()
{
    cout<<"Code by MSanathoi"<<endl;
    int n,feq;
    cin>>n;
    string el;
    vector<tuple<int,string>> huff;
    for(int i=0;i<n;i++){
        cin>>feq>>el;
        huff.push_back(make_tuple(feq,el));
    }
    Huffman obj;
    obj.buildt(huff);
    return 0;
}
