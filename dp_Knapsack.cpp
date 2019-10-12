#include <iostream>
#include <algorithm>

using namespace std;

int bestAnswer[101][101];
int item[3][2]={{25,10},{10,9},{10,9}}; 

int main(void){
	int w = 30;
	int length = sizeof(item)/sizeof(item[0]);
	
	for(int i=1; i<=length; i++) {
        for(int j=0; j<w; j++) {
            bestAnswer[i][j] = bestAnswer[i-1][j]; 
            if(j-item[i][0]>=0){
            	bestAnswer[i][j] = max(bestAnswer[i-1][j-item[i][0]]+item[i][1],bestAnswer[i-1][j]);
            }
        }
	}
    cout<<bestAnswer[length][w-1];
}
