#include<iostream>
#include<cstring>
#include"infix_header.h"
using namespace std;
                                       
int main(){
    string instr, rev = "", prstr;
    cout<<"Enter the infix expression\n";
    cin>>instr;
    for (int i = instr.length()-1; i>=0; i--)
    {
        if (instr[i]=='(')
        {
            instr[i]=')';
        }
        else if (instr[i]==')')
        {
            instr[i]='(';
        }
        rev+=instr[i];
        
    }
    prstr=infixtopostfix(rev);
    rev="";
    rev=prstr;
    prstr="";
    for (int i=rev.length()-1;i>=0;i--){
        prstr+=rev[i];
    }
    cout<<prstr;
    return 0;
}