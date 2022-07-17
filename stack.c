#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE];
int top=-1;

void push(){
	   int num;
	   if(top== SIZE-1) {
	   	
	   	   printf("Stack Overflow");
	   }else{
	   	
	   	  printf("Enter number:");
	   	  scanf("%d",&num);
	   	  top++;
	   	  stack[top]=num;
	   	
	   }
}

void pop(){
	
	  int num;
	  if(top==-1){
	  	 printf("Stack Underflow");
	  }else{
	  	 num=stack[top];
	  	 top--;
	  	 printf("\n%d POP",num);
	  	 
	  }
	
}

void display(){
	  int i;
	  if(top==-1) {
	  	 printf("Stack  Underflow"); 
	  }else{
	  	 for(i=top;i>=0;i--){
	  	 	
              printf("\n%d",stack[i]);
		   }
	  	
	  }
}

void peep(){
	
	int p,i;
	printf("\nEnter the position to find which number is present at this position:");
	scanf("%d",&p);
	i=top-p+1;
	printf("Element at %dth position=%d",p,stack[i]);
	
}

int main(){
	
	int choice;
	while(7576){
	
        printf("\n1----Push");
	    printf("\n2---Pop");
	    printf("\n3---Display");
	    printf("\n4---Exit");
	    printf("\n5---Peep");
	    printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			
			 case 1:push();
			        break;
			 
			 case 2:pop();
			        break;
			        
			 case 3:display();
			        break;
			        
			 case 4:exit(0);
			 
			 case 5:peep();
			        break;
			 default:printf("Invalid choice");
		}
	
   }
	return 0;
}
