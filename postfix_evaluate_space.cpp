// to evaluate a postfix expression
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
int main(){
    bool valid=true;
    string post;
    cout<<"Enter the Postfix expression"<<endl;
    getline(cin,post);

    string buffer="";
    double ans=0;
    stack<double>st;

    for(int i=0;i<post.size();i++){
        char ch=post[i];
        if(ch>='0' && ch<='9'){
            // string s="";
            // s+=ch;
            // cout<<"Enter the value of "<<ch<<endl;
            // double i;
            // cin>>i;
            // st.push(i);
            buffer+=ch;
          //  cout<<ch<<endl;
            
        }
        else if(ch==' '){
           // cout<<buffer<<" ";
            if(buffer.size()!=0){
             double num=stoi(buffer);
           //  cout<<num<<endl;
             st.push(num);
            }
          //  cout<<num<<endl;
            buffer="";
        }
        else{
            if(st.size()<2){
                cout<<"Invalid postfix expression "<<endl;
                valid=false;
                break;
            }
            double c1=st.top();
            st.pop();
            double c2=st.top();
            st.pop();
            //string ans="";
           // ans+='(';
            double temp=0;
            if(ch=='/'){
                temp+=c2/c1;
            }
            else if(ch=='*'){
                temp+=c2*c1;
            }
            else if(ch=='^'){
                temp+=pow(c2,c1);
            }
            else if(ch=='-'){
                temp+=c2-c1;
                
            }
            else if(ch=='+'){
                temp+=c2+c1;
            }
          
            st.push(temp);


        }
    }
    double s=st.top();
    if(valid)
    cout<<"Evaluated expression is "<<s<<endl;
}
