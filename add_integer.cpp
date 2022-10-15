// to add two integers using stacks 
#include<iostream>
#include<stack>
using namespace std;
int main(){
    cout<<"Enter the first number "<<endl;
    int n;
    cin>>n;
    int temp=n;
    stack<int>n1;
    stack<int>n2;
    while(temp>0){
        int last=temp%10;
        n1.push(last);
        temp=temp/10;

    }
    while(!n1.empty()){
        int last=n1.top();
        n1.pop();
        n2.push(last);
       
    }


     cout<<"Enter the second number "<<endl;
    int m;
    cin>>m;
    temp=m;
    stack<int>m1;
    stack<int>m2;
    while(temp>0){
        int last=temp%10;
        m1.push(last);
        temp=temp/10;

    }
    while(!m1.empty()){
        int last=m1.top();
        m1.pop();
        m2.push(last);
       
    }


   

    // adding the numbers and saving them
    int carry=0;
    stack<int>ans;
    while((!n2.empty()) && (!m2.empty()) ){
        int s1=n2.top();
        int s2=m2.top();
        n2.pop();
        m2.pop();
        int sum=s1+s2+carry;
        int put=sum%10;
        carry=sum/10;
         ans.push(put);

    }
    if(n2.empty()){
        while(!m2.empty()){
           int s1=m2.top();
           m2.pop();
           int sum=s1+carry;
           int put=sum%10;
           carry=sum/10;
           ans.push(put);
        }
    }
    if(m2.empty()){
        while(!n2.empty()){
                int s1=n2.top();
           n2.pop();
           int sum=s1+carry;
           int put=sum%10;
           carry=sum/10;
           ans.push(put);
        }
    }
   
    if(carry!=0){
        ans.push(carry);
    }

    int sum=0;

    while(!ans.empty()){
        int n=ans.top();
        ans.pop();
        sum=sum*10+n;
    }
    cout<<"The sum is "<<sum<<endl;
    
}