#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct cus{
	int pt;
	int st;
	int ct;
};
int main(void){
	int n,m,k,q,i,j;
	cin >> n >> m >> k >> q;
	cus cu[1000];
	int cusq[1000];
	for(i = 0;i < k;++i)
	cin >> cu[i].pt;
	for(i = 0;i < q;++i)
	cin >> cusq[i];
	queue<cus>win[20];
	int wint[20],cust[20];
	for(i = 0;i < n;++i)
		wint[i] = 0;
	for(i = 0;i < m;++i){
		for(j = 0;j < n;++j){
			if(i > 0)
			cust[j] += cu[n*(i-1)+j].pt;
			else
				cust[j] = 0;
			cu[i*n+j].st = cust[j];
			cu[i*n+j].ct = cu[i*n+j].pt + cu[i*n+j].st;
			win[j].push(cu[i*n+j]);
			wint[j] += cu[i*n+j].pt;
		}
	}
	int min;
	int key;
	for(j = n*m;j < k;++j){
		min = win[0].front().ct;
		key = 0;
	for(i = 0;i < n;++i){
		if(win[i].front().ct < min){
			min = win[i].front().ct;
			key = i;
		}
	}
		cu[j].st = win[key].front().st + wint[key];
		//cout << win[key].front().st << wint[key] << endl;
		cu[j].ct = cu[j].pt + cu[j].st;
		wint[key] += cu[j].pt;
		wint[key] -= win[key].front().pt;
		win[key].pop();
		win[key].push(cu[j]);
	}
	for(i = 0;i < q;++i){
		if(cu[cusq[i]-1].st < 9*60)
		printf("%.2d:%.2d\n",8+cu[cusq[i]-1].ct/60,cu[cusq[i]-1].ct%60);
		else
			cout << "Sorry" << endl;
	}
	system("pause");
	return 0;
}
