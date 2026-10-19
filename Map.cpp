#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    map<string, int> str;
    map<string, int>::iterator itr= str.begin();
    int ch;
    string name;
    int pop, flag;
    while(1){
        cout<<"\n1. Enter the State"<<endl;
        cout<<"2. Show the Records"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;            cout<<endl;
        cin.ignore(1);
        switch(ch)
        {
        case 1:
            cout<<"Enter State: \n";
            getline(cin, name);
            cout<<"Enter Population\n";
            cin>>pop;
            cin.ignore(1);
            str.insert(pair<string, int>(name, pop));
            break;
        case 2:
            itr= str.begin();
            cout<<"\nState---Population\n";
            while(itr!=str.end())
            {
                cout<<endl;
                cout<<itr->first<<"---"<<itr->second;
                itr++;
            }
            break;
        case 3:
            flag= 0;
            cout<<"Enter State: \n";
            getline(cin, name);
            itr= str.begin();
            while(itr!=str.end())
            {
                if(name==itr->first)
                {
                    flag= 1;
                    cout<<"Population of "<<name<<" is "<<str[name]<< endl;
                }
                itr++;
            }
            if(flag==0)
            {
                cout<<"\nNot found\n";
            }
            break;
        case 0: exit(0);
        }
    }
    return 0;
}
