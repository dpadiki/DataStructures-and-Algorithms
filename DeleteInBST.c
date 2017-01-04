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

struct Node* findmin(struct Node* root)
{
	while(root->left!=NULL)
		root = root->right;

	return root;
}

void inorder(struct Node* root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}


struct Node* Delete(struct Node* root, int data)
{
	if(root==NULL)
		return NULL;

	else if(data < root->data)
		root->left = Delete(root->left,data);

	else if(data > root->data)
		root->right = Delete(root->right,data);

	else // when data == root->data
	{
		// Case : 1 - NO child

		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root = NULL;
		}
		// case :2  - One child

		else if(root->left==NULL)
		{
			struct Node* temp;
			temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			struct Node* temp = root;
			root = root->left;
			free(temp);
		}

		else // case:3 - 2 Child .it will be reduced to either case 1 or case 2.
		{
			struct Node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}

	}

	return root;
}

struct Node* newnode(int n)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}
struct Node* insert(struct Node* root,int n)
{
	if(root==NULL)
		root = newnode(n);

	else if(n <= root->data)
		root->left = insert(root->left,n);

	else
		root->right = insert(root->right,n);

	return root;
}

int main()
{
	int n;
	struct Node* root;
	root = NULL;
	root = insert(root,15);
	root = insert(root,78);
	root = insert(root,5);
	root = insert(root,19);
	root = insert(root,24);
	root = insert(root,92);
	root = insert(root,10);
	root = insert(root,3);
	root = insert(root,13);

	
	printf("\nInorder : ");
	inorder(root);
	
	printf("\nEnter number to be deleted: ");
	scanf("%d",&n);

	root = Delete(root,n);

	printf("Inorder : ");
	inorder(root);

	return 0;
}