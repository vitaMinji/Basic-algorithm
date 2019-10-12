#include <iostream>
#include <algorithm>
//0-1 Knapsack Problem (배낭문제)

using namespace std;

int item[3][2]={{25,10},{10,9},{10,9}}; //(무게, 가격)  

int profit(int w){//가격 높은것부터 
	int length = sizeof(item)/sizeof(item[0]);
	int temp[length];

	for(int i=0; i<length; i++){
		temp[i]=item[i][1];
	}
	sort(temp,temp+length); 

	int te = 0;
	int result = 0;
	for(int i=length-1; i>=0; i--){
		for(int j=0; j<length; j++){
			if(item[j][1]==temp[i]&&(te+item[j][0])<=w){
				te=te+item[j][0];
				result = result+item[j][1];
			}	
		}
	}
	return result;
}

int weight(int w){
	int length = sizeof(item)/sizeof(item[0]);
	int temp[length];
	for(int i=0; i<length; i++){
		temp[i]=item[i][0];
	}
	sort(temp,temp+length);
	int te = 0;
	int result = 0;
	
	for(int i=0; i<length; i++){
		for(int j=0; j<length; j++){
			if(item[j][0]==temp[i]&&(te+item[j][0])<=w){
				te=te+item[j][0];
				result = result+item[j][1];
				break;
			}	
		}
	}
	return result;
}

int density(int w){
	int length = sizeof(item)/sizeof(item[0]);
	float temp[length];
	
	for(int i =0; i<length; i++){
		temp[i]=item[i][0]/item[i][1]+item[i][0]%item[i][1];
	}
	
	sort(temp,temp+length); 

	int te = 0;
	int result = 0;
	for(int i=length-1; i>=0; i--){
		for(int j=0; j<length; j++){
			if((item[j][0]/item[j][1]+item[j][0]%item[j][1])==temp[i]&&(te+item[j][0])<=w){
				te=te+item[j][0];
				result = result+item[j][1];
			}	
		}
	}
	return result;
	
	
}

//현재 무게로 출력하고있음, 가격으로 바꾸기 
int main(void){
 	int w = 30;
 	cout<<"답은 각자의 경우에 채우는 profit으로 출력합니다."<<"\n";
 	cout<<"Profit : "<<profit(w)<<"\n";
 	cout<<"Weight : "<<weight(w)<<"\n";
 	cout<<"Density : "<<density(w)<<"\n";
 }
