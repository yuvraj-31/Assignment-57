/*
8. Write a Program to reverse the Doubly Linked List.*/


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
    void reverse()
    {
        node *t=head;
        node *p=head;
        int l=0;
        while(t->next!=NULL)
        {
            t=t->next;
             l++;
        }
        l=(l+1)/2;
        while(l)
        {
            int y=p->data;
            p->data=t->data;
            t->data=y;


            p=p->next;
            t=t->prev;
            l--;

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
     cout<<endl<<"After reversing"<<endl;
    l1.reverse();
     l1.print();


    return 0;
}


