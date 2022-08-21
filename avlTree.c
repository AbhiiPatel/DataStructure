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
	int bf;
	if(root==NULL){
		root=createNode(data);

	}else{
		
		if(data < root->data){             //left side
			root->left = insertNode(root->left,data);
		}else{                             //right side
			root->right = insertNode(root->right,data);
		}
//		root->height=calculateHeight(root);
		
//		bf=balanceFactor(root);
//		printf(" [%d(%d)] ",root->data,bf);
	}
	root->height=calculateHeight(root);
	bf=balanceFactor(root);
	printf(" [%d(%d)] ",root->data,bf);
	
	if( !(bf>=-1 && bf<=1) ){
		printf(" *Rotation require for %d* ",root->data);
		 
		if(bf<0){
			if(data > root->right->data){
//				printf(" %d  %d",data,root->right->data);
				printf(" RR ");
			}else{
				printf(" RL ");
			}
		}else{
			if(data < root->left->data){
				printf(" LL ");
			}else{
				printf(" LR ");
			}
		}
		
	}
	
	return root;
}

int balanceFactor(struct node *root){
	
	int lh=0;
	int rh=0;
	
	if(root==NULL){
		return 0;
	}
	if(root->left != NULL){
		lh=root->left->height;
	}
	if(root->right != NULL){
		rh=root->right->height;
	}
	return lh-rh;
}

struct node* rightRotate(struct node *root){
	struct node *leftchild,*leftchildright;
	
	leftchild=root->left;
	leftchildright=leftchild->right;
	
	leftchild->right=root;
	root->left=leftchildright;	
	
	return leftchild;
	
}
struct node* leftRotate(struct node *root){
	struct node *rightchild,*rightchildleft;
	
	rightchild=root->right;
	rightchildleft=rightchild->left;
	
	rightchild->left=root;
	root->right=rightchildleft;	
	
	return rightchild;
	
}

void inOrder(struct node *root){
	
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d(%d)  ",root->data,root->height);
	inOrder(root->right);
}

int main(){
	printf("\n Inserting 100 ");
	root = insertNode(root,100);
	
//	printf("\n Inserting 150 ");
//		insertNode(root,150);
		
	
	printf("\n Inserting 50 ");
		insertNode(root,50);
	
	printf("\n Inserting 25 ");
		insertNode(root,25);
	printf("\n Inserting 70 ");
		insertNode(root,70);
	
//	printf("\n Inserting 300 ");
//		insertNode(root,300);
		
//	printf("\n Inserting 350 ");
//		insertNode(root,350);
//	printf("\n Inserting 120 ");
//		insertNode(root,120);
	printf("\n\nHeight of every node:\n\n");
	inOrder(root);
	
	return 0;
	
}
