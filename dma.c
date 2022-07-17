#include<stdio.h>

int main(){
	
	int *a,i;
	a=(int*)malloc(5*sizeof(int));
	
	for(i=0;i<5;i++){
		
		printf("Enter number:");
		//scanf("%d",&a[i]);
		scanf("%d",a+i);
		
	}
	
	for(i=0;i<5;i++){
		//printf("%d\n",a[i]);
		printf("%d\n",*(a+i));
	}
	
	
	return 0;
}
