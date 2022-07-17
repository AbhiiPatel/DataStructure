#include<stdio.h>

int n=7;

int main(){
	int a[]={1,2,33,14,15,16,9};                      
	int i,j,temp,min;
	
	printf("Array before sorted:\n");
	for(i=0;i<n;i++){
		printf("  %d",a[i]);
	}
	
	for(i=0;i<n-1;i++){              //no of passes
		min=i;
		printf("\nPass:%d\n",i+1);
		for(j=i+1;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		if(i != min){
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
		for(j=0;j<n;j++){
			printf("  %d",a[j]);
		}	
		
	}
	
	printf("\nArray after sorted:\n");
	for(i=0;i<n;i++){
		printf("  %d",a[i]);
	}
	
	return 0;
}
