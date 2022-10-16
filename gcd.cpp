 find GCD of two numbers
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	
	if (a == 0)
	return b;
	if (b == 0)
	return a;
	// base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a-b, b);
  else
	return gcd(a, b-a);
}


int main()
{
	int a,b;
  cout<<"Enter the two numbers :"<<endl;
  cin>>a>>b;
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
	return 0;
}
