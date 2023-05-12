/*
10. Given a doubly linked list containing N nodes, the task is to remove all the nodes
from the list which contains Fibonacci numbers.
Example:
Input: DLL = 15 <=> 16 <=> 8 <=> 7 <=> 13
Output: 15 <=> 16 <=> 7
Explanation:
The linked list contains two fibonacci numbers 8 and 13.
Hence, these nodes have been deleted.
Input: DLL = 5 <=> 3 <=> 4 <=> 2 <=> 9
Output: 4 <=> 9
Explanation:
The linked list contains three fibonacci numbers 5, 3 and 2.
Hence, these nodes have been deleted.
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
    int checkfibo(int n)
    {
        int a=-1,b=1;
        int c=0;
        while(c<=n)
        {
            c=a+b;
            a=b;
            b=c;
            if(c==n)
                return 1;
        }

        return 0;
    }
    void removeelement()
    {
        node *t=head;
        while(t!=NULL)
        {
           if(checkfibo(t->data))
           {
                  if(t==head)
                  {
                      t->next->prev=NULL;
                      node *temp=t;
                      head=t->next;
                      t=t->next;
                      delete temp;
                  }
                  else
                 {
                     t->prev->next=t->next;
                   if(t->next!=NULL)
                    t->next->prev=t->prev;

                   node *temp=t;
                   t=t->next;
                   delete temp;
                 }

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
    l1.insert(6);
    l1.insert(9);

    l1.insert(8);
    l1.insert(7);
    l1.insert(11);
    l1.insert(12);
     l1.insert(13);
     l1.insert(14);
    l1.print();
     cout<<endl<<"After removing fibo no's"<<endl;
    l1.removeelement();
     l1.print();


    return 0;
}



