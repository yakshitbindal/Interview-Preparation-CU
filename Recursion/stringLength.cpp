#include<bits/stdc++.h>
using namespace std;

void removeX(char s[])
{
    if(s[0]=='\0')
        return;
    if(s[0]=='x')
    {
        int i=1;
        for(;i<s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
    }
    else
    {
        removeX(s+1);
    }
    
}

int length(char s[])
{
    if(s[0]=='\0')
        return 0;
    return 1+length(s+1);
}
int main()
{
    char str[100];
    cin>>str;
    cout<<length(str)<<endl;
    removeX(str);
    cout<<str<<endl;
    cout<<length(str)<<endl;
}