#include<stdio.h>
#define SIZE 5

int a[]={1,2,3,4,5};

void rightshift(int num){
	int i;
	int temp=a[SIZE-1];
	for(i=SIZE-1;i>=0;i--){
		a[i]=a[i-1];
	}
	a[0]=temp;
	num--;
	if(num!=0){
	
		rightshift(num);
	}

}
void print(){
	int i;
	printf("\nArray:\n");
	for(i=0;i<SIZE;i++){
		printf("  %d",a[i]);
	}
}

int main(){
	print();
	
	rightshift(4);
	print();
	
	return 0;
}
