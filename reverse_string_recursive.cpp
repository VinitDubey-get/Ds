//  to reverse a string recursively
#include<iostream>
using namespace std;

void reverse(string s){
    if(s.size()==0){
        return ;
    }
    string rest=s.substr(1);
    reverse(rest);
    cout<<s[0];
}
int main(){
  cout<<"Enter the string"<<endl;
    string s;
    cin>>s;
    reverse(s);
    return 0;
}

// easy and more accurate recursive method
#include<iostream>
using namespace std;

void solve(int i,string&s){
    if(i==s.size()/2){
        return;
    }
   swap(s[i],s[s.size()-i-1]);
   solve(i+1,s);
    
}

void rev(string &s){
    solve(0,s);
}
int main(){
    cout<<"Enter any string"<<endl;
    string s;
    cin>>s;
    rev(s);
    cout<<s<<endl;
}
