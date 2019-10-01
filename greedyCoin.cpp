#include <iostream>

using namespace std;

int result[4];

int main(void){
	int have = 23;
	
	int coin[4]={6,5,4,1};
	
	for(int i=0; i<4; i++){
		result[i] = have/coin[i];
		have = have % coin[i];
		cout<<result[i]<<" ";
	}
	
}
