//3. Given a sorted doubly linked list and a value to insert, write a function to insert the
//value in a sorted way. Initial doubly linked list

#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node()
    {
        prev=NULL;
        next=NULL;
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
                node *p;
            while(t!=NULL)
            {
                if(t->data>v)
                {
                   int y=t->data;
                   t->data=temp->data;
                   temp->data=y;

                   temp->prev=t;
                   temp->next=t->next;
                   if(t->next!=NULL)
                     t->next->prev=temp;
                   t->next=temp;
                   return;

                }
                p=t;
                t=t->next;
            }
            p->next=temp;
            temp->prev=p;

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
    doublyll s1;
     s1.insert(2);
     s1.insert(1);
     s1.insert(21);
    s1.insert(1);
    s1.insert(15);
    s1.insert(2);
    s1.insert(1);

    s1.print();
}
