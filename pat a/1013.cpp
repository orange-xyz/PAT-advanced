#include<iostream>
#include<string>
using namespace std;
int pre[1000];
int t[1000];
int find(int x){		//find the big brother
	int r = x;
	while(pre[r] != r)
		r = pre[r];
	
	int i = x,tmp;		//Ñ¹ËõÂ·¾¶ 
	while(pre[i] != r){
		tmp = pre[i];
		pre[i] = r;
		i = tmp;
	}

	return r;
}

void join(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx != fy)
	pre[fx] = fy;
}

int main(void){
	int n,m,k,i,j,cnt = 0;
	cin >> n >> m >> k;
	int x[m],y[m],che[k];
	for(i = 0;i < m;++i)
	cin >> x[i] >> y[i];
	for(i = 0;i < k;++i)
	cin >> che[i];
	
	
	for(i = 0;i < k;++i){
		for(j = 1;j <= n;++j)
		pre[j] = j;
		cnt = 0;
		for(j = 0;j < m;++j){
		if(x[j] != che[i]&&y[j] != che[i])
		join(x[j],y[j]);
	}
	for(j = 0;j <= n;++j)
		t[j] = 0;
	for(j = 1;j <= n;++j){
		t[find(j)] = 1;
	}	
	for(j = 1;j <= n;++j)
		if(t[j] == 1)	
			cnt++;
    cout << cnt-2 << endl;
	}

 return 0;
} 
