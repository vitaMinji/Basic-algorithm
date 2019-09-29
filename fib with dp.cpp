#include <iostream>

using namespace std;
int array[101];

int fib(int n){
	if(array[n]!=0) return array[n];
	else if(n==1) return 1;
	else if(n==0) return 0;
	else return array[n]=fib(n-1)+fib(n-2);
}



int main(void){
	int n;
	cin>>n;
	cout<<fib(n);
}
