// to print the nth fibonnaci number recursively -- 0 1 1 2 3 5 8 13   in this 5th fibonacci number is 3 and 6th is 5
#include<iostream>
using namespace std;
int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}
int main(){
    cout<<"Enter the Number to find nth fibo number"<<endl;
    int n;
    cin>>n;
    cout<<"The number is "<<endl;
    cout<<fib(n-1)<<endl;
    return 0;
}
