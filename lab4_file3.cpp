#include<iostream>
#include<string>
using namespace std;

// Node of a linked list. 

class snode{
    public:
    char alph;
    snode *next;
};

class node{
public:
	int pho;
    string name,desc;
	node *next; // Pointer to next node
};

class Stack{
    public:
	snode *top;

public:
	Stack(){
		top =NULL;
	}
	void push(char a){
		snode *temp = new snode;
		temp->alph = a;
		temp->next = NULL;
		if(top!=NULL){
			temp->next = top;
		}
		top = temp;
	}
	void pop(){
        if(top == NULL){
            cout<<"Nothing to pop\n";
        }
        else{
            top = top->next;
        }
    }   
};

// Function, not in a class
bool checkpal(string n){
    Stack b;
    for(int i=0;i < n.length();i++){
        b.push(n[i]);
    }
    for(int i=0;i < n.length();i++){
        if(n[i]!=b.top->alph){
            cout<<"not palindrome";
            return 0;
        }
        b.pop();
    }
    return 1;
}

class queue{
	node *head;
    node *tail;

public:
	queue(){
		head = NULL;
        tail = NULL;
	}
	void inqueue(int num,string nam, string des){
		node *temp = new node;
		temp->pho = num;
        temp->name = nam;
        temp->desc = des;
		temp->next = NULL;
        if(checkpal(nam)==1){
            temp->next = head;
            head = temp;
        }
        else {
            if (head != NULL)
                tail->next = temp;
            else
                head = temp;
            tail = temp;
        }
        show();
	}
	void dequeue(){
        if(head == NULL){
            cout<<"Queue doesn't exist";
        }
        else{
            head = head->next;
        }
	}
	void show(){
		node *curr = head;
		while (curr!=NULL){
			cout << curr->name << "\n";
            cout << curr->pho<<"\n";
            cout << curr->desc<<"\n";
			curr = curr->next;
		}
		cout << "end" <<endl;
    
	}
};


int main(){
 queue s;
    int choice;
    int x;
    string name,descrip;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\t Customer Care \n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY QUEUE\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                cout<<"Enter name: ";
                cin >>name;
                cout<<"Description:";
                cin>>descrip;
                s.inqueue(x,name,descrip);
                break;
            case 2:
                s.dequeue();
                break;
            case 3:
                s.show();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nPlease enter correct choice(1-4)!!";
                break;
        }

    }
    return 0;
}
