#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int f=-1,r=-1,flag=0;
int q=0;

void insert(){
	  int num;
	  if(r==SIZE-1){
	  	 printf("Queue Full");
	  }else{
	  	
	  	printf("Enter the  number:");
	  	scanf("%d",&num);
	  	r++;
	  	queue[r]=num;
	  	if(f==-1){
	  		f++;
		}
	  	
	  }
	
}

void deleteQ(){
	
	int num;
	if(f==-1){
		printf("Queue is empty");
		
	}else{
		
		num=queue[f];
		printf("\n%d deleted",num);
		q++;             //q for search function
		if(f==r){
			f=-1;
			r=-1;
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
	
		for(i=f;i<=r;i++){
			printf(" %d",queue[i]);
		
		}
    }
}

void search(){                      //Linear Search
	
	int num,i;
	printf("\nEnter the number for searching:");
	scanf("%d",&num);
	for(i=f;i<=r;i++){
		
		
		if(num==queue[i]){
			printf("\n%d found at %d location",num,(i+1)-q);
			flag=1;
		}
		
	}
	
	if(flag==0){
		printf("\n%d not found",num);
	}
	
}

int main(){
	int choice;
	while(1){
	
		printf("\n1---Insert");
		printf("\n2---Delete");
		printf("\n3---Display");
		printf("\n4---Exit");
		printf("\n5---Search");
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
			
			case 5:search();
			       break;
			
			default:printf("Invalid choice");	    
		}
	
    }
	
	return 0;
}
