#include<bits/stdc++.h>
using namespace std;

void combinationsOfQueens(int totalQueen,int curr_Queen,bool place[],int size,string ans,int lastQueenPlaced)
{
    if(curr_Queen>totalQueen)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=lastQueenPlaced+1;i<size;i++)
    {
        if(place[i]==false)
        {
            place[i]=true;
            combinationsOfQueens(totalQueen,curr_Queen+1,place,size,ans+"Q"+" "+"B"+to_string(i)+" ",i);
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
    combinationsOfQueens(2,1,place,4,"",-1);
}