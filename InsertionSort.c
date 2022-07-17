#include<stdio.h>

int n=5;
int main(){
	int a[]={7,12,3,4,1};               
	int i,j,x,sort;
	printf("Array before sorted:\n");
	for(x=0;x<n;x++){
		printf("  %d",a[x]);
	}
	
	
	for(i=1;i<n;i++){
		sort=a[i];
		printf("\nPass:%d\n",i);
		for(j=i-1;j>=0;j--){
			if(a[j]>sort){
				
				a[j+1]=a[j];
			}else{
				break;
			}	
		}
		a[j+1]=sort;
		for(j=0;j<n;j++){
			printf("  %d",a[j]);
		}
	}
	
	printf("\nArray after sorted:\n");
	for(x=0;x<n;x++){
		printf("  %d",a[x]);
	}
	
	return 0;
}
