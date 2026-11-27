#include <stdio.h>
#include <stdlib.h>

// 인접 배열로 표현된 그래프에 대한 깊이 우선탐색 프로그램 구현
#define MAX_VERTICES 50

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}

typedef struct GraphType{
	int n;
	struct GraphType *adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType *g){
	int r;
	g->n = 0;
	for(r = 0; r < MAX_VERTICES; r++){
		g->adj_list[r] = 0;
	}
}

void insert_vertex(GraphType *p, int start, int end){

}

int visited[MAX_VERTICES];

void dfs_list(GraphType *g, int v){
	GraphNode *w;
	visited[v] = TRUE;// 정점 v의 방문 표시
	printf("정점 %d -> ", v); // 방문한 정점 표시
	for(w = g->adj_list[v]; w; w = w->link){ // 인접 정점 탐색
		if(!visited[w->vertex]){
			dfs_list(g, w->vertex); // 정점 w에서 dfs 새로 시작
		}
	}
}