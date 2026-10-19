#include<iostream>
using namespace std;
void heapify(int heap[],int parnt,int maxx)
{
    int lloc= 2*parnt;
    int rloc= (2*parnt)+1;
    int root= parnt;
    if(lloc<= maxx && heap[parnt]<heap[lloc]){root= lloc;}
    if(rloc<= maxx && heap[root]<heap[rloc]){root= rloc;}
    if(root!=parnt){
        int tmp= heap[root];
        heap[root]= heap[parnt];
        heap[parnt]= tmp;
        heapify(heap,root,maxx);
    }
}
void build(int heap[],int maxx){
    //cout<<"Entered"<<endl;
    for(int i=maxx/2;i>=0;i--)
        heapify(heap,i,maxx);
}

int main(){
    cout<<"Code By MSanathoi"<<endl;
    int n;
    cout<<"Number of students to record marks: ";       cin>>n;
    int heap[n];
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter marks scored by "<<i+1<<"th student: ";       cin>>heap[i];
    }
    build(heap,n-1);
    int maxx= n-1;
    for(int l=n-1;l>=1;l--){
        //cout<<"Swap"<<endl;
        int tmp= heap[0];
        heap[0]= heap[l];
        heap[l]= tmp;
        --maxx;
        heapify(heap,0,maxx);
    }
    cout<<"Marks obtained by the students are: ";
    for(int p=0;p<n;p++){
        cout<<heap[p]<<" ";
    }
    cout<<"\nMinimum marks scored is: "<<heap[0]<<endl;
    cout<<"Maximum marks scored is: "<<heap[n-1]<<endl;
    return 0;
}
