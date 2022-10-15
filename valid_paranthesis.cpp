// to check whether a given set of parenthesis is valid or not  
// {[]} is a valid one
#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        if(s.length()==1)
            return false;
        for(int i=0;i<s.size();i++){
            
            char temp=s[i];
            if(temp=='[' || temp=='(' || temp=='{'){
                
                st.push(temp);
                
            }else{
                 if(st.empty())
                     return false;
                char f=st.top();
                st.pop();
                if(temp==')' && f!='(')
                    return false;
            
                else if(temp==']' && f!='[')
                    return false;
                
                
                else if(temp=='}' && f!='{')
                    return false;
            
                
            }
            
            
            
        }
        if(!st.empty())
            return false;
        return true;
}

int main(){
   cout<<"Enter the paranthesis"<<endl;
   string st;
   cin>>st;

   if(isValid(st)){
    cout<<"Paranthesis are Valid"<<endl;
   }
   else{
    cout<<"Not valid"<<endl;
   }
 
}