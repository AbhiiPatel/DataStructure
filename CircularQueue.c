#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int f=-1,r=-1;


void insert(){
	  int num;
	  if(r==SIZE-1  && f==0 ){
	  	 printf("\nQueue Full");
	  }else if(r==f-1){
	  	printf("\nQueue full");
      }else{
	  	
		  	printf("Enter the  number:");
		  	scanf("%d",&num);
		  	
		  	
		  	if(r==SIZE-1){
		  	   r=0;	
			}else{
				r++;
			}
			
			if(f==-1){
		  		f++;
			}
	      queue[r]=num;  	
	  }
	
}

void deleteQ(){
	
	int num;
	if(f==-1){
		printf("Queue is empty");
		
	}else{
		
		num=queue[f];
		printf("\n%d deleted",num);
		
		if(f==r){
			f=-1;
			r=-1;
		}else if(f==SIZE-1){
			f=0;
		}else{
			f++;
		}
	}
	
}

void display(){
	int i;
	if(f==-1){
		printf("Queue is empty");
	}else{
	
		  if(r>=f){
		  	  for(i=f;i<=r;i++){
		  	  	
		  	     printf(" %d",queue[i]);	
			  }
		  }
		  
		  else if(r<f){
		  	
		  	  for(i=f;i<SIZE;i++){
		  	     printf(" %d",queue[i]);	
			  }
		  	
		  	 for(i=0;i<=r;i++){
		  	    printf(" %d",queue[i]);
			 }
		  	
		  }
    }
}


int main(){
	int choice;
	while(1){
	
		printf("\n1---Insert");
		printf("\n2---Delete");
		printf("\n3---Display");
		printf("\n4---Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			
			case 1:insert();
			       break; 
			
			case 2:deleteQ();
			       break; 
			
			case 3:display();
			       break;
				   
			case 4:exit(0);
			
			
			default:printf("Invalid choice");	    
		}
	
    }
	
	return 0;
}
