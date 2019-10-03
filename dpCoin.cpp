#include <iostream>
#include <algorithm>

using namespace std;

int bestCoin[101];
int coin[4]={1,4,5,6};

int main(void){

	int have=23;
	int length = sizeof(coin)/sizeof(coin[0]);
	
	for(int i=1;i<=have; i++){
		bestCoin[i]=i;
	}
	
	for(int i=0; i<length; i++){
		for(int j=coin[i]; j<=have; j++){
			bestCoin[j]=min(bestCoin[j],bestCoin[j-coin[i]]+1);
		}
	}
	cout<<bestCoin[have];	
}
