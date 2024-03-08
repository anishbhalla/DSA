#include<iostream>
using namespace std;
#define n 20
/*
Queue Explaination-
For a queue with size 5

Initially:-
  

   ^        ^      
   |        |
Front=-1  Back=-1

When Queue has elements:- 

  1     2     3     4     5
  ^                       ^ 
  |                       |
Front=0                 Back=4                       
*/

/*Queue Code*/

class Queue{
    int* arr;
    int front;
    int back;

    public:
    Queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }

    bool isfull(){
        if (back==n-1){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        if (isfull()){
            cout<<"Queue overflow..."<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if (front==-1){
            front++;
        }
    }

    bool isempty(){
        if (front==-1 || front>back){
            return true;
        }
        return false;
    }

    void dequeue(){
        if (isempty()){
            cout<<"Queue underflow..."<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if (isempty()){
            cout<<"No elements in Queue"<<endl;
            return -1;
        }
        return arr[front];
    }
};

                    
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<"Peek of queue is :"<<q.peek()<<endl;
    q.dequeue();

    cout<<"Peek of queue is :"<<q.peek()<<endl;
    q.dequeue();
    
    cout<<"Peek of queue is :"<<q.peek()<<endl;
    q.dequeue();
    
    cout<<"Peek of queue is :"<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.peek()<<endl;
    q.dequeue();
    
    return 0;
}