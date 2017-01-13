#include "stdio.h"


void sort(int A[],int n)
{
	
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