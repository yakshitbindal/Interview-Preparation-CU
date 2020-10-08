#include<bits/stdc++.h>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

    public:
    Fraction(int numerator,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }

    void print()
    {
        cout<<numerator<<"/"<<denominator<<endl;
    }

    void simplify()
    {
        int gcd=1;
        int j=min(numerator,denominator);
        for(int i=1;i<j;i++)
        {
            if(numerator%i==0 && denominator%i==0)
            {
                gcd=i;
            }
        }
        numerator/=gcd;
        denominator/=gcd;
    }

    void add(const Fraction &f2)
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=x*numerator+(y*f2.numerator);
        
        numerator=num;
        denominator=lcm;
        
        simplify();
    }

    void multiply(const Fraction &f2)
    {
        numerator*=f2.numerator;
        denominator=f2.denominator;
        simplify();
    }

    //+ operator overloaded
    Fraction operator+(Fraction const &f2) const
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=x*numerator+(y*f2.numerator);

        Fraction fNew(num,lcm);
        fNew.simplify();
        return fNew;
    }

    //*operator overloaded
    Fraction operator*(Fraction const &f2) const
    {
        int num=(numerator*f2.numerator);
        int deno=(denominator*f2.denominator);
        Fraction fNew(num,deno);
        fNew.simplify();
        return fNew;
    }

    //==operator overloaded
    bool operator==(Fraction const &f2) const
    {
        return (numerator==f2.numerator) && (denominator==f2.denominator);
    }

    //++operator overloaded pre increment
    Fraction& operator++()
    {
        numerator+=denominator;
        simplify();
        return *this;
    }

    //psot increment
    Fraction operator++(int)
    {
        Fraction fNew(numerator,denominator);
        numerator+=denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction& operator+=(Fraction const &f2)
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=x*numerator+(y*f2.numerator);

        numerator=num;
        denominator=lcm;
        simplify();

        return *this;
    }
};

int main()
{
    Fraction f1(10,2);
    Fraction f2(15,4);
    
    (f1+=f2) += f2;

    f1.print();
    f2.print();

    /*
    Fraction f3=f1++;
    f1.print();
    f3.print();
    */

    /*
    f1.print();
    Fraction f3=++(++f1);
    f1.print();
    f3.print();
    */

    /*
    Fraction f3=f1+f2;
    Fraction f4=f1*f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();

    if(f1==f2)
        cout<<"Equal"<<endl;
    else
        cout<<"Not equal"<<endl;
    */
}