#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
using namespace std;
#define max 100000;

int main(void){
	int n;
	double p,rate;
	cin >> n >> p >> rate;
	vector<vector<int>> no(n);
	int i,j;
	int tmp,r;
	for(i = 0;i < n;++i){
		cin >> tmp;
		if(tmp == -1)
			r = i;
		else 
			no[tmp].push_back(i);
	}
	queue<int> q;
	queue<int> next;
	int l = 0,cnt = 0;
	q.push(r);
	while(!q.empty()){
		l++;
		cnt = q.size();
		while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(auto it = no[tmp].begin();it != no[tmp].end();++it)
			next.push(*(it));
		}
		swap(q,next);
	}
	double sum;
	sum = 1+rate/100;
	sum = pow(sum,l-1)*p;
	printf("%.2f %d",sum,cnt);
	system("pause");
	return 0;
}