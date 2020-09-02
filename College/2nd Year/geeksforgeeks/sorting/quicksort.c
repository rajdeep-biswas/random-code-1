#include<stdio.h>
#include<stdlib.h>

void quicksort(int number[12],int first,int last) {
	int i, j, pivot, temp,k; 
   	
   	if(first<last){
   		pivot=first;
   		i=first;
   		j=last;
 	
	 	while(i<j){
	        while(number[i]< number[pivot]&&i<last)
	        	i++;
	        while(number[j]>number[pivot])
	           	j--;
	        if(i<j){
	            temp=number[i];
	            number[i]=number[j];
	            number[j]=temp;
	        }
	    }
	    temp=number[pivot];
	    number[pivot]=number[j];
	    number[j]=temp;    
	    quicksort(number,first,j-1);
	    quicksort(number,j+1,last);
   	}
}

int main(){
   int i, count=12, number[12]={44,33,11,55,77,90,40,60,99,22,88,66};

	printf("\n Unsorted list is as follows \n");

	for (i = 0; i < 12; i++) {
		printf(" %d, ", number[i]);
	}

   quicksort(number,0,11);

   printf("\n Order of Sorted elements: \n");
   for(i=0;i<count;i++)
      printf(" %d, ",number[i]);
}
