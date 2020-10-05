#include<bits/stdc++.h>
using namespace std;
class Student
{
    public:
    int rollNumber;

    private:
    int age;

    public:
    ~Student()
    {
        cout<<"Destructor called !"<<endl;
    }

    //Default Constructor
    
    Student()
    {
        cout<<"Default Contructor called !!"<<endl;
    }
    
   //Paramterized constructor
   Student(int rollNumber)
   {
       cout<<"Constructor 2 called !"<<endl;
       this->rollNumber=rollNumber;
   }

   Student(int a, int r) {
		cout << "this : " << this << endl;
		cout << "Constructor 3 called ! " << endl;
		this -> age = a;
		this -> rollNumber = r;
	}

    void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}
};