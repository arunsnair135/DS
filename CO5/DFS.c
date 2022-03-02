#include<stdio.h>

int graph[10][10],v,visited[10];

void dfs(int x){
	printf("%d\t",x);
	visited[x]=1;
	for(int j=0;j<v;j++){
		if(!visited[j] && graph[x][j]==1){
			dfs(j);
		}
	}
}

void main(){
	printf("\nEnter the number of vertices ");
	scanf("%d",&v);
	printf("\nEnter the adjacency matrix\n");
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	
	for(int i=0;i<v;i++){
		graph[i][i]=0;
	}
	
	for(int i=0;i<v;i++){
		visited[i]=0;
	}
	printf("\nDEPTH FIRST SEARCH\n");
	dfs(0);
}
