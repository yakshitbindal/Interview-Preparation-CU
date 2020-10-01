#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="abc";
    cout<<s<<endl;

    string *p=new string;
    *p="def";
    cout<<p<<endl;
    cout<<*p<<endl;

    //input string
    string sp;
    cin>>sp;
    getline(cin,sp);

    string s1=s+sp;
}