#include <iostream>
#define SIZE 1000000
using namespace std;

void sort012(int a[], int n){
    int init=0,init1=0;                                     //array iterator for 0 & 1
    bool fl= true;                                          //flag to exit when swap condition found
    bool fl1= true;                                         //flag to exit when swap condition found
    bool swp= true;                                         //flag to terminate the array pass
    bool pass= true;                                        //flag to mark unswapped iteration of array
    bool last= true;                                        //flag to mark last element of array
    if(n>2){                                                //avoid preset condition if size <2
    if(a[n-1]==0 && a[0]==0){                               //swap if last & first element are both 0
        while(fl){                                          //loop to iterate till swap-point (element !0)
            init++;                                         //iterator (to start from index 1)
            if(a[init-1]!=a[init]){                         //compare prev & curr element to decide swapping
                fl= false;                                  //if swap-point, break out of loop
            }
        }
        int tmp= a[init];                                   //swap last element with swap-point
        a[init]= a[n-1];
        a[n-1]= tmp;
    }
    if(a[n-1]==0 && a[0]==1){                               //swap if last & first element are 0 & 1
        while(fl1){                                         //loop to iterate till swap-point (element==2)
            init1++;                                        //iterator (to start from index 1)
            if((init1+1)==(n-1)){                           //check if next element is last or not
                fl1= false;                                 //exit loop if current element is second last
            }
            else if(a[init1]==2){                           //if not 2nd last, iterate till element is >1 i.e. '2'
                fl1= false;                                 //exit loop if swap-point found, i.e. element '2'
            }
        }
        int tmp= a[init1];                                  //swap last element with swap-point
        a[init1]= a[n-1];
        a[n-1]= tmp;
    }
    if(a[n-1]==0 && a[0]==2){                               //swap if last & first element are 0 & 2
        int tmp= a[0];                                      //swap first & last element
        a[0]= a[n-1];
        a[n-1]= tmp;
    }
    }
    while(swp){                                             //loop till array is sorted
        for(int k=0;k<n;k++){                               //loop to make pass on array
            if(k==(n-1)){                                   //check if current index is last
                last= false;                                //flag the current pass
            }
            if(a[k]>a[k+1] && last==true){                  //enter if curr element is greater & not last
                pass= false;                                //flag the swapping operation
                int p= a[k];                                //sort the adjacent element
                a[k]= a[k+1];
                a[k+1]= p;
            }
        }
        if(pass){                                           //if no swapping done, terminate program
            swp= false;                                     //set flag as false to exit loop
        }
        pass= true;                                         //reset the 'swap' flag
        last= true;
    }
};
void disp(int ar[], int l){
    for(int h=0;h<l;h++){
        cout<<ar[h]<<" ";
    }
}
int main()
{
    cout<<"Code by MSanathoi"<<endl;
    int sz;
    cout<<"Enter the array length: ";   cin>>sz;
    int arr[sz];
    for(int i=0;i<sz;i++){
        cout<<"Enter the "<<i+1<<"th element: ";  cin>>arr[i];
    }
    disp(arr,sz);
    cout<<endl;
    sort012(arr,sz);
    disp(arr,sz);
    return 0;
}
