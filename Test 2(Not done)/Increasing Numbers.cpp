/*
Increasing Numbers
Send Feedback
Given an integer n, print all n digit increasing numbers in increasing order in one line.
Numbers you need to print should be in increasing order and only those numbers should be printed which have digits in increasing order.
Input Format :
Integer n
Output Format :
 Numbers in increasing order
Constraints :
1 <= n <= 8
Sample Input :
2
Sample Output :
12 13 14 15 16 17 18 19 23 24 25 26 27 28 29 34 35 36 37 38 39 45 46 47 48 49 56 57 58 59 67 68 69 78 79 89 
*/

/*
Approach used: (Recursion)
1) we will be needing 3 parameters 
    -number the number will we will be making by adding digits into it
    -x to tell next where to satr next digit so that it should be increasing
    -n (already given) to count digits
2) base case- we will check if count of digits (which is n) ==0 then we will print our number
3) we will iterate from (x+1) to 9 in order to get number in increasing order
4) we will call function in that iteration with (10*number+i)
*/

#include<iostream>
using namespace std;

void helper(int number,int x,int n)
{
    if(n==0)
    {
        cout<<number<<" ";
        return;
    }
    for(int i=(x+1);i<=9;i++)
    {
        helper(number*10+i,i,n-1);
    }
}

void printIncreasingNumbers(int n)
{
    helper(0,0,n);
}

//main code

// #include<iostream>
// using namespace std;
// #include "solution.h"

int main()
{
	int n;
	cin>>n;
  printIncreasingNumbers(n);
}
