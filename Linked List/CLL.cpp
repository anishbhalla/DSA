#include<iostream>
using namespace std;
/*Circular Linked List Code*/
                    
class cnode{
    private:
    int data;
    cnode* next;

    friend class CLL;
};

class CLL{
    public:
    /*Declaring Constructor and Destructor*/
    CLL(); //Constructor
    ~CLL(); //Destructor

    /*Declaring Basic Functions*/
    bool empty() const; //It checks weather list is empty or not.
    const int front() const; //Returns the node after the cursor.
    const int back() const; //Returns element referenced by the cursor.
    void advance(); //It advances the cursor to the next node.
    void add(const int); //Inserts a new node with element 'e' immidiately after the cursor.
    void remove(); //Removes the node immidiately after the cursor.
    void display(); //To display the contents of the CLL.
    private:
    cnode* cursor;        
};

CLL ::CLL(){
    cursor=NULL;
}

CLL ::~CLL(){
    while(!empty()){
        remove();
    }
}

bool CLL ::empty() const{
    return(cursor==NULL); //Will return either True or False for the expresion.
}

const int CLL ::front() const{
    cout<<cursor->next->data<<endl;
}

const int CLL ::back() const{
    cout<<cursor->data<<endl;
}

void CLL ::advance(){
    cursor=cursor->next;
}

void CLL ::add(const int num){
    cnode* newnode=new cnode();
    newnode->data=num;
    cnode* temp=cursor;
    if (empty()){
        newnode->next=newnode; 
        cursor=newnode;
    }
    else{
        while (temp->next!=cursor) //Whenever next field of 'temp' ptr is not pointing to cursor.
        {
            temp=temp->next; //traverse the CLL.
        }// When next field of 'temp' ptr is pointing to cursor.
        temp->next=newnode; //We insert newnode in the next field of 'temp' ptr.
        newnode->next=cursor; //We redirect the next field of 'newnode' to the cursor, successfully inserting a new node.
    }
}

void CLL ::remove(){
    cnode* prev=cursor->next; //Creating 'prev' ptr that stores 'next field' of cursor.
    if (cursor==nullptr)
    {
        cout<<"The Circular Linked List is Empty"<<endl;
    }
    else
    {
        if (prev==cursor){
            cursor=NULL;
        }
        else
        {
            cursor->next=prev->next;
            delete prev;
        }
    }
}

void CLL ::display(){
    if (cursor==nullptr){
        cout<<"The Circular Linked List is empty"<<endl;
        return;
    }
    cnode *temp=cursor;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=cursor);
}


int main(){
    CLL c;
    c.add(12);
    c.add(13);
    c.add(14);
    c.add(16);
    c.add(18);
    c.back();

    return 0;
}