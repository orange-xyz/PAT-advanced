#include<iostream>
#include<queue>
#include<string>
#include<algorithm> 
#include<math.h>
using namespace std;
struct task{
	int ar_time;
	int se_time;
	int st_time;
	int co_time;
	friend bool operator < (task t1,task t2){
		return t1.co_time > t2.co_time;
	}
};
priority_queue<task>q;
int cmp(task t1,task t2){
	return t1.ar_time < t2.ar_time;
}

int time(string s){
	int t;
	t = 36000*(s[0]-'0') + 3600*(s[1]-'0') + 600*(s[3]-'0') + 60*(s[4]-'0') + 10*(s[6]-'0') + (s[7]-'0');
	return t; 
} 
task t[10000];
int main(void){
	int n,k,i,j,se;
	string ar;
	task tmp;
	double wait = 0;
	double cnt = 0;
	cin >> n >> k;
	for(i = 0;i < n;++i){
		cin >> ar >> se;
		t[i].ar_time = time(ar);
		t[i].se_time = se*60; 
	}
	sort(t,t+n,cmp);
	for(i = 0;i < k;++i){
		if(t[i].ar_time < 3600*8){
			t[i].st_time = 3600*8;
		}
		else t[i].st_time = t[i].ar_time;
		t[i].co_time = t[i].st_time + t[i].se_time;
		if(t[i].st_time <= 17*3600){
			wait += t[i].st_time - t[i].ar_time;
//			cout << wait << endl;
			cnt++;
		}
		q.push(t[i]);
	}
	for(i = k;i < n;++i){
		tmp = q.top();
		q.pop();
		t[i].st_time = max(tmp.co_time,t[i].ar_time);
		t[i].co_time = t[i].st_time + t[i].se_time;
		if(t[i].st_time <= 17*3600){
			wait += t[i].st_time - t[i].ar_time;
//			cout << wait << endl;
			cnt++;
		}
		q.push(t[i]);
	}
	double waitt ;
	if(cnt == 0)
	cout << "0.0";
	else{
	waitt = (wait/(cnt*60));
    printf("%.1lf",waitt);		
	}
	return 0;
}
