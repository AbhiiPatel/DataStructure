#include<stdio.h>

int fibonacci(int num){
	
	if(num<=2){
		return 1;
	}else{
		return (fibonacci(num-1)+fibonacci(num-2));
	}
}



int main(){
	
	int n,i;
	printf("Enter number till you print fibonacci series:");
	scanf("%d",&n);
	printf("\nFibonacci series:\n");
	for(i=1;i<=n;i++){
		
		printf("%d\t",fibonacci(i));
	}
	
	return 0;
}
