/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void and_en(string pt){
    for(char i: pt){
        char var=(int(i) & 127);
        cout<<var;
    }
}
void or_en(string pt){
    for(char i: pt){
        char var=(int(i) | 127);
        cout<<var;
    }
}
void xor_en(string pt){
    for(char i: pt){
        char var=(int(i) ^ 127);
        cout<<var<<"";
    }
}
int main()
{
    string inp;
    cout<<"Enter the string to encrypt: ";      cin>>inp;
    cout<<"\nEncrypting using AND: "<<endl;
    and_en(inp);
    cout<<"\nEncrypting using OR: "<<endl;
    or_en(inp);
    cout<<"\nEncrypting using XOR: "<<endl;
    xor_en(inp);
    return 0;
}
