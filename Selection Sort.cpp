#include <stdio.h>

int main (void){
	int min, temp, index;
	
	
	int array [10] = {2,5,7,8,9,4,6,3,10,1};
	for(int i =0 ; i <10; i++){
		
		min =999;
		for(int j= i; j<10; j++){
			if(min>array[j]){
				
				min=array[j];
				index = j;
			}
				
		}
	
	temp=array[index];
	array[index]=array[i];
	array[i]=temp;	
		
	}
	
	
	
	for(int i =0; i<10; i++){
		printf("%d ",array[i]);
	}
}

//시간복잡도 엔제곱 ㅇㅅㅇ
 
