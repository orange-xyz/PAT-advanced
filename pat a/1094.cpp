#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(void){
	int n,m;
	int i,j;
	int fid,son;
	cin >> n >> m;
	vector<vector<int>> man(1000);
	for(i = 0;i < m;++i){
		cin >> fid >> son;
		int tmp;
		for(j = 0;j < son;++j){
			cin >> tmp;
			man[fid].push_back(tmp);
		}
	}

	queue<int> q,next;		//BFS
	q.push(1);
	int level = 0,cnt[1000];
	for(i = 0;i < 1000;++i)
		cnt[i] = 0;
	cnt[0] = 1;
	while(!q.empty()){
		level++;
		while(!q.empty()){
		int tmp = q.front();
		for(auto it = man[tmp].begin();it != man[tmp].end();++it){
			next.push(*(it));cnt[level]++;
		}
		q.pop();
		}
		swap(q,next);
	}
	int max = cnt[0];
	int key = 0;
	for(i = 0;i < 1000;++i){
		if(cnt[i] > max){
			max = cnt[i];
			key = i;
		}
	}
	printf("%d %d",max,key+1);
	system("pause");
	return 0;
}
