#include <iostream>
int n;
int e=2;
int cprime(int x,int y){
    if (x==0){return y;}
    return gcd(y%x,y);
}
int enrypt(int p,int q,int m){
    n= p*q;
    int tot= (p-1)*(q-1);
    while(e<tot){
        if(cprime(tot,e)){break;}
        e++;
    }
    int ct= (m**e)%n;
    return ct;
}
int decrypt(){
    int k= 9;
    d= k*
}
