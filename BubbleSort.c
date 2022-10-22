#include<stdio.h>

int n=7;

int main(){
	int a[]	={11,2,33,4,5,17,9};         //11,2,33,4,5,17,9   //-1,-2,-3,-4,-5,6,7,
	int i,j,temp,flag=0;
	
	printf("Array Before sorted...\n");
	for(i=0;i<n;i++){
		printf("  %d",a[i]);
	}
	
	for(i=0;i<n-1 && flag==0;i++){               //no of passes
		flag=1;
		printf("\n Pass :%d\n",i+1);	
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=0;
			}
				
		}
		for(j=0;j<n;j++){
			printf("  %d",a[j]);
		}
			
		
	}
	
	
	printf("\nArray After sorted...\n");
	for(i=0;i<n;i++){
		printf("  %d",a[i]);
	}
	return 0;
}
