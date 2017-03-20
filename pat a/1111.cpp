#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<stdlib.h>
#define int_max 99999999;
using namespace std;
typedef struct graph{
	int dist;
	int time;
}g;

int n;
g map[500][500];
int visit[500];
int path[500];
int distan[500];
void init(int n){
	int i,j;
	for(i = 0;i < n;++i){
		visit[i] = 0;
		for(j = 0;j < n;++j){
			map[i][j].dist = 0;
			map[i][j].time = 0;
		}
	}
}

void dijkstra(int start){
	int i,j,k;
	for(i = 0;i < n;++i){
		if(map[start][i].dist > 0){
			path[i] = start;
			distan[i] = map[start][i].dist;
		}
		else{
			distan[i] = int_max;
			path[i] = -1;
		}
		visit[i] = 0;
		path[start] = start;
		distan[start] = 0;
	}
	visit[start] = 1;
	int u;
	for(i = 0;i < n-1;++i){
		int min = int_max;
		for(j = 0;j < n;++j)
			if(visit[j] == 0&&distan[j] < min){
				min = distan[j];
				u = j;
			}
		visit[u] = 1;
		for(k = 0;k < n;++k)
			if(visit[k] == 0&&map[u][k].dist > 0&&min + map[u][k].dist < distan[k]){
				distan[k] = min + map[u][k].dist;
				path[k] = u;
			}
	}

}

void showpath(int start,int end){
	stack<int>s;
	int u = end;
	while(start != u){
		s.push(u);
		u = path[u];
	}
	s.push(u);
	cout << "Distance = " << distan[end];
	while(!s.empty()){
		cout << s.top() <<" ";
		s.pop();
	}
}

int main(void){
	int m,i;
	cin >> n >> m;
	init(n);
	int x,y,one,d,t;
	for(i = 0;i < m;++i){
		cin >> x >> y >> one >> d >> t;
		map[x][y].dist = d;
		map[x][y].time = t;
		if(one == 0){
			map[y][x].dist = d;
			map[y][x].time = t;
		}
	}
	int start,end;
	cin >> start >> end;
	dijkstra(start);
	showpath(start,end);
	system("pause");
	return 0;
}