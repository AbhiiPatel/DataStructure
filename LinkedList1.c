#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	
}*head=NULL;

void insert(int num);
void display();
void deleteNode();           //Last node
void insertAtBegin();
void insertAtAnyAfter();
void insertAtAnyBefore();
void deleteBeg();
void deleteAny(int num);

int main(){
	
	int ch,num;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	while(1){
		printf("\n1----Insert");
		printf("\n2----Display");
		printf("\n3----Delete");
		printf("\n4----InsertAtBegin");
		printf("\n5----InsertAtAnyAfter");
		printf("\n6----InsertAtAnyBefore");
		printf("\n7----DeleteBeginning");
		printf("\n8----DeleteAny");
		printf("\n0----Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch){
			
			case 1:printf("\nEnter number:");
				   scanf("%d",&num);
				   insert(num);
				   break;
					
			case 2:display();
				   break;
				
			case 3:deleteNode();
				   break;
				  
			case 4:insertAtBegin();
				   break;			
			case 5:insertAtAnyAfter();
					break;
					
			case 6:insertAtAnyBefore();
					break;
					
			case 7:deleteBeg();
					break;
					
			case 8:printf("\nEnter number:");
				   scanf("%d",&num);
				   deleteAny(num);
				   break;
							
			case 0:exit(0);
			
			default:printf("Invalid choice");
		}
	
	}
	return 0;
}


void insert(int num){

	struct node *temp,*p;
	
	
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		head->data=num;
		head->next=NULL;
		
	}else{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=NULL;
		
		p=head;
		
		while(p->next != NULL){
			
			p=p->next;
		}
		
		p->next=temp;
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

void deleteNode(){
	
	struct node *p,*q;
	if(head==NULL){
		printf("\nList is empty");
	}else{
		
		p=head;
		q=head;
		while(p->next != NULL){
			q=p;
			p=p->next;
		}
		
		printf("\n%d Deleted",p->data);
		free(p);
		q->next=NULL;
		
	}
}

void insertAtBegin(){
	
	int num;
	struct node *temp;
	
	if(head==NULL){
		printf("\nPlease add Node.");
	}else{
		printf("\nEnter number:");
		scanf("%d",&num);
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=head;
		
		head=temp;
	}
	
}


void insertAtAnyAfter(){
	
	int search,num,flag=0;
	struct node *p,*q,*temp;
	
	if(head==NULL){
		printf("\nPlease add node.");
	}else{
		printf("\nEnter number after you want to add data:");
		scanf("%d",&search);
		
		p=head;
		while(p != NULL){
			if(p->data == search){
				flag=1;
				break;
			}
			p=p->next;
		}
		
		if(flag==1){
			printf("\nEnter number which you want to add:");
			scanf("%d",&num);
			
			q=p->next;
			
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=num;
			temp->next=q;
			p->next=temp;
		}else{
			printf("\nNumber not found in List Please try again");
		}
	}
	
	
}

void insertAtAnyBefore(){
	
	struct node *temp,*p,*q;
	int num,search,flag=0;
	
	if(head==NULL){
		printf("\nPlease add a node.");
	}else{
		printf("\nEnter number before you want to add data:");
		scanf("%d",&search);
		
		p=head;
		q=head;
		while(p!= NULL){
			if(p->data == search){
				flag=1;
				break;
				
			}
			q=p;
			p=p->next;
		}
		
		if(flag==1){
			
			printf("\nEnter number which you want to add:");
			scanf("%d",&num);
			
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=num;
			temp->next=p;
			
			q->next=temp;
			
		}else{
			printf("\nNumber not found in List Please try again");
		}
	
	}	
}


void deleteBeg()
{
	
	struct node *temp;
	
	temp=head;
	head=head->next;
	printf("\n%d deleted",temp->data);
	free(temp);
//	if(head == NULL){
//		printf("\nPlease add node.");
//	}
}

void deleteAny(int num)
{
	struct node *p,*q;
	int flag=0;
	
	p=head;
	q=head;
	while(p != NULL){
		
		if(p->data == num){
			flag=1;
			break;
		}
		q=p;
		p=p->next;
	}
	
	if(flag){
		if(p==head){
			deleteBeg();
		}else if(p->next == NULL){
			deleteNode();
		}else{
			q->next=p->next;
			printf("\n%d deleted",p->data);
			free(p);
		}
		
	}else if(head==NULL){
		printf("\nList is Empty ,Please add node.");
	}else{
		printf("\nNumber not found please try again");
	}
	
	
	
}





