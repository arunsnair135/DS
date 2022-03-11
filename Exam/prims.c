#include<stdio.h>
#define inf 1000

int g[10][10],visited[10],v;

void prims(){
	int edge_count=0,cost,total=0,x,y;
	visited[0]=1;
	printf("\n  Edge    Weight");
	while(edge_count<v-1){
		cost=inf;
		for(int i=0;i<v;i++){
			
			if(visited[i]){
				for(int j=0;j<v;j++){
					if(!visited[j] && g[i][j]){
						if(g[i][j] < cost){
							cost=g[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		printf("\n%d  -  %d    %d",x,y,cost);
		total+=cost;
		visited[y]=1;
		edge_count++;
	}
	printf("\nTOTAL COST= %d ",total);
}

void main(){
	printf("\nEnter the number of vertices  ");
	scanf("%d",&v);
	printf("\nEnter the Matrix\n");
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			scanf("%d",&g[i][j]);
		}
	}

	for(int i=0;i<v;i++){
		visited[i]=0;
	}

	prims();

}
