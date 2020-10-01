#include<bits/stdc++.h>
using namespace std;

void subs(string input,string output[])
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    subs(input.substr(1),output);
    subs(input.substr(1),output+input[0]);
}

int main()
{
    string input;
    cin>>input;
    long long s=pow(2,input.size());
    string* output=new string[s];
    subs(input,output);
}