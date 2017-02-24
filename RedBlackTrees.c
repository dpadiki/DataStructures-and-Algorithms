#include <stdio.h>
#include <stdlib.h>

enum color {RED,BLACK};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int color; 
};

struct Queue
{
    struct Node* data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

struct Node* pfront()
{
    struct Node* data ;
    data = front->data;
    return data;
}

int isempty()
{
    if(front==NULL)
        return 1;

    else
        return 0;
}

void dequeue()
{
    if(isempty())
        return ;

    struct Queue* temp = front;
    front = front->next;
    free(temp);
}


void enqueue(struct Node* data)
{
    struct Queue* temp  =(struct Queue*)malloc(sizeof(struct Queue));
    temp->data = data;
    temp->next = NULL;

    if(front==NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
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

        if(current->left!=NULL)
            enqueue(current->left);

        if(current->right!=NULL)
            enqueue(current->right);

        dequeue();
    }
}

void LeftRotate(struct Node** T,struct Node** x)
{
    struct Node* y = (*x)->right;
    (*x)->right = y->left;

    if((*x)->right!=NULL)
        (*x)->right->parent = (*x);

    y->parent = (*x)->parent;

    if((*x)->parent == NULL)
        *T = y;

    else if((*x) == (*x)->parent->left)
        (*x)->parent->left = y;

    else
        (*x)->parent->right = y;

    y->left = (*x);

    (*x)->parent = y;


}

void RightRotate(struct Node** T,struct Node** x)
{
    struct Node* y = (*x)->left;
    (*x)->left = y->right;

    if((*x)->left!=NULL)
        (*x)->left->parent = (*x);

    y->parent = (*x)->parent;

    if((*x)->parent==NULL)
        *T = y;

    else if((*x)== (*x)->parent->left)
        (*x)->parent->left = y;

    else
        (*x)->parent->right = y;

    y->right = *x;
    (*x)->parent = y;

}

void RB_insert_fixup(struct Node** T, struct Node** z)
{
    struct Node* grandparent = NULL;
    struct Node* parentpt = NULL;

    while(((*z)!=*T)&& ((*z)->color!= BLACK) && ((*z)->parent->color == RED))
    {
        parentpt = (*z)->parent;
        grandparent = (*z)->parent->parent;

        if(parentpt == grandparent->left)
        {
            struct Node* uncle = grandparent->right;

            if(uncle!=NULL && uncle->color == RED)
            {
                grandparent->color = BLACK;
                parentpt->color = BLACK;
                uncle->color = BLACK;
                *z = grandparent;
            }

            else 
            {   
                if((*z) == parentpt->right)
                {
                    LeftRotate(T,&parentpt);
                    (*z) = parentpt;
                    parentpt = (*z)->parent; 
                }

                RightRotate(T,&grandparent);
                parentpt->color = BLACK;
                grandparent->color = RED;
                (*z) = parentpt;
            }
        }

        else
        {
            struct Node* uncle = grandparent->left;

            if(uncle!=NULL && uncle->color == RED)
            {
                grandparent->color = BLACK;
                parentpt->color = BLACK;
                uncle->color = BLACK;
                (*z) = grandparent;
            }

            else 
            {   
                if((*z) == parentpt->left)
                {
                    RightRotate(T,&parentpt);
                    (*z) = parentpt;
                    parentpt = (*z)->parent; 
                }

                LeftRotate(T,&grandparent);
                parentpt->color = BLACK;
                grandparent->color = RED;
                (*z) = parentpt;
            }
        }
    }
    (*T)->color = BLACK;

}

struct Node* RB_insert(struct Node* T,int data)
{
    struct Node* z = (struct Node*)malloc(sizeof(struct Node));
    z->data = data;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    z->color = RED;

    struct Node* y = NULL;
    struct Node* x = T;//root

    while(x!=NULL)
    {
        y = x;
        if(z->data < x->data)
            x = x->left;

        else
            x = x->right;
    }
    z->parent = y;

    if(y==NULL)
        T = z;

    else if(z->data < y->data)
        y->left = z;

    else
        y->right = z;

    RB_insert_fixup(&T,&z);

    return T;
}

void preorder(struct Node* root)
{
    if(root==NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct Node* RBT = NULL;

    RBT = RB_insert(RBT,2);
    RBT = RB_insert(RBT,1);
    RBT = RB_insert(RBT,4);
    RBT = RB_insert(RBT,5);
    RBT = RB_insert(RBT,9);
    RBT = RB_insert(RBT,3);
    RBT = RB_insert(RBT,6);
    RBT = RB_insert(RBT,7);


    printf("\nPreorder - ");
    preorder(RBT);
    
    printf("\nLevel order - ");
    levelorder(RBT);
    
    return 0;
}