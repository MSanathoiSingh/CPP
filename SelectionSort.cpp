/* Selection Sort by M Sanathoi Singh */

#include <iostream>
using namespace std;
void inparr(int arr[],int n){										// method to add elements for sorting
    int el;
    for(int i=0;i<n;i++){
        cout<<i+1<<"th element is: ";  cin>>el;     cout<<endl;		// taking input from user
        arr[i]= el;													// appending numbers in unsorted initial list
    }
};
void disparr(int arr[],int n){										// method to display the array
    for(int i=0;i<n;i++){											// traversing through array and displaying the elements
        cout<<"\t"<<arr[i];
    }
    cout<<endl;
};
void swapfn(int *x,int *y){											// method to swap numbers
    int tmp;
    tmp= (*x);
    (*x)= (*y);
    (*y)= tmp;
}
void selection(int arr[],int n){ 									// method for selection sort
    int minv,i,loc;
    for(int o=0;o<n;o++){											// traversal of sorted list
        bool flag= false;											// initializing flag
        minv= arr[o];												// last element of sorted list is minimum element among unsorted list
        for(i=o+1;i<n;i++){											// traversing unsorted list to find minimum element
            if(minv>arr[i]){										// checking the current element to be less than minimum element
                minv=arr[i];										// if current is minimum, store current as minimum element
                loc=i;												// taking index of minimum element in variable
                flag= true;											// indicating minimum element is found
            }
        }
        if(flag==true){												// if minimum element found in unsorted list
            swapfn(&arr[o],&arr[loc]);								// swap last element of sorted list with minimum element found
        }
    }
};
int main()
{
    int sz;
    cout<<"Enter size of the array: ";  cin>>sz;					// taking number of elements to sort from user
    cout<<endl;
    int arr1[sz];
    inparr(arr1,sz);												// taking elements to sort from user
    cout<<"Array to be sorted is: ";
    cout<<endl;
    disparr(arr1,sz);												// displaying raw elements
    cout<<"Sorted array is: ";
    cout<<endl;
    selection(arr1,sz);												// performing selection sort on unsorted elements
    disparr(arr1,sz);												// displaying the sorted list
    return 0;
}
