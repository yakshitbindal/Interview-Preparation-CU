#include<bits/stdc++.h>
using namespace std;

void placementOfQueens(int totalQueen,int curr_Queen,bool place[],int size,string ans)
{
    if(curr_Queen>totalQueen)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<size;i++)
    {
        if(place[i]==false)
        {
            place[i]=true;
            placementOfQueens(totalQueen,curr_Queen+1,place,size,ans+"Q"+to_string(curr_Queen)+" "+"B"+to_string(i)+" ");
            place[i]=false;
        }
    }
}

int main()
{
    bool place[4];
    for(int i=0;i<4;i++)
    {
        place[i]=false;
    }
    placementOfQueens(2,1,place,4,"");
}