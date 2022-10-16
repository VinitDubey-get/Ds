// to evaluate a postfix expressions and convert it into infix 
#include<iostream>
#include<stack>
using namespace std;
int main(){
    bool valid=true;
    string post;
    cout<<"Enter the Postfix expression"<<endl;
    cin>>post;

    stack<string>st;

    for(int i=0;i<post.size();i++){
        char ch=post[i];
        if(ch>='a' && ch<='z'){
            string s="";
            s+=ch;
            st.push(s);
        }
        else{
            if(st.size()<2){
                cout<<"Invalid postfix expression "<<endl;
                valid=false;
                break;
            }
            string c1=st.top();
            st.pop();
            string c2=st.top();
            st.pop();
            string ans="";
            ans+='(';
            ans=ans+c2+ch+c1;
            ans+=')';
            st.push(ans);


        }
    }
    string s=st.top();
    if(valid)
    cout<<"Infix expression is "<<s<<endl;
}