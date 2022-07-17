#include<stdio.h>

int main(){
	
	int array[100],size,i,search,flag=0;
	
	printf("Enter size of array:");
	scanf("%d",&size);
	
	for(i=0;i<size;i++){
		printf("\nEnter element:");
		scanf("%d",&array[i]);
	}
	
	printf("\nEnter element which you find in array:");
	scanf("%d",&search);
	
	for(i=0;i<size;i++){
		
		if(array[i]==search){
			flag=1;
			printf("\n%d present at %d index",search,i);
		}
	}
	if(!flag){
		printf("\n%d not present in array",search);
	}
	return 0;
}
