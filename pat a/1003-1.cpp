#include<iostream>
#include<algorithm>
#include<string>
#include<limits>
#include<vector>
#define INT_MAX 0xffffffff
using namespace std;
const int MAX = 500;
int visited[MAX],map[MAX][MAX],res[MAX];
int mind = INT_MAX,n,maxr,cnt,i,j;

void init(int n){
	int i,j;
	for(i = 0;i < n;++i){
		visited[i] = 0;
		for(j = 0;j < n;++j)
		map[i][j] = INT_MAX;
	}
}
void dfs(int p,int e,int dist,int rest){
	if(p == e){
		if(dist < mind){
			cnt = 1;
			mind = dist;
			maxr = rest;
		}
		else if(dist == mind){
			cnt++;
			if(maxr < rest)
			maxr = rest;
		}
		return;
	}	
	if(dist > mind) return;
	for(i = 0;i < n;++i){
		if(visited[i] == 0&&map[p][i] != INT_MAX){
			visited[i] = 1;
			dfs(i,e,dist+map[p][i],rest+res[i]);
			visited[i] = 0;
		}
	}
	
}
int main(void){
	int n,m,c1,c2;
	int a,b,d;
	cin >> n >> m >> c1 >> c2;
		init(n);
	for(i = 0;i < n;++i)
	cin >> res[i];
	for(i = 0;i < m;++i){
		cin >> a >> b >> d;
		map[a][b] = d;
		map[b][a] = d;
	}
   dfs(c1,c2,0,res[c1]);
	cout << cnt << " " << maxr;
	return 0;
}
