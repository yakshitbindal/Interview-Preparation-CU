/*

Even after Odd LinkedList

For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

*/

Node *evenAfterOdd(Node *head)
{   
	//write your code here
    if(head==NULL)
        return NULL;
    Node* evenH=NULL;
    Node* evenT=NULL;
    Node* oddH=NULL;
    Node* oddT=NULL;
    while(head!=NULL)
    {
        Node *n=new Node(head->data);
        if(head->data%2==0)
        {
            
            if(evenH==NULL)
            {//see if u assign head to even head then all the next node are also with head
                //like 2->3->4->6
                //here 2 is even and head 
                //when u assign it to ecen head all the node that are next to head are also a part of even head now
                //while new node will create a node with 2 only 
                //get it?
                
                evenH=n;
                evenT=n;
            }
            else
            {//here let say event was at 100
                //now it event->next is head let say 200
                //then even t is head
                //no
                evenT->next=n;
                evenT=n;
            }
        }
        else
        {
            if(oddH==NULL)
            {
                oddH=n;
                oddT=n;
            }
            else
            {
                oddT->next=n;
                oddT=n;
            }
        }
        head=head->next;
    }
    if(oddH!=NULL)
    	oddT->next=evenH;
    else
        oddH=evenH;
    return oddH;
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}