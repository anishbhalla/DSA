#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; 
};

class Stack
{
public:
    Node *top = NULL; //'Top' will be 'NULL' by default if stack is empty.

    void push(int data) //Pushing data into stack.
    {
        Node *temp = new Node; //Creating new node to push data.
        temp->data = data; //Assigning data to the new node created.
        temp->next = top; //Next node to the new node will  be 'NULL' (i.e value store in 'top'), since there is only one node in stack.
        top = temp; //Now value of top will be changed from 'NULL' to 'temp'.
    }

    void pop()
    {
        if (top == NULL) //If 'top' is 'NULL' that means stack is empty.
        {
            cout << "Stack is empty";
        }
        else //If 'top' is not NULL.
        {
            Node *ptr = top; //We create a node ptr 'ptr' pointing to 'top'.
            top = top->next; //We increment 'top' from last node of stack to the node just next to it.
            delete ptr; //We delete i.e pop the last node of stack.
        }
    }

    void peek()
    {
        cout << top->data;
    }

    bool isEmpty()
    {
        return (top == NULL) ? true : false;
    }

    void Display()
    {
        Node *current = top;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    Stack s;
    int choice, data;

    while (1)
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data to be pushed: ";
            cin >> data;
            s.push(data);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty";
            else
                cout << "Stack is not empty";
            break;

        case 5:
            s.Display();
            break;

        case 6:
            exit(0);

        default:
            cout << "";
        }
    }
    return 0;
}