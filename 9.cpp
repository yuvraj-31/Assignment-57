/*
9. Given a Doubly linked list containing N nodes, the task is to remove all the nodes
from the list which contains elements whose digit sum is even.
Example:
Input: DLL = 18 <=> 15 <=> 8 <=> 9 <=> 14
Output: 18 <=> 9 <=> 14
Explanation:

The linked list contains :
18 -> 1 + 8 = 9
15 -> 1 + 5 = 6
8 -> 8
9 -> 9
14 -> 1 + 4 = 5
Here, digit sum for nodes containing 15 and 8 are even.
Hence, these nodes have been deleted.
Input: DLL = 5 <=> 3 <=> 4 <=> 2 <=> 9
Output: 5 <=> 3 <=> 9
Explanation:
The linked list contains two digit sum values 4 and 2.
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
    int sumeven(int n)
    {
        int sum=0;
        while(n)
        {
            sum=sum+n%10;
            n=n/10;
        }
        if(sum%2==0)
            return 1;
        return 0;
    }
    void removeelement()
    {
        node *t=head;
        while(t!=NULL)
        {
           if(sumeven(t->data))
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
     cout<<endl<<"After removing"<<endl;
    l1.removeelement();
     l1.print();


    return 0;
}


