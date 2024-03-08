#include<iostream>
using namespace std;
/*Doubly Linked List Code*/

class node{
    public:
    int data;
    node *next;
    node *prev;

    node(int val){ 
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class DLL{
    node *head;
    public:
    DLL(){
        head=NULL;
    }

    void insertAtEnd(int val){
        node *n=new node(val); 
        node *temp=head;

        if (head==NULL){
            insertAtBeg(val);
            return;
        }

        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }

    void insertAtBeg(int val){
        node *n=new node(val);
        n->next=head;
        if (head!=NULL){
            head->prev=n;
        }
        head=n;
    }

    void deleteAtpos(int pos){
        node *temp=head;
        int count=1;

        if (pos==1){
            deleteAtBeg();
        }

        while (temp!=NULL && count!=pos){
            temp=temp->next;
            count++;
        }
        temp->prev->next=temp->next;
        if (temp->next!=NULL){
            temp->next->prev=temp->prev;
        }

        delete temp;
    }

    void deleteAtBeg(){
        node *todelete=head;
        head=head->next;
        head->prev=NULL;

        delete todelete;
    }

    void display(){
        node* temp=head;
        cout<<"NULL <-> ";
        while (temp!=NULL){
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
                    
int main(){
    DLL s;
    s.insertAtBeg(1);
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(4);
    s.insertAtEnd(5);
    s.display();
    s.insertAtBeg(7);
    s.display();

    return 0;
}