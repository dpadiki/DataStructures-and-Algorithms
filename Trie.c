#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define false 0
#define true 1
#define ALPHABET_SIZE 26
#define CHAR_TO_INT(c) (int)c - (int)'a';

// Trie insertion and searching

struct Node
{
	int isLeaf;
	struct Node* children[ALPHABET_SIZE];
};

struct Node* NewNode()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	if(temp)
	{
		temp->isLeaf = false;
		int i;

		for(i=0;i<ALPHABET_SIZE;i++)
			temp->children[i] = NULL;
	}

	return temp;
}

int search(struct Node* root,const char *key)
{
	int index;
	int level;
	int length = strlen(key);
	struct Node* crawl = root;

	for(level = 0;level<length;level++)
	{
		index = CHAR_TO_INT(key[level]);
		if(!crawl->children[index])
			return false;

		crawl = crawl->children[index];
	}

	return (crawl!=NULL && crawl->isLeaf);
}

void insert(struct Node* root,const char *key)
{
	int index;
	int length = strlen(key);
	int level;
	struct Node* crawl = root;

	for(level=0;level<length;level++)
	{
		index = CHAR_TO_INT(key[level]);
		if(!crawl->children[index])
			crawl->children[index] = NewNode();

		crawl = crawl->children[index];
	}
	crawl->isLeaf = true;
}

int main()
{
	char strings[][10] = {"the","a","there","answer","any","by","bye","their"};
	char output[][30] = {"Not present in trie","Present in trie"};

	int total = sizeof(strings)/sizeof(strings[0]);

	struct Node* root = NewNode();

	int i;

	for(i=0;i<total;i++)
		insert(root,strings[i]);

	printf("%s---%s\n","these",output[search(root,"these")]);
	printf("%s---%s\n","the",output[search(root,"the")]);
	printf("%s---%s\n","that",output[search(root,"that")]);
	printf("%s---%s\n","this",output[search(root,"this")]);
	printf("%s---%s\n","bye",output[search(root,"bye")]);
	
	return 0;
}
