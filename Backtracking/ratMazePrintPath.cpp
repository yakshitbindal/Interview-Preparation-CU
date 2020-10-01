#include<bits/stdc++.h>
using namespace std;

void printPath(int** input,int n,int** solution,int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        solution[x][y]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<solution[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(x<0 || y<0 || x>=n || y>=n || input[x][y]==0 || solution[x][y]==1)
    {
        return;
    }
    solution[x][y]=1;
    printPath(input,n,solution,x-1,y);
    printPath(input,n,solution,x+1,y);
    printPath(input,n,solution,x,y-1);
    printPath(input,n,solution,x,y+1);
    solution[x][y]=0;
    return;
}


void hasPath(int** arr,int n)
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
    printPath(arr,n,solution,0,0);
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
    hasPath(arr,n);
}