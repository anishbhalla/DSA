#include<iostream>
using namespace std;
                    
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    node* front;
    node*  back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    bool isempty(){
        if (front==NULL){
            return true;
        }
        return false;
    }

    void enqueue(int val){

        node* n=new node(val);

        if (isempty()){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }

    void dequeue(){

        if (isempty()){
            cout<<"Queue underflow..."<<endl;
            return;
        }
        
        node*todelete=front;
        front=front->next;
        delete todelete;
    }

    int peek(){

        if (isempty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }
        return front->data;
    }    
};
                    
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<"Peek is :"<<q.peek()<<endl;
    q.dequeue();

    cout<<"Peek is :"<<q.peek()<<endl;
    q.dequeue();

    cout<<"Peek is :"<<q.peek()<<endl;
    q.dequeue();

    cout<<"Peek is :"<<q.peek()<<endl;
    q.dequeue();

    cout<<q.peek()<<endl;
    q.dequeue();

    return 0;
}