#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	
};


void display(struct node *p){
	
	while(p != NULL){
	
		printf("Element:%d\n",p->data);
		p=p->next;
	}
}
int main(){
	
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	
	
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	fourth=(struct node*)malloc(sizeof(struct node));
	
	head->data=5;
	head->next=second;

	second->data=10;
	second->next=third;
	
	third->data=15;
	third->next=fourth;
	
	fourth->data=20;
	fourth->next=NULL;
	
	display(head);
		
	return 0;
}
