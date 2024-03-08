#include<iostream>
using namespace std;
#define maxsize 5

class Cqueue{
    int cque[maxsize];
    int front,rear;
    
    public:
    Cqueue(){
        front=-1;
        rear=-1;
        for (int i = 0; i < maxsize; i++)
        {
            cque[i]=0;
        }
    }

    bool isfull();
    bool isempty();
    void enqueue(int);
    int dequeue();
    void display();
};

bool Cqueue ::isfull(){
    if ((rear+1)%maxsize==front){
        return true;
    }
    return false;
}


bool Cqueue ::isempty(){
    if (front==-1 && rear==-1){
        return true;
    }
    return false;
}


void Cqueue ::enqueue(int val){
    if (isfull()){
        cout<<"Circular Queue Overflow..."<<endl;
        return;
    }
    else if (isempty()){
        rear=front=0;
        cque[rear]=val;
    }
    else{
        rear=(rear+1)%maxsize;
        cque[rear]=val;
    }
} 

int Cqueue ::dequeue(){
    int x=0;
    if (isempty()){
        cout<<"Circular Queue Underflow..."<<endl;
        return x;
    }
    else if(front==rear){
        x=cque[rear];
        front=rear=-1;
        return x;
    }
    else{
        x=cque[front];
        cque[front]=0;
        front=(front+1)%maxsize;
        return x;
    }
}

void Cqueue ::display(){
    cout<<"Circular Queue contents :"<<endl;
    for (int i = 0; i < maxsize; i++)
    {
        cout<<cque[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Cqueue q;

    //Enqueueing values and displaying them alongside.
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(6); //Will return Circular Queue overflow.

    //Dequeueing values and displaying them alongside.
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue(); //Will return Circular Queue underflow.
    return 0;
}