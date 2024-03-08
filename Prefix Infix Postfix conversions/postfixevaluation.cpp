#include<iostream>
#include<stack>
using namespace std;

stack<int> st;
void eval(string s)
{
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];

        if(ch>='0'&&ch<='9')
        {
            st.push(ch - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            if (ch=='+'){
                st.push(op1 + op2);
            }
            else if (ch=='-'){
                st.push(op1 - op2);
            }
            else if (ch=='/'){
                st.push(op1 / op2);
            }
            else if (ch=='*'){
                st.push(op1 * op2);
            }
            else if (ch=='$'){
                st.push(op1 ^ op2);
            }                             
        }
    }
    cout<<st.top()<<endl;
}
                                        
int main(){
    eval("231*+9-");         
    return 0;
}
