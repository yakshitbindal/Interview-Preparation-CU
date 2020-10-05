/*
Strings of Length k
Send Feedback
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
    
}

//print wali approach
void allStringsPrint(char input[],int k)
{
    
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
}
