#include<stdio.h>
#include<malloc.h>

struct node{
	
	int data;
	struct node *left,*right;
	int height;
}*root=NULL;

struct node* createNode(int data){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
int calculateHeight(struct node *root){
	int lh=0;
	int rh=0;
	
	if(root->left != NULL){
		lh=root->left->height;
	}
	if(root->right != NULL){
		rh=root->right->height;
	}
	
	if(lh>rh){
		return lh+1;
	}else{
		return rh+1;
	}
	
}

struct node* insertNode(struct node *root,int data){
	
	if(root==NULL){
		root=createNode(data);

	}else{
		
		if(data < root->data){             //left side
			root->left = insertNode(root->left,data);
		}else{                             //right side
			root->right = insertNode(root->right,data);
		}
	}
	root->height=calculateHeight(root);
	return root;
}

void inOrder(struct node *root){
	
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d(%d)  ",root->data,root->height);
	inOrder(root->right);
}

int main(){
	
	root = insertNode(root,50);
		insertNode(root,35);
		insertNode(root,25);
		insertNode(root,40);
		insertNode(root,100);
		insertNode(root,80);
		insertNode(root,150);
	
	printf("In order Traversal:\n\n");
	inOrder(root);
	
	return 0;
	
}
