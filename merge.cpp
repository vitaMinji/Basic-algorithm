#include <iostream>

using namespace std;

int sorted[100001];

void merge(int array[], int left, int mid, int right){
  
   int i=left;
   int j = mid +1;
   int k = left;
   
   while(i<=mid && j<=right){
      if(array[i]<=array[j]){
         sorted[k] = array[i];
         i++;
      }else{
         sorted[k] = array[j];
         j++;
      }
      k++;
   }
   if(i>mid){
      for(int l=j; l<=right; l++){
         sorted[k]=array[l];
         k++;
      }
   }
   else{
      for(int l=i; l<=right; l++){
         sorted[k]=array[l];
         k++;
      }
   }
   
   for(int l=left; l<=right; l++){
      array[l]=sorted[l];
   }
}

int mergeSort(int array[], int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		mergeSort(array, left, mid);
		mergeSort(array, mid+1, right);
		merge(array, left, mid, right);
	}
}

int main(void){
	int array[10] ={1,3,5,7,8,9,4,2,6,10};
	int length = sizeof(array)/sizeof(array[0]);
	mergeSort(array,0,length-1);
	
	for(int i=0; i<length; i++){
		printf("%d ", sorted[i]);
	}
}

