// tower of hanoi recursion
#include<iostream>
using namespace std;

void move(int n,char src , char helper , char dest){
    if(n==0){
        return;
    }
    move(n-1,src,dest,helper);
    cout<<"Shift "<<n<<" from "<<src<<" to "<<dest<<endl;
    move(n-1,helper,src,dest);
}
int main(){
  cout<<"Enter the number of rings to place"<<endl;
    int n;
    cin>>n;
  cout<<"Source is A"<<endl;
  cout<<"Helper is B"<<endl;
  cout<<"Destination is C"<<endl;
    move(n,'A','B','C');
    return 0;
}
