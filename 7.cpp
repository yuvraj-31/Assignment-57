/*
7. Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes. Here N
is a given positive integer and is smaller than the count of nodes in the linked list.*/


#include<iostream>
using namespace std;
class node{
    public:
   int data;
   node *next;
   node *prev;
   node()
   {
       next=NULL;
       prev=NULL;
   }
};
class doublyll
{
    node *head;
public:
    doublyll()
    {
        head=NULL;
    }
     void insert(int v)
    {
        node *temp=new node();
        temp->data=v;
        if(head==NULL)
        {
            head=temp;
        }
        else{
             node *t=head;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            temp->prev=t;
            t->next=temp;
        }
    }
    void rotate(int n)
    {
        node *t=head;
        while(n!=0)
        {
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->prev->next=NULL;
            t->next=head;
            t->prev=NULL;
            head->prev=t;
            head=t;
            n--;
        }
    }

    void print()
    {
        node *t=head;
        while(t!=NULL)
        {
            cout<<t->data<<" -> ";
            t=t->next;
        }
    }
};
int main()
{
    doublyll l1;
    l1.insert(10);
    l1.insert(9);

    l1.insert(8);
    l1.insert(7);
    l1.insert(11);
    l1.insert(12);
     l1.insert(13);
     l1.insert(14);
    l1.print();
     cout<<endl<<"After rotation"<<endl;
    l1.rotate(10);
     l1.print();


    return 0;
}

