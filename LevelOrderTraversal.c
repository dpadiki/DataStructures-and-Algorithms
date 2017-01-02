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

struct qnode
{
	struct Node* data;
	struct qnode* next;
};
struct qnode *front,*rear;

void enqueue(struct Node* root)
{
	struct qnode *temp;
	temp = (struct qnode*)malloc(sizeof(struct qnode));
	temp->data = root;
	temp->next = NULL;

	if(front==NULL && rear == NULL)
	{
		front = rear  =temp;
		return;
	}

	rear->next = temp;
	rear = temp;

}
int isempty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void pop()
{
	front = front->next;
}
struct Node* pfront()
{
	struct Node* temp;
	temp = front->data;

	return(temp);
}

struct Node* Newnode(int n)
{
	struct Node* temp;

	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = n;
	temp->right = temp->left = NULL;

	return temp;
}
void levelorder(struct Node* root)
{
	if(root==NULL)
		return;
	enqueue(root);

	while(!isempty())
	{
		struct Node* current = pfront();
		printf("%d ",current->data);
		if(current->left!=NULL) enqueue(current->left);

		if(current->right!=NULL) enqueue(current->right);
		pop();
		

	}
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

 	front = NULL;
 	rear = NULL;

 	root = NULL;
 	root = insert(root , 123);
 	root = insert(root , 20);
 	root = insert(root , 5);
 	root = insert(root , 300);
 	root = insert(root , 12);
 	root = insert(root , 100);

 	levelorder(root);
}