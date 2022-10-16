// to convert from infix to postfix expressions
#include<iostream>
#include<stack>
using namespace std;


string ans="";

void check(char ch,stack<char>&st){
    if(ch=='(' || ch=='['){
        st.push(ch);
    }
    else if(ch=='^'){
        string buffer="";
        while((!st.empty() && st.top()!='(' && st.top()!='[') && (st.top()=='^')){
            buffer+=st.top();
            st.pop();
        }
        st.push(ch);
        if(buffer.size()!=0){
            ans+=buffer;
        }
    }
    else if(ch=='/' ||ch=='*' || ch=='%'){
        string buffer="";
        while((!st.empty() && st.top()!='(' && st.top()!='[') && (st.top()=='/' || st.top()=='^' || st.top()=='*' || st.top()=='%')){
            buffer+=st.top();
            st.pop();
        }
        st.push(ch);
        if(buffer.size()!=0){
            ans+=buffer;
        }
    }
    else if(ch=='+' ||ch=='-'){
        string buffer="";
        while((!st.empty() && st.top()!='(' && st.top()!='[') && (st.top()=='^' || st.top()=='/' || st.top()=='*' || st.top()=='%' || st.top()=='+' || st.top()=='-')){
              buffer+=st.top();
              st.pop();

        }
        st.push(ch);
        if(buffer.size()!=0){
            ans+=buffer;
        }

    }
    else if(ch==')' || ch==']'){
        while(!st.empty() && st.top()!='(' && st.top()!='['){
            ans+=st.top();
            st.pop();
        }
        st.pop();
    }
   
}


int main(){
    cout<<"Enter the  infix expression"<<endl;
    string infix;
    cin>>infix;

    stack<char>st;
    for(int i=0;i<infix.size();i++){
        char ch=infix[i];
        if(!(ch>='a' && ch<='z')){
            check(ch,st);
        }
        else if(ch>='a' && ch<='z'){
            ans+=ch;
        }


    }
    while(!st.empty()){
       if(st.top()=='(' || st.top()=='['){
            // ans+=st.top();
            // st.pop();
            st.pop();
        }
        else{
            ans+=st.top();
            st.pop();
        }
    }
    cout<<"Postfix Expression is "<<endl;
    cout<<ans<<endl;
}