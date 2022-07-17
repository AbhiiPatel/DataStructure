#include<stdio.h>

int main(){
	
	int array[100],size,i,j,min,temp;
	
	printf("Enter size of an array:");
	scanf("%d",&size);
	
	
	for(i=0;i<size;i++){
		printf("\nEnter element:");
		scanf("%d",&array[i]);
	}
	
	printf("\nArray before sorted:\n");
	for(i=0;i<size;i++){
		printf(" %d",array[i]);
	}
	
	for(i=0;i<size-1;i++){
		min=i;
		for(j=i+1;j<size;j++){
			if(array[min]>array[j]){
				min=j;
			}
		}
		if(i != min){
			
				temp=array[min];
				array[min]=array[i];
				array[i]=temp;
		}
		
	}
	printf("\nArray after sorted:\n");
	for(i=0;i<size;i++){
		printf(" %d",array[i]);
	}
	return 0;
}
