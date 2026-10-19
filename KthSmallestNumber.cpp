#include <iostream>
using namespace std;
int kth(int arr[],int l,int r,int k){
    int mn= arr[l];                             //setting minimum threshold
    int diff;
    int diffa[100000]= {};                      //array to store difference of array
    for(int i=l+1;i<=r;i++){                    //loop to find minimum element
        if(mn>arr[i]){
            mn= arr[i];                         //minimum element
        }
    }
    for(int s=l;s<=r;s++){                      //loop to calculate difference of min & current element
        diff= arr[s]-mn;
        diffa[diff]= arr[s];                    //storing element at index equal to its difference with min
    }
    for(int itr=0;itr<500;itr++){               //loop to iterate array storing difference
        if(diffa[itr]!=0){                      //condition to avoid empty slots
            k--;    mn= diffa[itr];             //variable store minimum element
        }
        if(k==1){break;}                        //exit loop if value of 'k' reached
    }
    return mn;                                  //return minimum element
};
int main()
{
    int arr[10]= {23,15,26,46,123,45,486,26,486,123};
    cout<<kth(arr,0,9,7);
    return 0;
}
