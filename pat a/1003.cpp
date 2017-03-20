#include<iostream>
#define MaxVertexNum 500
#define MaxNum 99999
using namespace std;
typedef int VertexType;
typedef int EdgeType;
typedef struct{
	VertexType vertex[MaxVertexNum];
	EdgeType edge[MaxVertexNum][MaxVertexNum];
	int n,e;
}Mgraph;
void dijkstra(G){
	
}
int main(Mgraph *G){
	int i,j,k;
	int a[e-1][1];
	int ivertex,dvertex;
	std::cin>>G->n>>G->e;
	std::cin>>ivertex>>dvertex;
	for(i = 0;i < n;i++){
		std::cin>>G->vertex[i];
	}
	for(i = 0;i < e;i++){
		std::cin>>a[i][0]>>a[i][1];
		for(j = 0;j < n;j++){
			for(k = 0;k < n;k++){
				if((j == a[i][0])&&(k == a[i][1]))
				std::cin>>G->edge[j][k];
				else
				G->edge[j][k] = MaxNum;
			}
		}
	}
	dijkstra(G); 
}

