#include <iostream>
#include <string>
using namespace std;

class Publication
{
public:
    string title;
    float price;
    void get()
    {
        cout<<"Enter title: ";              cin>>title;
        cout<<"Enter price: ";              cin>>price;
    }
    void show()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
};
class Book : public Publication
{
    int page;
public:
    Book()
    {
        title= "";
        price= 0.0;
        page= 0;
    }
    void get()
    {
        cout<<"Enter Book's detail"<<endl;
        Publication::get();
        cout<<"Enter number of pages: ";
        cin>>page;
    }
    void show()
    {
        cout<<"\t--Book Details--"<<endl;
        Publication::show();
        cout<<"Pages: "<<page<< endl;
    }
};
class Tape : public Publication
{
    float PlayingTime;
public:
    Tape()
    {
        title = "";
        price = 0.0;
        PlayingTime = 0.0;
    }
    void get()
    {
        cout<<"Enter Tape details: "<<endl;
        Publication::get();
        cout<<"Enter Playing Time: ";
        cin>>PlayingTime;
    }
    void show()
    {
        cout<<"\t--Tape Dwtails--"<<endl;
        Publication::show();
        cout<<"Playing Time: "<<PlayingTime<<endl;
    }
};
int main(void)
{
    Book obj1;
    Tape obj2;
    obj1.get();
    obj2.get();
    obj1.show();
    obj2.show();
    return 0;
}
