/*
1. An example of a linked list with a random pointerGiven a linked list of size N where
each node has two links: one pointer points to the next node and the second pointer
points to any node in the list. The task is to create a clone of this linked list in O(N)
time.
*/
#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int v)
    {
        data=v;
        next=NULL;
        prev=NULL;
    }

};
int main()
{
    node *head=new node(1);
    head->next=new node(2);
    head->next->prev=head;
    head->next->next=new node(3);
    head->next->next->prev=head->next;
    head->next->next->next=new node(4);
    head->next->next->next->prev=head->next;
    head->next->next->next->next=new node(5);
    head->next->next->next->next->prev=head->next->next;

  node *    t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" -> ";
        t=t->next;

    }
 /*   cout<<t->data<<" -> "<<endl;
    int x=1;
    while(x<6)
    {
        cout<<t->data<<" -> ";
        t=t->prev;
        x++;
    }   */

    return 0;
}
