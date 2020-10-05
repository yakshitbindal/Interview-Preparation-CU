/*
Strings of Length k

Given a string S and an integer k, you need to find and return all the possible strings that can be made of size k using only characters present in string S.
The characters can repeat as many times as needed.
Note : The number of output strings can be at max 1000.
Input format :
String S and Integer k (separated by space)
Output Format :
All possible strings (in different lines)
Constraints :
1 <= Length of String S <= 10
1 <= k <= 5
Sample Input 1 :
abc 2
Sample Output 1 :
aa
ab
ac
ba
bb
bc
ca
cb
cc
*/

#include<bits/stdc++.h>
using namespace std;
int allStrings(char input[], int k, char output[][100]) {
    if(k==0)
    {
        output[0][0]='\0';
        return 1;
    }
    char smallOutput[100][100];
    int size=allStrings(input,k-1,smallOutput);
    int row=0;
    for(int i=0;input[i]!='\0';i++)
    {
        for(int j=0;j<size;j++)
        {
            int k=0;
            output[row][k++]=input[i];
            for(int l=0;smallOutput[j][l]!=0;l++)
            {
                output[row][k++]=smallOutput[j][l];
            }
            output[row][k++]='\0';
            row++;
        }
    }
    return row;
}


// main code

// #include <iostream>
// #include "solution.h"
// using namespace std;

int main() {
    char a[100];
    char b[1000][100];
    cin >> a;
    int k;
    cin >> k;
    int size = allStrings(a, k, b);
    for(int i = 0; i < size; i++) {
        cout << b[i] << endl;
    }
    allStringsPrint(a,k);
}


//print wali approach
#include <bits/stdc++.h>
using namespace std;

void helper(char input[],int size,int k,string output)
{
    if(k==0)
    {
        cout<<output<<endl;
        return;
    }
    if(size==0)
    {
        return;
    }
    string s=output;
    for(int i=k;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            output+=input[0];
        }
        helper(input+1,size-1,k-i,output);
        output=s;
    }
    return;
}

void allStringsPrint(char input[],int k)
{
    string output="";
    int size=strlen(input);
    helper(input,size,k,output);
}
int main() {
    char a[100];
    cin >> a;
    int k;
    cin >> k;
     allStringsPrint(a, k);
}