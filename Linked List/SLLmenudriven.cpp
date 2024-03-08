#include<iostream>
using namespace std;
/*Singly Linked List Menu Driven Code*/

class node{
    public:
    int data; //Will Store value in data field of SLL.
    node* next; //Pointer that points to the next node of the SLL.

    node(int val){ //Constructor
        data=val;
        next=NULL;
    }
};

class SLL{
    node* head; //Creates a ptr head of class node, to store address of first node in SLL.
    public:
    SLL(){
        head=NULL; //'head' is 'NULL' implies SLL is empty, Since 'head' stores address of first node.
    }
    
    /*INSERTING NODES*/
    void insertAtBegin(int val){
        node *n=new node(val); //Will create a new node and will store its address at 'n'.
        n->next=head; //The 'next field' of the first node will contain the value of head, that is NULL.
        head=n; //Since 'head' stores address of first node, it will now store  address at 'n' not NULL.
    }

    void insertAtEnd(int val){
        node *n=new node(val); //Will create a new node and will store its address at 'n'.

        if (head==NULL){ //Will check if SLL is empty.
            head=n; //Since 'head' stores address of first node, it will now store address at 'n'.
            return;
        }

        node *temp=head; // Pointer 'temp' will store address of first node.
        while (temp->next!=NULL){ //Will traverse through the SLL till it reaches the last node.
            temp=temp->next; //Pointer 'temp' will store address of next node,this is incrementing 'temp' for SLL traversal.
        }
        temp->next=n; //Will change the 'next field' of last node to address stored at 'n'.
    }

    void insertAt(int val,int pos){
        node *n=new node(val); //Will create a new node and will store its address at 'n'.
        node *temp=head; // Pointer 'temp' will store address of first node.
        for ( int i = 1; i < pos-1; i++) //Will traverse through SLL until it reaches the position after which new node has to be inserted.
        {
            temp=temp->next; //Pointer 'temp' will store address of next node,this is incrementing 'temp' for SLL traversal.
        }
        n->next=temp->next;
        temp->next=n;    
    }
    
    /*DELETING NODES*/
    void deleteAtBegin(){
        if (head==NULL){ // If 'head' is equal to 'NULL',this implies that SLL is empty and nothing has to be deleted.
            cout<<"NULL";
        }
        node *temp=head; // Pointer 'temp' will store address of first node.
        head=temp->next; // 'head' will store address of second node since first node has to be deleted.
        cout<<temp->data<<" is getting deleted"<<endl;
        delete temp; //First node is deleted.
    }

    void deleteAtEnd(){
        if (head==NULL){ // If 'head' is equal to 'NULL',this implies that SLL is empty and nothing has to be deleted.
            cout<<"NULL";
        }
        if (head->next==NULL){ //If 'next' of 'head' node is 'NULL',this means there is only 1 node in SLL and that has to be deleted.
            delete head;
            cout<<"NULL";
        }
        
        node *temp=head; // Pointer 'temp' will store address of first node.
        while (temp->next->next!=NULL){ //This mean if the 'next' field of the last node is not NULL,keep traversing the SLL.
            temp=temp->next;
        }
        node *todelete=temp->next; //When 'next' field of last node is 'NULL', we have to delete the last node. We create ptr 'todelete'.
        temp->next=NULL; // Since last node is to be deleted, the 'next' field of the node before it is made 'NULL'.
        cout<<todelete->data<<" is getting deleted."<<endl;
        delete todelete;
    }

    void deleteAt(int pos){
        node *temp=head;
        for (int i = 1; i < pos-1; i++) //Will traverse through SLL until it reaches the position after which the node has to be deleted.
        {
            temp=temp->next; //Pointer 'temp' will store address of next node,this is incrementing 'temp' for SLL traversal.
        }
        node *todelete=temp->next; 
        temp->next=temp->next->next; //The 'next' field of temp will now store address of 'next' field of node at the position to be deleted.
        cout<<"The node at position "<<pos<<" having data "<<todelete->data<<" is getting deleted."<<endl;
        delete todelete;        
    }
    
    bool lsearch(int num){
       if (head==NULL){cout<<"NULL";}
       bool flag=false;
       node *temp=head;
       while (temp->next!=NULL)
       {
        if (temp->data==num)
        {
            flag=true;
            break;
        }
        temp=temp->next;
       }
       return flag;
    }

    void reverse(){
        node *prev,*next1,*curr=head;
        prev=next1=NULL;
        while (curr!=NULL)
        {
            next1=curr->next; //next1 points to next node of curr.
            curr->next=prev; //Rverses curr pointer to point to prev.
            //Move pointers one position ahead.
            prev=curr;
            curr=next1;
        }
        head=prev;
    }

    void display(){
        node *temp=head; // Pointer 'temp' will store address of first node.
        while (temp!=NULL){ //Only when 'temp' is not 'NULL', it will carry out the following.
            cout<<temp->data<<"->";
            temp=temp->next; //Pointer 'temp' will store address of next node,this is incrementing 'temp' for SLL traversal. 
        }
        cout<<"NULL"<<endl; //Will Display 'NULL' after last node implying there is no 'next node' after that.     
    }

};
                                        
int main(){
    SLL single;
    int choice;
    int value;
    bool res=true;

    do
    {   cout<<endl;
        cout<<endl;
        cout<<"----------------SINGLY LINKED LIST (SLL) OPERATION MENU------------------"<<endl;
        cout<<"Press 1 for insertion at beginning of SLL"<<endl;
        cout<<"Press 2 for insertion at end of SLL"<<endl;
        cout<<"Press 3 for insertion at specific position of SLL"<<endl;
        cout<<"Press 4 for deletion at beginning of SLL"<<endl;
        cout<<"Press 5 for deletion at end of SLL"<<endl;
        cout<<"Press 6 for deletion at specific position of SLL"<<endl;
        cout<<"Press 7 for displaying the SLL"<<endl;
        cout<<"Press 8 to search in SLL"<<endl;
        cout<<"Press 9 to reverse the SLL"<<endl;
        cout<<"Press 0 to exit menu"<<endl;
        cout<<"Enter your choice :";cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 0:
            res=false;
            break;
        case 1:
            cout<<"Enter value to be inserted :";cin>>value;
            single.insertAtBegin(value);
            break;
        case 2:
            cout<<"Enter value to be inserted :";cin>>value;
            single.insertAtEnd(value);
            break;
        case 3:
            int pos;
            cout<<"Enter position to be inserted at :";cin>>pos;
            cout<<"Enter value to be inserted :";cin>>value;
            single.insertAt(value,pos);
            break;
        case 4:
            single.deleteAtBegin();
            break;
        case 5:
            single.deleteAtEnd();
            break;
        case 6:
            cout<<"Enter value to be deleted :";cin>>value;
            single.deleteAt(value);
            break;
        case 7:
            single.display();
            break;
        case 8:
            int number;
            cout<<"Enter value to be searched in SLL :";cin>>number;
            single.lsearch(number);
            break;
        case 9:
            single.reverse();
            single.display();
            break;
        }
    } while (res);

    return 0;    
}