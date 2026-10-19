// { Driver Code Starts
#include <iostream>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;                                    // driver method

int main() {
    int t;
    cout<<"Number of arrays to check: ";        cin >> t;
    while (t--) {
        int n;
        cout<<"Length of array: ";      cin >> n;                                               // taking array length
        ll a[n];
        cout<<"Enter "<<n<<" elements: "<<endl;
        for(int i = 0; i < n; i++){cin>>a[i];}                                                  // taking array elements
        pair<ll, ll> pp= getMinMax(a,n);
        cout<<"Minimum element is "<<pp.first<<" and maximum element is "<<pp.second<<endl;     // printing min and max
    }
    return 0;
}
// } Driver Code Ends
pair<long long, long long> getMinMax(long long a[], int n) {                                    // driver method
    long long int mn= a[0];                                                                     // stores minimum element
    long long int mx= a[0];                                                                     // stores maximum element
    for(int i=1;i<n;i++){                                                                       // iterating through element
        if(mn>a[i]){mn= a[i];}                                                                  // checking constraints
        if(mx<a[i]){mx= a[i];}
        else{continue;}
    }
    return make_pair(mn,mx);                                                                    // returning pair
}
