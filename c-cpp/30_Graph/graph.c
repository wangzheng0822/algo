#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct vertex;
struct vertex_adjs {
	struct vertex *v;
	struct vertex_adjs *next;
};

struct vertex {
	int data;
	struct vertex_adjs *adj;
};

#define MAX_GRAPH_VERTEX (1 << 8)
struct graph {
	struct vertex *vxs[MAX_GRAPH_VERTEX];
};

void init_graph(struct graph *graph)
{
	int i;

	for (i = 0; i < MAX_GRAPH_VERTEX; i++)
		graph->vxs[i] = NULL;
}

struct vertex *create_vertex(int data)
{
	struct vertex *v;

	v = malloc(sizeof(struct vertex));

	if (v) {
		v->data = data;
		v->adj = NULL;
	}

	return v;
}

struct vertex_adjs *create_vertex_adj(struct vertex *v)
{
	struct vertex_adjs *v_adj;

	v_adj = malloc(sizeof(struct vertex_adjs));

	if (!v_adj)
		return NULL;

	v_adj->v = v;
	v_adj->next = NULL;
	return v_adj;
}

void insert_adj(struct vertex *v, struct vertex *adj)
{
	struct vertex_adjs **v_adj;

	v_adj = &v->adj;

	while (*v_adj)
		v_adj = &(*v_adj)->next;

	*v_adj = create_vertex_adj(adj);
}

void dump_raw(struct graph *graph)
{
	int i;

	for (i = 0; i < MAX_GRAPH_VERTEX; i++) {
		struct vertex *v = graph->vxs[i];
		struct vertex_adjs *adj;
		if (v == NULL)
			continue;

		printf("Vertex[%02d]: %8d ->", i, v->data);

		adj = v->adj;
		while (adj) {
			printf(" %8d,", adj->v->data);
			adj = adj->next;
		}
		printf("\n");
	}
}

/* 
  1 ----- 2 ----- 3
  |     / |     /
  |    /  |    / 
  |   /   |   /  
  |  /    |  /   
  | /     | /    
  4 ----- 5
*/
void fake_a_graph(struct graph *graph)
{
	int i;

	init_graph(graph);

	for (i = 0; i < 5; i++)
		graph->vxs[i] = create_vertex(i+1);

	/* connect 1 -> 2, 1 -> 4 */
	insert_adj(graph->vxs[0], graph->vxs[1]);
	insert_adj(graph->vxs[0], graph->vxs[3]);
	/* connect 2 -> 1, 2 -> 3, 2 -> 5, 2 -> 4 */
	insert_adj(graph->vxs[1], graph->vxs[0]);
	insert_adj(graph->vxs[1], graph->vxs[2]);
	insert_adj(graph->vxs[1], graph->vxs[4]);
	insert_adj(graph->vxs[1], graph->vxs[3]);
	/* connect 3 -> 2, 3 -> 5 */
	insert_adj(graph->vxs[2], graph->vxs[1]);
	insert_adj(graph->vxs[2], graph->vxs[4]);
	/* connect 4 -> 1, 4 -> 2, 4 -> 5 */
	insert_adj(graph->vxs[3], graph->vxs[0]);
	insert_adj(graph->vxs[3], graph->vxs[1]);
	insert_adj(graph->vxs[3], graph->vxs[4]);
	/* connect 5 -> 4, 5 -> 2, 5 -> 3 */
	insert_adj(graph->vxs[4], graph->vxs[3]);
	insert_adj(graph->vxs[4], graph->vxs[1]);
	insert_adj(graph->vxs[4], graph->vxs[3]);
}

int main()
{
	struct graph g;

	fake_a_graph(&g);
	dump_raw(&g);
	return 0;
}
