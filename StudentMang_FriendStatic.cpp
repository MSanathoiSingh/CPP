#include<iostream>
#include<string>
const int MAX=45;
using namespace std;
class Student
{
private:
    string name, clas, div, dob, blood;
    int roll;
public:
    static int ctflag;
    friend class personal_info;
    Student()
    {
        name= "";
        clas= "";
        div= "";
        dob= "";
        blood= "";
        roll= 0;
    }
    static void show(){cout<<"Total number of students is/are: "<<ctflag<< endl;}
};
int Student::ctflag=0;
class personal_info
{
private:
    string address, license;
    string mobile;
public:
    personal_info()
    {
        address= "";
        mobile= " ";
        license= "";
    }
    friend class Student;
    void GetData(Student *var);
    void show(Student *obj);

};
void personal_info::GetData(Student *var)
{
    cout<<"\nRoll No: ";      cin>>var->roll;
    cout<<"Student's Name: ";       cin>>var->name;
    cout<<"Class: ";        cin>>var->clas;
    cout<<"Division: ";     cin>>var->div;
    cout<<"Date Of Birth: ";        cin>>var->dob;
    cout<<"Blood Group: ";  cin>>var->blood;
    cout<<"Address : ";     cin>>this->address;
    cout<<"Mobile number: ";        cin>>this->mobile;
    cout<<"Driving License number: ";       cin>>this->license;
    Student::ctflag++;
};
void personal_info::show(Student *obj)
{
    cout<<"Roll No: "<<obj->roll<<endl;
    cout<<"Name: "<<obj->name<<endl;
    cout<<"Class: "<<obj->clas<<endl;
    cout<<"Division: "<<obj->div<<endl;
    cout<<"Date Of Birth: "<<obj->dob<<endl;
    cout<<"Blood Group: "<<obj->blood<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"Mobile number: "<<this->mobile<<endl;
    cout<<"Driving License number: "<<this->license<<endl;
};
int main()
{
    Student *census[MAX];
    personal_info *dataa[MAX];
    int i= 0, ch;
    do
    {
        cout<<"\n1. Enter new record"<<endl;
        cout<<"2. Display records"<<endl;
        cout<<"3. Display number of records."<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: census[i]= new Student;
                dataa[i]= new personal_info;
                dataa[i]->GetData(census[i]);
                i++;
                break;
            case 2: cout<<"Students are: "<<endl;
                for(int p=0; p<i; p++)
                {
                    cout<<"\nStudent "<<p+1<<endl;
                    dataa[p]->show(census[p]);
                };
                break;
            case 3: Student::show();
                break;
            case 4: break;
            default: cout<<"\nEnter valid choice."<<endl;
                break;
        }
    }while(ch!=0&&ch!=4);
    return 0;
};
