#include<iostream>

using namespace std;

int insertion(int array[], int length){
	int temp;
	
	for(int i=1; i<length; i++){
		for(int j=i; j>=1; j--){
			if(array[j-1]>array[j]){
				temp=array[j];
				array[j]=array[j-1];
				array[j-1]=temp;
			}
		}

	}
}

int main(void){
	int n;
	int array[10];
	
	for(int i=0; i<10; i++){
		cin>>n;
		array[i]=n;
	}
	
	int length = sizeof(array)/sizeof(array[0]);
	insertion(array,length);
	
	for(int i=0; i<10; i++){
		cout<<array[i]<<" ";
	}	
}

