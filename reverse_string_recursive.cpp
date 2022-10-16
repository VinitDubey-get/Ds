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
