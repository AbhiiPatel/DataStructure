#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	struct node *prev;
}*head=NULL;


void insert(int num);
void display();


int main(){
	
	int ch,num;
	while(1){
		printf("\n0-----Exit");
		printf("\n1-----Insert");
		printf("\n2-----Display");
		printf("\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch){
				
			case 0:exit(0);
				
			case 1:printf("\nEnter number:");
					scanf("%d",&num);
					insert(num);
					break;
				
			case 2:display();
					break;
						
						
			default:printf("\nInvalid choice.");
		}//end of switch
	
	}
	return 0;
}

void insert(int num){
	
	struct node *temp,*p;
	
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		head->data=num;
		head->next=NULL;
		head->prev=NULL;
	}else{
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=NULL;
		temp->prev=NULL;
		p=head;
		
		while(p->next != NULL){
			p=p->next;
		}
		
		p->next=temp;
		temp->prev=p;
		temp->next=NULL;
	}
	
}

void display(){
	struct node *p;
	
	if(head==NULL){
		printf("\nNo element");
	}else{
		p=head;
		
		while(p != NULL){
			printf("  %d",p->data);
			p=p->next;
		}
	}
	
}
