#include<bits/stdc++.h>
#include "ourmap.h"
using namespace std;
int main()
{
    ourmap<int> map;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key+=c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;
    }

    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key+=c;
        cout<<key<<":"<<map.getValue(key)<<endl;
    }

    cout<<map.size()<<endl;
}