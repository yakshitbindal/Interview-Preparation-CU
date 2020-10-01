/*
Problem statement:
You will be given a number(without repeatition). Find the no. of numbers grater than the given number.
e.g.: 
input: 4
3 1 2 4
output: 11

input: 
3
2 1 3
output: 3
explanation: 
312
321
231

Approach: 
1) first we will be counting digits greater than the first digit.
2) the (s-1)!
3) considering the first digit we will call recursion on remaining number
4) to do this we have to maintain freq array and factorial array
*/

#include<bits/stdc++.h>
using namespace std;

int num(int* input,int n,int* fact,int* freq)
{
    //base case
    if(n==0 || n==1)
    {
        return 0;
    }

    int ans=0;
    for(int i=input[0]+1;i<10;i++)
    {
        if(freq[i]>0)
        {
            ans+=fact[n-1];
        }
    }
    freq[input[0]]--; //next time that number should not be considered again
    ans+=num(input+1,n-1,fact,freq);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int* input=new int[n];
    int* fact=new int[n+1];
    fact[0]=1;
    int freq[10]={};
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
        freq[input[i]]++;
        fact[i+1] = (i+1) * fact[i];
    }
    cout<< num(input,n,fact,freq) << endl;
}