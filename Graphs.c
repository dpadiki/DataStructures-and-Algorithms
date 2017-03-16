#include <stdio.h>
#include <stdlib.h>

struct Graph 
{
	int v;
	struct AdjList* array;
};

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode* head;
};

struct Graph* Creategraph(int v)
{
	struct Graph* new = (struct Graph*)malloc(sizeof(struct Graph));
	new->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);
	new->v = v;

	int i;

	for(i=0;i<v;i++)
		new->array[i].head = NULL;

	return new;
}

struct AdjListNode* NewAdjListNode(int dest)
{
	struct AdjListNode* temp = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	temp->dest = dest;
	temp->next = NULL;

	return temp;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* new = NewAdjListNode(dest);
	new->next = graph->array[src].head;
	graph->array[src].head = new;

	//As it is an undirected graph.. Add an edge from dest to src.
	struct AdjListNode* new2 = NewAdjListNode(src);
	new2->next = graph->array[dest].head;
	graph->array[dest].head = new2;

}

void printGraph(struct Graph* graph)
{
	int i;

	for(i=0;i<graph->v;i++)
	{
		struct AdjListNode* crawl = graph->array[i].head;

		printf("Neighbours of %d are ",i);
		while(crawl!=NULL)
		{
			printf("-> %d",crawl->dest);
			crawl = crawl->next;
		}
		printf("\n");
	}
}


int main()
{
	struct Graph* graph = Creategraph(5);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);	
	return 0;
}