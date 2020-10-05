#include<bits/stdc++.h>
using namespace std;
#include "Student.cpp"

int main()
{
    Student s1;  //constructor 1 called

    Student s2(101); //constructor 2 called

    Student s3(20,102); //constructor 3 called

    Student s4(s3);  //copy constructor

    s1=s2;  //copy assignment operator

    Student s5=s4;   //same as copy constructor

    

    /*
    Student s1(10,1001);
    Student s2(20,2001);

    Student *s3=new Student(30,3001);

    s2=s1;

    *s3=s1;

    s2=*s3;

    delete s3; //to delete dynamic objec as in s3 there is only address to delete objects values we have to delete that
    */

    /*
    Student s1(10,1001);
    cout<<"S1: ";
    s1.display();

    Student s2(s1);
    cout<<"S2: ";
    s2.display();

    Student *s3=new Student(20,2004);
    cout<<"S3: ";
    s3->display();

    Student s4(*s3);

    Student *s5=new Student(*s3);
    Student *s6=new Student(s1);
    */
}