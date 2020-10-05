/*
Generate all parenthesis
Send Feedback
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
Input format :
Integer n
Output format :
Print all possible valid parenthesis in different lines
Note: Order in which different combinations of well-formed parentheses are printed in different lines doesn't matter.
Constraints :
1 <= n <= 10
Sample Input :
3
Sample Output :
((()))
(()())
(())()
()(())
()()()
*/

/*
Approach used: 
1) we will be having count of number of open and close brackets and a output string in our helper function
2) then base case if open and close are both zero then print output
3) we will check if count of open>0 then we will call at open-1 and we will include '(' in output
4) we will check if close>open (otherwise it will make it invalid) then we will call at close-1 and we will include ')' in output
*/

#include<bits/stdc++.h>
using namespace std;
void helper(int n,int open,int close,string output)
{
    if(open==0 && close==0)
    {
        cout<<output<<endl;
        return;
    }
    if(open>0)
        helper(n,open-1,close,output+'(');
    if(close>open)
        helper(n,open,close-1,output+')');
}
void printWellFormedParanthesis(int n){
    string s="";
    helper(n,n,n,s);
}

//main code

// #include <iostream>
// using namespace std;
// #include "solution.h"

int main() {
    int n;
    cin >> n;
    printWellFormedParanthesis(n);
}
