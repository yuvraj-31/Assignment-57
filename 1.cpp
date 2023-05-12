/*
2. Given a sorted doubly linked list of positive distinct elements, the task is to find pairs
in a doubly-linked list whose sum is equal to given value x, without using any extra
space?
Example:
*/
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
    void findpairs(int x)
    {
        node *t1=head;

        while(t1->next!=NULL)
        {   node *t2=t1->next;
            while(t2!=NULL)
            {
                if(t1->data+t2->data==x)
                    cout<<"("<<t1->data<<","<<t2->data<<") ";
                t2=t2->next;
            }
            t1=t1->next;
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
    l1.insert(1);
    l1.insert(2);

    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(8);
     l1.insert(9);
    l1.print();
     cout<<endl;
    l1.findpairs(9);

    return 0;
}
