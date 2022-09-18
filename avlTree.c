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
struct node* rightRotate(struct node *root){
	struct node *leftchild,*leftchildright;
	
	leftchild=root->left;
	leftchildright=leftchild->right;
	
	leftchild->right=root;
	root->left=leftchildright;	
	
	root->height=calculateHeight(root);
	leftchild->height=calculateHeight(leftchild);
	
	return leftchild;
	
}
struct node* leftRotate(struct node *root){
	struct node *rightchild,*rightchildleft;
	
	rightchild=root->right;
	rightchildleft=rightchild->left;
	
	rightchild->left=root;
	root->right=rightchildleft;	
	
	root->height=calculateHeight(root);
	rightchild->height=calculateHeight(rightchild);
	
	return rightchild;
	
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
				return leftRotate(root);
			}else{
				printf(" RL ");
				root->right=rightRotate(root->right);
				return leftRotate(root);
			}
		}else{
			if(data < root->left->data){
				printf(" LL ");
				return rightRotate(root);
			}else{
				printf(" LR ");
				root->left=leftRotate(root->left);
				return rightRotate(root);
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


void inOrder(struct node *root){
	
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d(%d)  ",root->data,root->height);
	inOrder(root->right);
}
struct node* inorderSuccesser(struct node *root){
	
	while(root!=NULL && root->left!=NULL){
		root=root->left;
	}
	return root;
}

struct node* deleteNode(struct node *root,int key){
	struct node *temp;
	int bf;
	
	if(root == NULL)
		return NULL;
		
	if(root->data == key){
		//delete logic
		
		if(root->left==NULL && root->right == NULL){
			free(root);
			return NULL;
		}else if(root->left==NULL && root->right != NULL){
			temp=root->right;
			free(root);
			return root->right;
		}else if(root->left!=NULL && root->right == NULL){
			temp=root->left;
			free(root);
			return temp;
		}else{
			//both side data present
			temp=inorderSuccesser(root->right);
			root->data=temp->data;
			return deleteNode(root->right,temp->data);
			
		}
	}else if(key > root->data){
		root->right = deleteNode(root->right,key);
	}else if(key < root->data){
		root->left = deleteNode(root->left,key);
	}
	
	
	root->height=calculateHeight(root);
	bf=balanceFactor(root);
	
	
	if( !(bf>=-1 && bf<=1) ){
		printf(" *Rotation require for %d* ",root->data);
		 
		if(bf<0){
			if(key > root->right->data){

				printf(" RR ");
				return leftRotate(root);
			}else{
				printf(" RL ");
				root->right=rightRotate(root->right);
				return leftRotate(root);
			}
		}else{
			if(key < root->left->data){
				printf(" LL ");
				return rightRotate(root);
			}else{
				printf(" LR ");
				root->left=leftRotate(root->left);
				return rightRotate(root);
			}
		}//end of else
		
	}//end of if  
	return root;
}

int main(){
	printf("\n Inserting 100 ");
	root = insertNode(root,100);
	
	printf("\n Inserting 150 ");
	root =	insertNode(root,150);
		
	
	printf("\n Inserting 50 ");
	root =	insertNode(root,50);
	
	
	printf("\n Inserting 75 ");
	root =	insertNode(root,75);
	
	printf("\n Inserting 25 ");
	root =	insertNode(root,25);
	
	printf("\n Inserting 10 ");
	root =	insertNode(root,10);
	
	printf("\n Inserting 65 ");
	root =	insertNode(root,65);
//	printf("\n Inserting 300 ");
//		insertNode(root,300);
		
//	printf("\n Inserting 350 ");
//		insertNode(root,350);
//	printf("\n Inserting 120 ");
//		insertNode(root,120);
	printf("\n\nHeight of every node:\n\n");
	inOrder(root);
	printf("\nRoot %d\n\n",root->data);
	
	
	deleteNode(root,50);
	
	printf("---------------After deleting---------------");
	printf("\n\nHeight of every node:\n\n");
	inOrder(root);
	printf("\nRoot %d",root->data);
	
	return 0;
	
	
}
