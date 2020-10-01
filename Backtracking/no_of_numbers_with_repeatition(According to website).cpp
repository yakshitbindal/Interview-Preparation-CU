/*
Code : No. of numbers - with duplicates
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
Input Format :
Integer n
Output Format :
Count of greater numbers
Sample Input :
122
Sample Output :
2
*/

#include<bits/stdc++.h>
using namespace std;
int numDigits(long num)
{
    int numDigit=0;
    while(num)
    {
        numDigit++;
        num/=10;
    }
    return numDigit;
}

long numof(int* input,int n,long long deno,int* fact,int* freq)
{
    //base case
    if(n==0 || n==1)
    {
        return 0;
    }

    long ans=0;
    for(int i=input[0]+1;i<10;i++)
    {
        if(freq[i]>0)
        {
            ans+=((fact[n-1]*freq[i])/deno);
        }
    }
    deno/=fact[freq[input[0]]];
    freq[input[0]]--; //next time that number should not be considered again
    deno*=fact[freq[input[0]]];
    ans+=numof(input+1,n-1,deno,fact,freq);
    return ans;
}

long numberOfNumbersWithDuplicates(long num){
	int n=numDigits(num);
    int* input=new int[n];
    for(int i=n-1;i>=0;i--)
    {
        input[i]=num%10;
        num/=10;
    }
    int* fact=new int[n+1];
    long long deno=1;
    fact[0]=1;
    int freq[10]={};
    for(int i=0;i<n;i++)
    {
        freq[input[i]]++;
        fact[i+1] = (i+1) * fact[i];
    }
    for(int i=0;i<n;i++)
    {
        if(freq[input[i]]>0)
        {
            deno*=fact[freq[i]];
        }
    }
    return numof(input,n,deno,fact,freq);
}

//main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}
