/*

kReverse

Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 4 -> 5
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10 

*/

pair<Node*,Node*> reverse(Node* head,Node* tail)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* nxt=head->next;
    while(nxt!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=nxt;
        nxt=nxt->next;
    }
    curr->next=prev;
    pair<Node*,Node*> p;
    p.first=curr;
    p.second=head;
    return p;
}

int length(Node* head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}

Node *kReverse(Node *head, int k)
{
	if(k==0 || head==NULL || k==1)
        return head;
  if(k>=length(head))
  {
      return(reverse(head,NULL).first);
  }
    int count=0;
    Node* h1=NULL;
    Node* t1=NULL;
    Node* temp=head;
    while(count!=k)
    {
        if(h1==NULL)
        {
            h1=temp;
            t1=temp;
        }
        else
        {
            t1->next=temp;
            t1=t1->next;
        }
        temp=temp->next;
        count++;
    }
    Node* h2=t1->next;
    t1->next=NULL;
    pair<Node*,Node*> p=reverse(h1,t1);
    Node* remHead=kReverse(h2,k);
    p.second->next=remHead;
    return p.first;
}

//main code
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}