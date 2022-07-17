#include<stdio.h>


int arr[]={1,2,3,4};

//create using recursion
int sum(int len){
	
	if(len<=0){
		return 0;
	}else{
		return arr[len-1]+sum(len-1);
	}
}



int main(){
	int l=sizeof(arr)/sizeof(arr[0]);
	
	printf("Answer=%d",sum(l));
	
	return 0;
}
