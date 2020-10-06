#include<bits/stdc++.h>
using namespace std;
class Student
{
    int age;
    

    public:
    char *name;
    Student(int age,char* input)
    {
        this->age=age;
        
        //shallow copy
        //this->name=name;

        //Deep copy
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    //copy constructor
    Student(const Student &s)
    {
        this->age=s.age;
        //this->name=s.name; //shallow copy
        
        //deep copy
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }

    void display()
    {
        cout<<name<<" "<<age<<endl;
    }
};