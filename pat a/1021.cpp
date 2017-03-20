#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define int_max 0xffffffff
int map[10000][10000];
int visit[10000];
int n;

void init(int n){
	int i,j;
	for(i = 0;i < n;++i){
		visit[i] = 0;
		for(j = 0;j < n;++j)
			map[i][j] = int_max;
	}
}

int dfs(int p){
	int i;
	int max = -1;
	int tmp = -1;
	int flg = 0;
	visit[p-1] = 1;
	for(i = 0;i < n;++i){
		if(map[p-1][i] == 1&&visit[i] == 0){
		    flg = 1;
			tmp = dfs(i+1);
			if(tmp > max)
			max = tmp;
		}	
	}
	if(flg == 0)
	return 1;
	return max+1;
}

int dfsn(){
	int cnt = 0,m;
	for(m = 0;m < n;++m)
		if(visit[m] == 0){
			dfs(m+1);
			cnt++;
		}
	return cnt;
}

int main(void){
	int i,j;
	int x,y,k;
	cin >> n;
	init(n);
	for(i = 0;i < n-1;++i){
		cin >> x >> y;
		map[x-1][y-1] = 1;
		map[y-1][x-1] = 1;
	}
	int h[n],maxh = 0;
	for(j = 1;j <= n;++j){		//这里用i的话循环体就运行一次，为什么呢？？？
		h[j] = dfs(j);
		if(h[j] > maxh)
		maxh = h[j];
		for(k = 0;k < n;++k)
			visit[k] = 0;
	}
	int cnt = dfsn();
	if(cnt > 1)
	printf("Error: %d components\n",cnt);
	else
	for(i = 1;i <= n;++i){
		if(h[i] == maxh)
			cout << i << endl;
	}

	return 0;
}
