#include<iostream>
#include<queue>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#define int_max 999999;
using namespace std;
int map[500][500];
int visit[500];
int cost[500][500];
int dist[500];
int scost[500];
int path[500];
void dijkstra(int s,int n){
	int i,j,k;
	visit[s] = 1;
	int min = int_max;
	int minc = int_max;
	int u;
	for(i = 0;i < n;++i){
		if(map[s][i] != -1){
			dist[i] = map[s][i];
			scost[i] = cost[s][i];
			path[i] = s;
		}
	}
	for(i = 1;i < n;++i){
		min = int_max-1;
		minc = int_max-1;
		for(j = 0;j < n;++j){
			if(min > dist[j]&&visit[j] == 0){
				min = dist[j];
				minc = scost[j];
				u = j;
			}
			else if(min == dist[j]&&visit[j] == 0&&minc > scost[j]){
				minc = scost[j];
				u = j;
			}
		}

	visit[u] = 1;
	for(k = 0;k < n;++k){
		if(visit[k] == 0&&map[u][k] != -1){
			if(map[u][k]+min < dist[k]){
				dist[k] = map[u][k]+min;
				path[k] = u;
				scost[k] = cost[u][k] + minc;
			}
			else if(map[u][k]+min == dist[k]&&scost[k] > cost[u][k] + minc){
				path[k] = u;
				scost[k] = cost[u][k] + minc;
			}
		}
	}
}

}
int main(void){
	int n,m,s,d,i,j;
	cin >> n >> m >> s >> d;
	for(i = 0;i < 500;++i){
		visit[i] = 0;
		dist[i] = int_max;
		scost[i] = int_max;
		path[i] = -1;
		for(j = 0;j < 500;++j){
			map[i][j] = -1;
			cost[i][j] = int_max;
		}
	}
	for(i = 0;i < m;++i){
		int x,y,map1,cost1;
		cin >> x >> y >> map1 >> cost1;
		map[x][y] = map1;
		map[y][x] = map1;
		cost[x][y] = cost1;
		cost[y][x] = cost1;
	}
	dijkstra(s,n);
	int dd = d;
	stack<int> ps;
	do{
		ps.push(dd);
		dd = path[dd];
	}while(dd != -1);

	while(!ps.empty()){
		cout << ps.top() <<" ";
		ps.pop();
	}
	cout << dist[d] << " " << scost[d];
	system("pause");
	return 0;
}
