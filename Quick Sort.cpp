#include<stdio.h>

int data[10]={2,5,7,8,9,4,6,3,10,1};

void quickSort(int *data, int start, int end){
	int pivot = start ; //피벗값 지정. 
	int i=start+1;
	int j=end;
	int temp;
	
	if(start>=end) return;
	
	while(j>=i){
		while(data[pivot]>=data[i]&&i<=end){
			i++;
		}
		while(data[pivot]<=data[j]&&j>start){
			j--;
		}
		
		if(i>j){
			temp=data[j];
			data[j]=data[pivot];
			data[pivot]=temp;
			
		}
		else{
			
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
	}
	//이 while을 통과했다는건 pivot 바뀌었다는 것을 의미. 
	quickSort(data,start,j-1);
	quickSort(data,j+1,end);

}

int main (void){
	
	quickSort(data,0,9);
	
	for(int i=0; i<10; i++){
		printf("%d ", data[i]);
	}
	
	return 0;
}
