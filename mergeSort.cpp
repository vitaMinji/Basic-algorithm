#include <stdio.h>
int array[10]= {1,10,8,7,4,9,6,5,3,2};
int size = 10;

void mergeSort(int start, int end){
	int middle=size/2;
	if(middle>=1){
		mergeSort(start,middle);
		mergeSort(middle,end);
		
		 
	}
	
}
int main(void){
	//mergeSort
	//다 가닥가닥 쪼개버려서,,, 정렬하면서 합치기 

}
