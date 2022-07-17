#include<stdio.h>
#define SIZE 5

int array[SIZE];

int main(){
	
	int search,min=0,max=SIZE-1,mid,i,flag=0;
	printf("Enter number is ascending order:");
	for(i=0;i<SIZE;i++){
		printf("\nEnter element:");
		scanf("%d",&array[i]);
	}
	
	printf("\nEnter the number for search:");
	scanf("%d",&search);
	
	while(min<=max){
		
		mid=(min+max)/2;
		
		if(array[mid]==search){
			flag=1;
			printf("\n%d number found at %d index",search,mid);
			break;
		}else if(search>array[mid]){
			min=mid+1;
		}else if(search<array[mid]){
			max=mid-1;
		}
		
		
	}
	if(!flag){
		printf("\n%d not found",search);
	}
	
	return 0;
}
