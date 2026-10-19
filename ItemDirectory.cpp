#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class item
{
private:
    string name;
    int quant, code;
    float cost;
public:
    item()
    {
        name= "";
        quant=code= 0;
        cost= 0.0;
    };
    bool operator==(const item &obj)
    {
        if(code==obj.code){return 1;}
        return 0;
    };
    bool operator<(const item &obj)
    {
        if (code<obj.code){return 1;}
        return 0;
    };
    static void display(item &var)
    {
        cout<<"Name= "<<var.name<<endl;
        cout<<"Code= "<<var.code<<endl;
        cout<<"Quantity= " <<var.quant<<endl;
        cout<<"Cost= "<<var.cost<<endl;
        cout<<endl;
    };
    void print();
    void get();
    void search();
    friend bool CompCost(const item &, const item &);
    friend bool CompCode(const item &, const item &);
};
vector<item> v;
bool CompCost(const item &obj, const item &obj1)
{
    return obj.cost<obj1.cost;
};
bool CompCode(const item &var, const item &var1)
{
    return var.code<var1.code;
};
void item::get()
{
    item i;
    cout<<"Item name: \n";          cin>>i.name;
    cout<<"Item code: \n";          cin>>i.code;
    cout<<"Quantity available: \n"; cin>>i.quant;
    cout<<"Item cost: \n";          cin>>i.cost;
    v.push_back(i);
};
void item::print()
{
    for_each(v.begin(), v.end(), display);
};
void item::search()
{
    vector<item>::iterator itr;
    item ob;
    cout<<"\nEnter code to search:\n";
    cin>>ob.code;
    itr= find(v.begin(), v.end(), ob);
    if(itr==v.end()){cout<<"Item Not found\n";}
    else
    {
        cout<<"Name= "<<itr->name<<endl;
        cout<<"Code= "<<itr->code<<endl;
        cout<<"Quantity= "<<itr->quant<<endl;
        cout<<"Cost= "<<itr->cost<<endl;
    }
};
int main()
{
    item obj;
    int ch;
    do
    {
        cout<<"\n1. Add an Item"<<endl;
        cout<<"2. Display the Records"<<endl;
        cout<<"3. Search the Record"<<endl;
        cout<<"4. Sort according to Cost"<<endl;
        cout<<"5. Sort according to Code"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;        cout<<endl;
        switch (ch)
        {
        case 1: obj.get();
            break;
        case 2: obj.print();
            break;
        case 3: obj.search();
            break;
        case 4: sort(v.begin(), v.end(), CompCost);
            cout<<"Sorted Records are: "<<endl;
            obj.print();
            break;
        case 5: sort(v.begin(), v.end(), CompCode);
            cout<<"Sorted Records are: "<<endl;
            obj.print();
            break;
        case 6: break;
        default: cout<<"Give valid choice"<<endl;
        }
    } while(ch!=6);
    return 0;
}
