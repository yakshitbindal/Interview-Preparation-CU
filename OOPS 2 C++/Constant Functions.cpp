//Explanation at the end

#include<bits/stdc++.h>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

    public:
    Fraction()
    {

    }

    Fraction(int numerator,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    void setNumerator(int n)
    {
        numerator=n;
    }

    void setDenominator(int d)
    {
        denominator=d;
    }

    void print() const
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
};

int main()
{
    Fraction f1(10,2);
    Fraction f2(15,4);

    //we can also make constant objects
    Fraction const f3; //with constant objects we can only call constant functions
    //constant functions: those doesn't change any property of current object

    cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;
}