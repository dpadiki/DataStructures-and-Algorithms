#include "stdio.h"

void swap(int *a,int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeapify(int A[],int n,int i)
{
	int l = (2*i)+1;
	int r = (2*i)+2;
	int smallest = i;

	if(l<n && A[l] > A[smallest])
		smallest = l;

	if(r<n && A[r] > A[smallest])
		smallest = r;

	if(smallest!=i)
	{
		swap(&A[i],&A[smallest]);
		MaxHeapify(A,n,smallest);
	}
}

void sort(int A[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		MaxHeapify(A,n,i);

	for(i=n-1;i>=0;i--)
	{
		swap(&A[0], &A[i]);
		MaxHeapify(A,i,0);
	}
	
}

int main()
{
	int A[] = {7,4,8,5,6,9,3,2,1};
	int n,i;

	n = sizeof(A) / sizeof(A[0]);

	sort(A,n);

	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}