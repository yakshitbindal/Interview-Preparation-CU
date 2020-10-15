/*

Divide linked list in two

Write a function that takes one list and divides up its nodes to create two smaller lists A and B. The sub lists should be made from alternating elements in the original list.
Nodes should be in the reverse order of which they occurred in the source list.
Print both linked lists in different lines.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Line 1 : Output Linked List 1 elements (separated by space)
Line 2 : Output Linked List 2 elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
 8 2 5 9 1 4 3 7 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 8.
Sample Output :
 3 1 5 8
 7 4 9 2

*/

void AlternatingSplit(Node<int>* head) {
	// Write your code here
    Node<int>* f1=NULL;
    Node<int>* f2=NULL;
    int num=1;
    while(head!=NULL)
    {
        if(num%2!=0)
        {
            if(f1==NULL)
            {
                Node<int>* n=new Node<int>(head->data);
                f1=n;
            }
            else
            {
                Node<int>* a=new Node<int>(head->data);
                a->next=f1;
                f1=a;
            }
        }
        else
        {
            if(f2==NULL)
            {
				Node<int>* n=new Node<int>(head->data);
                f2=n;
            }
            else
            {
                Node<int>* a=new Node<int>(head->data);
                a->next=f2;
                f2=a;
            }
        }
        num++;
        head=head->next;
    }
    while(f1!=NULL)
    {
        cout<<f1->data<<" ";
        f1=f1->next;
    }
    cout<<endl;
    while(f2!=NULL)
    {
        cout<<f2->data<<" ";
        f2=f2->next;
    }
}

//main code

//Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists a and b. 
//The sublists should be made from alternating elements in the original list.
//nodes should be in the reverse order of which they occurred in the source list
#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		//(*this).data = data;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};
#include "solution.h"
Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL) {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


int main()
{ 
	Node<int>* head=takeLLInput();

	AlternatingSplit(head);
	
}
