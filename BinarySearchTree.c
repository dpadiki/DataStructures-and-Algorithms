#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0

struct bstNode
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
};

struct bstNode* Newnode(int n)
{
	struct bstNode* temp;

	temp = (struct bstNode*)malloc(sizeof(struct bstNode));

	temp->data = n;
	temp->right = temp->left = NULL;

	return temp;
}

int search(struct bstNode* root , int data)
{
	if(root==NULL)  
		return false;
	
	else if(root->data == data)  
		return true;

	else if(data <= root->data)
		return search(root->left,data);

	else
		return search(root->right,data);
}

struct bstNode* insert(struct bstNode* root ,int n)
{
	if(root==NULL){
		root = Newnode(n);
	}

	else if(n <= root->data)
		root->left = insert(root->left,n);

	else 
		root->right = insert(root->right,n);

	return root;
}

int main()
{
 	struct bstNode* root;

 	int i;

 	root = NULL;
 	root = insert(root , 15);
 	root = insert(root , 20);
 	root = insert(root , 25);
 	root = insert(root , 8);
 	root = insert(root , 12);
 	root = insert(root , 14 );

 	printf("Enter number to be searched :\n");
 	scanf("%d",&i);

 	if(search(root,i))
 		printf("Found");

 	else
 		printf("Not Found");

 	return 0;
}