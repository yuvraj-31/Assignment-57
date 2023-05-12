/*5. Given an unsorted doubly linked list containing n nodes. The problem is to remove
duplicate nodes from the given list. */



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
    void removeduplicates()
    {
        node *t=head;
        node *p;
        while(t->next!=NULL)
        {
            p=t->next;
            while(p!=NULL)
            {
                if(t->data==p->data)
                {
                    p->prev->next=p->next;
                    if(p->next!=NULL)
                     p->next->prev=p->prev;

                    node *temp=p;
                    p=p->next;
                    delete temp;
                }
                else
                    p=p->next;
            }
            t=t->next;
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
    l1.insert(2);

    l1.insert(10);
    l1.insert(2);
    l1.insert(1);
    l1.insert(10);
     l1.insert(20);
     l1.insert(1);
    l1.print();
     cout<<endl;
     l1.removeduplicates();
     l1.print();


    return 0;
}

