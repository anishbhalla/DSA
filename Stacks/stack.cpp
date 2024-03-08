#include<iostream>
using namespace std;
#define MAX 10

class stack
{
    int stk[MAX];
    int top;
    public:
    stack(){top=-1;}
    bool isfull()
    {
        if (top==MAX){
            return true;
        }
        else{
            return false;
        }
    }
    bool isempty()
    {
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int num)
    {
        if (isfull()){
            cout<<"Overflow  Error"<<endl;
            return;
        }
        else{
            stk[++top]=num;
        }
    }
    int pop()
    {
        if (isempty()){
            cout<<"Underflow Error"<<endl;
            return -1;
        }
        else{
            return (stk[top--]);
        }
    }
    void peek()
    {
        cout<<"Topmost element is :"<<stk[top]<<endl;
    }
};
                    
int main(){
    stack s;
    s.push(20);
    s.push(30);         
    s.push(40);
    s.peek();
    cout<<"Popped element is "<<s.pop()<<endl;         
    return 0;
}