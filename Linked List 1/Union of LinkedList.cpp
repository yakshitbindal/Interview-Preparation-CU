/*

Union of LL

Given a two Linked Lists, find out union of both given input lists and return the new Linked List.
Order of elements are not important.
Note : You don't need to print the linked list, just return the head. It will be printed internally.
Input format :

Line 1 : Linked list 1 elements (separated by space and terminated by -1)

Line 2 : Linked list 2 elements (separated by space and terminated by -1)

Sample Input 1 :
1 2 3 4 -1
8 7 5 3 -1
Sample Output 1 :
1
2
3
4
8
7
5
Sample Input 2 :
1 2 1 1 -1
8 -1
Sample Output 2 :
1
2
1
1
8

*/

ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
{
	ListNode<int>* result = NULL;
  	ListNode<int>* tail = NULL;
  	ListNode<int>* temp = head1;
  	while (temp != NULL) 
	{
    	ListNode < int > * n = new ListNode < int > (temp -> data);
    	if (result == NULL) 
		{
      		result = n;
      		tail = result;
    	} 
		else 
		{
      		tail -> next = n;
      		tail = n;
    	}
    	temp = temp -> next;
  	}

  	temp = head2;

	while (temp != NULL) 
	{
		ListNode < int > * temp2 = head1;
		while (temp2 != NULL) 
		{
			if (temp2 -> data == temp -> data) 
			{
				temp2 -> data = -1;
				break;
			}
			temp2 = temp2 -> next;
		}
		if (temp2 == NULL) 
		{
			ListNode < int > * n = new ListNode < int > (temp -> data);
			if (result == NULL) 
			{
				result = n;
				tail = result;
			}
			else 
			{
				tail -> next = n;
				tail = n;
			}
		}
		temp = temp -> next;
	}
	return (result);
}


//main code

#include <iostream>
using namespace std;

template <typename T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};

#include "solution.h"

 ListNode<int>* createlist()
	{
	    ListNode<int> *head=NULL;
		ListNode<int> *rear=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
			ListNode<int> *newnode=new ListNode<int>(data);
			if(head==NULL)
			{
				head=newnode;
				rear=head;
			}
			else
			{
				rear->next=newnode;
				rear=rear->next;
			}
			cin>>data;
		}
		return head;
	}

    void print(ListNode<int> * head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<endl;
			head=head->next;
		}
	}

int main()
{
   ListNode<int> *head1=createlist();
   ListNode<int> *head,*head2=createlist();
   head=unionOf2LL(head1,head2);
   print(head);
}
