#include<iostream>
#include<string>
#include<conio.h>
#include<stack>
using namespace std;
                    
bool isoperand(char ch){
    if (((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))){return true;}
    else{return false;}
}

bool isoperator(char ch){
    if ((ch=='^')||(ch=='*')||(ch=='/')||(ch=='+')||(ch=='-')){return true;}
    else{return false;}
}

int getprec(char alpha){
    if((alpha=='+')||(alpha=='-')){return 1;}
    if((alpha=='*')||(alpha=='/')){return 2;}
    if((alpha=='*')){return 3;}
    return 0;
}

string infixtopostfix(string s){
    stack <char> opstk;
    string result="";
    char symb;
    for (int i=0;i<s.length();i++){
        symb=s[i];
        if(isoperand(symb)){
            result+=symb;
            cout<<result<<endl;
        }
        if(symb=='(' )
        {
            opstk.push(symb);
        }
        if(symb==')'){
            while(opstk.top()!='(')
            {
                result+=opstk.top();
                opstk.pop();
            }
            opstk.pop();
        }
        if(isoperator(symb))
        {
            while(!opstk.empty()&&getprec(symb)<=getprec(opstk.top())){
                result+=opstk.top();
                opstk.pop();
            }
            opstk.push(symb);
            //i++;
            
        }
    }
    while(!opstk.empty())
    {
        result+=opstk.top();
        cout<<result<<endl;
        opstk.pop();
    }
    return result;
}