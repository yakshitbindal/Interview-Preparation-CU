/*
N Queens
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(bool** board,int i,int j,int n)
{
    //col check
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
            return false;
    }
    //left diagonal
    int x=i,y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y])
        {
            return false;
        }
        x--;
        y--;
    }
    //right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y])
        {
            return false;
        }
        x--;
        y++;
    }
    
    return true;
}

bool placeNQueens(bool** board,int i,int n)
{
    //base case
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return true;
    }
    
    //recursive call
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,i,j,n))
        {
            board[i][j]=1;
            bool ans=placeNQueens(board,i+1,n);
            board[i][j]=0;
        }
    }
    return false;
}

void placeNQueens(int n){
    bool** board=new bool*[n];
    for(int i=0;i<n;i++)
    {
        board[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }
    }
    bool ans=placeNQueens(board,0,n);
}

//main code

//#include<iostream>
//using namespace std;
//#include "Solution.h"

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}


