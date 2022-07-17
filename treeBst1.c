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

void inOrder(struct node *root){
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
	
}

void preOrder(struct node *root){
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
	
}

void postOrder(struct node *root){
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}
int main(){
	
	/*
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
	*/
	
	
	root=addNode(50,root);
		addNode(35,root);
		addNode(25,root);
		addNode(40,root);
		addNode(100,root);
		addNode(80,root);
		addNode(150,root);
		
		
	printf("\nIn order Traversal:\n");
	inOrder(root);
	printf("\nPre order Traversal:\n");
	preOrder(root);
	printf("\nPost order Traversal:\n");
	postOrder(root);
	
	return 0;
}
