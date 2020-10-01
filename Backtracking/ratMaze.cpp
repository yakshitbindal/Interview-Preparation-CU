#include<bits/stdc++.h>
using namespace std;

bool hasPath(int** input,int n,int** solution,int x,int y)
{
    //to check if we hve reached the last block then it will be true
    if(x==n-1 && y==n-1)
    {
        return true;
    }

    //base case
    if(x<0 || y<0 || x>=n || y>=n || input[x][y]==0 || solution[x][y]==1)
    {
        return false;
    }

    solution[x][y]=1; //block visited

    if(hasPath(input,n,solution,x-1,y))
        return true;
    if(hasPath(input,n,solution,x+1,y))
        return true;
    if(hasPath(input,n,solution,x,y-1))
        return true;
    if(hasPath(input,n,solution,x,y+1))
        return true;
    
    solution[x][y]=false; //if it is a invalid move
    return false;
}

bool hasPath(int** arr,int n)
{
    int** solution=new int*[n];
    for(int i=0;i<n;i++)
    {
        solution[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            solution[i][j]=0;
        }
    }
    //we have made solution matrix to check whether we have considered the block or not so that we can prevent looping
    //for example
    // 1 1 0
    // 1 1 0
    // 1 1 1
    //to prevent looping in first two columns we are taking solution matrix
    return hasPath(arr,n,solution,0,0);
}

int main()
{
    int **arr;
    int n;
    cin>>n;
    arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<hasPath(arr,n)<<endl;
}