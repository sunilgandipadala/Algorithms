//This is a program to implement BellMan Ford algorithm.
//lets create a graph dynamically from the user...for this he needs to be enter the vertices.. greater than 0 and less than or equal to the no.of vertices.

//in this we will find the shortest path from source vertex to remaining every vertex.
#include<stdio.h>
#define INF 999

struct Edges{
	int vert1;
	int vert2;
};
struct Edges edges[100];
int main(){
	int no_vertices,no_edges,i,j,k,m,vertex1,vertex2,cost,source;
	printf("Enter the number of vertices: ");
	scanf("%d",&no_vertices);
	printf("Enter the number of edges: ");
	scanf("%d",&no_edges);
	const int size=no_vertices;
	int graph[size][size];
	int relaxation[size];
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(i==j){
				graph[i][j]=0;
			}
			else{
				graph[i][j]=INF;
			}
		}
	}

	
	for(i=0;i<no_edges;i++){
		printf("Enter the edge vertices from which to which... and the cost of the edge(weight): ");
		scanf("%d %d %d",&k,&m,&cost);
		if(k>no_vertices||m>no_vertices){
			i--;j--;
			printf("Enter the vertices.. with in the range only...");
			continue;
		}
		else{
			graph[k][m]=cost;
			edges[i].vert1=k;
			edges[i].vert2=m;
		}	
	}
	for(i=1;i<size;i++){
			relaxation[i]=INF;
	}
	relaxation[0]=0;
	for(k=0;k<no_vertices;k++){
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(relaxation[i]+graph[i][j]<relaxation[j]){
					relaxation[j]=relaxation[i]+graph[i][j];
				}
			}
		}
	}
	printf("\n relaxation..\n");
	for(i=0;i<size;i++){
		printf("from source 0 to %d vertex cost is: %d \n",i,relaxation[i]);
	}


}