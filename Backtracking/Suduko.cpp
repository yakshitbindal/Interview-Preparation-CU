/*
Code : Sudoku
Send Feedback
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

#include<bits/stdc++.h>
using namespace std;


bool rowCheck(int board[][9],int row,int t)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==t)
            return false;
    }
    return true;
}

bool columnCheck(int board[][9],int column,int t)
{
    for(int j=0;j<9;j++)
    {
        if(board[j][column]==t)
            return false;
    }
    return true;
}
bool boxCheck(int board[][9],int a,int b,int t)
{
    for(int i=a;i<(a+3);i++)
    {
        for(int j=b;j<(b+3);j++)
        {
            if(board[i][j]==t)
                return false;
        }
    }
    return true;
}

bool helper(int board[][9],int i,int j)
{
    //base value
    if(i==8 && j==8)
    {
        if(board[i][j]==0)
        {
            for(int t=1;t<=9;t++)
            {
                if(rowCheck(board,i,t) && columnCheck(board,j,t) && boxCheck(board,6,6,t))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return true;
        }
    }
    
    //now check for all values
    bool ans;
    if(board[i][j]==0)
    {
        for(int t=1;t<=9;t++)
        {
			if(rowCheck(board,i,t) && columnCheck(board,j,t) && boxCheck(board,3*(i/3),3*(j/3),t))
            {
                board[i][j]=t;
                if(j<8)
                    ans=helper(board,i,j+1);
                if(j==8)
                    ans=helper(board,i+1,0);
                
            }
        }
        //if still unable to find value
        if(board[i][j]==0)
        {
            return false;
        }
        if(ans==true)
        {
            return true;
        }
        board[i][j]=0;
    }
    else
    {
        if(j<8)
            ans=helper(board,i,j+1);
        if(j==8)
            ans=helper(board,i+1,0);
    }
    return ans;
}

bool sudokuSolver(int board[][9]){
    return helper(board,0,0);
}



//Main Code
#include<iostream>
using namespace std;
//#include "Solution.h"

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}