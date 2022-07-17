#include<stdio.h>

int main()
{
	int arr[5]={-90,8,-90,-5,65},p[5]={},n[5]={};
	int i,j,l1=0,l2=0,l3=0;
	
	for(i=0;i<5;i++){
		
		printf("  %d",arr[i]);
	}
	printf("\n");
	for(i=0;i<5;i++){
		if(arr[i]>0){
			p[l1]=arr[i];
			l1++;
		}else{
			n[l2]=arr[i];
			l2++;
		}
		
	}
	
	for(i=0;i<l1;i++){
		arr[l3]=p[i];
		l3++;
		
	}
	
	for(i=0;i<l2;i++){
		arr[l3]=n[i];
		l3++;
    }
	for(i=0;i<l3;i++){
		
		printf("  %d",arr[i]);
	}
	
	return 0;
}
