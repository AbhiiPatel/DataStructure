#include<stdio.h>

int main(){
	
	int arr[]={1,2,3,4,5};
	int l=sizeof(arr)/sizeof(arr[0]);
	int n;
	int i,j,last;
	
	printf("\nEnter no of time which you want to shift:\n");
	scanf("%d",&n);
	
	printf("Before shifting the array:\n");
	for(i=0;i<l;i++){
		
		printf("  %d",arr[i]);
	}
	
	for(i=0;i<n;i++){
		last=arr[l-1];
		for(j=l-1;j>0;j--){
			arr[j]=arr[j-1];
			
		}
		arr[0]=last;
	}
	
	printf("\nAfter shifting the array:\n");
	for(i=0;i<l;i++){
		
		printf("  %d",arr[i]);
	}
	return 0;
}
