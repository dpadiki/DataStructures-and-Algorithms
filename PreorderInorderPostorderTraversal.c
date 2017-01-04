#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* Newnode(int n)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->right = temp->left = NULL;

	return temp;
}
void preorder(struct Node* root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct Node* root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(struct Node* root)
{
	if(root==NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

struct Node* insert(struct Node* temp ,int n)
{
	if(temp==NULL){
		temp = Newnode(n);
	}

	else if(n <= temp->data)
		temp->left = insert(temp->left,n);

	else 
		temp->right = insert(temp->right,n);

	return temp;
}


int main()
{
 	struct bstNode* root;
 	root = NULL;
 	root = insert(root , 123);
 	root = insert(root , 20);
 	root = insert(root , 5);
 	root = insert(root , 300);
 	root = insert(root , 12);
 	root = insert(root , 100);

 	printf("Preorder : ");preorder(root);
 	printf("\nInorder : ");inorder(root);
 	printf("\nPostorder : ");postorder(root);
}