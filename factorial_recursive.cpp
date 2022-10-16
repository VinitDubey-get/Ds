// to find the factorial of a given number using recursion
#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    int prevfact=factorial(n-1);
    return n*prevfact;
}
int main(){
    cout<<"Enter the number to find factorial"<<endl;
    int n;
    cin>>n;
  cout<<"ans is <<endl;
    cout<<factorial(n)<<endl;
    return 0;
}
