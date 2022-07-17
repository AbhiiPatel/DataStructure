#include<stdio.h>

int main(){
	
	int *a,n;
	int x,i,j,sort;
	printf("Enter array size:");
	scanf("%d",&n);
	
	a=(int*)malloc(n*sizeof(int));
	
	
	for(x=0;x<n;x++){
		printf("\nEnter element a[%d]:",x);
		scanf("%d",a+x);
	}
	
	printf("\nArray before sorted:\n");
	for(x=0;x<n;x++){
		printf("  %d",*(a+x));
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
		printf("  %d",*(a+x));
	}
	return 0;
}
