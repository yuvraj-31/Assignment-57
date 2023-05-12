  /*6. Sort the given biotonic doubly linked list. A biotonic doubly linked list is a doubly
linked list which is first increasing and then decreasing. A strictly increasing or a
strictly decreasing list is also a biotonic doubly linked list.   */




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
    void sortll()
    {
        node *t=head;
        node *p;
        while(t->next!=NULL)
        {
            p=t->next;
            while(p!=NULL)
            {
                if(t->data>p->data)
                {
                    int y=t->data;
                    t->data=p->data;
                    p->data=y;
                }
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
    l1.insert(9);

    l1.insert(8);
    l1.insert(7);
    l1.insert(11);
    l1.insert(12);
     l1.insert(13);
     l1.insert(14);
    l1.print();
     cout<<endl;
    l1.sortll();
     l1.print();


    return 0;
}

