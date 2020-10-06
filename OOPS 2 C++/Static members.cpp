#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    int rollNumber;
    int age;

    static int totalStudents; //total number of students present
    //to access static member we have to use scope resolution

    Student()
    {
        totalStudents++;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }
    //static functions can only access static properties.
    //there is no this keyword in static functions

};

int Student::totalStudents=0; //initialize static data members

int main()
{
    Student s1;
    cout<<s1.rollNumber<<" "<<s1.age<<endl;
    cout<<Student::totalStudents<<endl;
}