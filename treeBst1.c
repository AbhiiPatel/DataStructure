#include<stdio.h>
#include<malloc.h>

struct node{
	
	int data;
	struct node *left;
	struct node *right;
	
}*root=NULL;

struct node* createNode(int num){
	
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

struct node* addNode(int num,struct node *root){
	
	if(root==NULL){
		root=createNode(num);
	}else{
		if(root->data > num){              //left side
		
			root->left = addNode(num,root->left);
			
		}else{                             //right side
			
			root->right = addNode(num,root->right);
		}
		
	}
	return root;
}


int main(){
	
	root=addNode(50,root);
		 addNode(35,root);
		 addNode(100,root);
		 addNode(25,root);
		 addNode(150,root);
	
	printf("%d",root->data);  //50
	printf("\n%d",root->left->data);  //35
	printf("\n%d",root->right->data); //100
	printf("\n%d",root->left->left->data);  //25
	printf("\n%d",root->right->right->data);  //150
	
	return 0;
}
