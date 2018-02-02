
#include <iostream>
using namespace std;
class Node    
{
  public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
};
class StackLL  // Stack via Linked list   
{
  public:
  Node* head;
  StackLL()
  {
    head=NULL;
  }
  void push(int num);
  void pop();
  void display();
};
class StackArr  // Implementing Stack by Array 
{
             int stk[20];
             int top;
      public:
             StackArr()
              {
                top=-1;
              }
             void push(int x)
              {
                 if(top >  19)
                       {
                           cout <<"\nSTACK OVERFLOW !!!";
                           return;
                       }
                 stk[++top]=x;
                 cout <<"\nInserted " <<x<<endl;
               }
             void pop()
               {
                  if(top <0)
                   {
                         cout <<"\n \nSTACK UNDERFLOW !!!";
                         return;
                    }
                    cout <<"\nDeleted" <<stk[top--]<<endl;
                }
             void display()
               {
                   cout<<"\n \n";
                   if(top<0)
                    {
                            cout <<" EMPTY STACK !!!!";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<stk[i] <<" -> ";
                    cout<<"NULL";
                }
};
class QueueArr // Implementing Queue via Array 
{
              int queue1[20];
              int rear,front;
      public:
              QueueArr()
                {
                     rear=-1;
                     front=-1;
                }
              void enqueue(int x)
               {
                   if(rear >  19)
                    {
                       cout <<"\nQUEUE OVERFLOW !!!";
                       front=rear=-1;
                       return;
                    }
                    queue1[++rear]=x;
                    cout <<"\nInserted " <<x<<endl;
               }
              void dequeue()
               {
                   if(front==rear)
                     {
                         cout <<"\nUNDERFLOW !!!";
                         return;
                     }
                     cout <<"\nDeleted " <<queue1[++front];
                }
              void display()
               {
                   cout<<"\n";
                   if(rear==front)
                     {
                          cout <<"\nEMPTY !!!!";
                          return;
                     }
                   for(int i=front+1;i<=rear;i++)
                   cout <<queue1[i]<<" -> ";
                   cout<<"NULL";
               }
};
class QueueLL //  Queue via linked list 
{
  public:
  Node* head;
  Node* tail;
  QueueLL()
  {
    head=NULL;
    tail=NULL;
  }
  void enqueue(int num);
  void dequeue();
  void display();
};
void StackLL::push(int num) //  pushing in a stack node 
{
  Node* temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }
  temp->next=head;
  head=temp;
}
void StackLL::pop() //  popping in a stack node  
{
  Node* temp;
  if(head==NULL)
  { 
   cout<<"\nUNDERFLOW !!! The stack is empty";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  cout<<"\n"<<temp->data<<" is being deleted from the stack";
  delete temp;
}
void StackLL::display() //  displaying a stack 
{
  Node *curr = head;
  cout<<"\n";
  while (curr!=NULL)
  {
    cout << curr->data << "->" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
}
void QueueLL::enqueue(int num) //  enqueuing in a queue 
{
  Node *temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp; 
  }
  else
  {
    tail->next=temp;
  }
  tail=temp;
}
void QueueLL::dequeue() //  dequeuing a queue  
{
  Node* temp;
  if(head==NULL)
  {
   cout<<"\nQueue is empty !!!! UNDERFLOW";
   return;
  }
  temp=head;
  head=head->next;
  cout<<"\n"<<temp->data<<" is being deleted";
  temp->next=NULL;
  delete temp;
}
void QueueLL::display() //  displaying the queue 
{
 {
  Node *curr = head;
  cout<<"\n";
  while (curr!=NULL)
  {
    cout << curr->data << "->" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
 }
}
int main()
{
  StackLL SLList;
  QueueLL QLList;
  StackArr SArr;
  QueueArr QArr;
  SLList.push(12); //Checking for stack and queue by linked list
  SLList.push(23);
  SLList.push(34);
  SLList.display();
  SLList.pop();
  SLList.display();
  QLList.enqueue(12);
  QLList.enqueue(23);
  QLList.enqueue(34);
  QLList.display();
  QLList.dequeue();
  QLList.display();
  SArr.push(12);  //Checking for stack and queue by Array
  SArr.push(23);
  SArr.push(34);
  SArr.display();
  SArr.pop();
  SArr.display();
  QArr.enqueue(12);
  QArr.enqueue(23);
  QArr.enqueue(34);
  QArr.display();
  QArr.dequeue();
  QArr.display();
  return 0;
}
