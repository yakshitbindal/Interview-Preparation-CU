/*

Next Number

Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 

*/

Node* reverse(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* nxt=head->next;
    while(nxt!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=nxt;
        nxt=nxt->next;
    }
    curr->next=prev;
    return curr;
}

Node* addOne(Node* head)
{
    int carry=0;
    bool add=1;
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL)
    {
        int res=temp->data+carry;
        if(add==1)
        {
            res++;
            add=0;
        }
        if(res>9)
        {
            res=res%10;
            carry=1;
        }
        temp->data=res;
        prev=temp;
        temp=temp->next;
    }
    if(carry==1)
    {
        Node* a=new Node(1);
        prev->next=a;
    }
    return head;
}

Node* NextLargeNumber(Node *head) {
    if(head==NULL)
        return NULL;
    Node* h1=reverse(head);
    Node* h2=addOne(h1);
    return reverse(h2);
}

//main code

#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
#include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}