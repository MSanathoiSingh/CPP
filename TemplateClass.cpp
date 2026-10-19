#include <iostream>
using namespace std;
template<class P>
void get(P arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout<<"Enter element "<<i<<": ";
        cin>>arr[i];   // cout<<endl;
    }
};
template<class X>
void display(X arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout<<"Element of index "<<i<<" is "<<arr[i]<<endl;
    }
    cout<<endl;
};
template<class T>
void change(T *x, T *y)
{
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
template<class T>
void sort(T arr[], int n)
{
    int i, j, index;
    for(i=0; i<(n-1); i++)
    {
        index = i;
        for(j=(i+1); j<n; j++)
        {
            if(arr[index]>arr[j]){index=j;}
        }
        change(&arr[index], &arr[i]);
    }
}
int main()
{
    int *var1;
    float *var2;
    int Nint, Nfl, dec;
    do{
        cout<<"\n1. Sorting of integer array"<<endl;
        cout<<"2. Sorting of float array"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>dec;        cout<<endl;
        switch(dec)
        {
        case 1:
            cout<<"Enter number of elements: ";             cin>>Nint;    cout<<endl;
            var1= new int[Nint];
            cout<<"Input array of "<<Nint<<" integers:\n";
            get(var1, Nint);        cout<<endl;
            cout<<"Array of integers is:\n";
            display(var1, Nint);    cout<<endl;
            cout<<"Array after sorting will be:\n";
            sort(var1, Nint);
            display(var1, Nint);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter number of elements: ";             cin>>Nfl;
            var2 = new float[Nfl];
            cout<<"Input array of "<<Nfl<< " float:\n";
            get(var2, Nfl);             cout<<endl;
            cout<<"Array of float values:\n";
            display(var2, Nfl);         cout<<endl;
            cout<<"Float array after sorting:\n";
            sort(var2, Nfl);
            display(var2, Nfl);
            cout<<endl;
            break;
        case 3: break;
        default: cout<<"Give valid choice.\n";
            break;
        }
    }while(dec!=3);
return 0;
}
