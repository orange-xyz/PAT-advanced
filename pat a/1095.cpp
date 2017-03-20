#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct car{
	string id;
	int in;
	int out;
	int time;
};
bool cmp(car a,car b){
	return a.time > b.time;
}
bool cmp1(car a,car b){
	return a.time < b.time;
}
int main(void){
	int n,m,k = 0;
	cin >> n >> m;
	car c[10000],cc[10000];
	int i,j;
	for(i = 0;i < 10000;++i){
		c[i].id = "";
		c[i].in = 0;
		c[i].out = 0;
		c[i].time = 0;
		cc[i].time = 0;
	}
	for(i = 0;i < n;++i){
		string tid,io;
		int hour,min,sec,time;
		cin >> tid;
		scanf("%d:%d:%d",&hour,&min,&sec);
		time = hour*3600+min*60+sec;
		cin >> io;
		c[i].id = tid;
		if(io == "in")
			c[i].in = time;
		else if(io == "out")
			c[i].out = time;
	}
	int qtime[10000];
	for(i = 0;i < m;++i){
	    int hour,min,sec,time;
		scanf("%d:%d:%d",&hour,&min,&sec);
		time = hour*3600+min*60+sec;
		qtime[i] = time;
	}
	sort(c,c+n,cmp1);	
	for(i = 0;i < n-1;++i){
		for(j = i+1;j <n;++j){
			if(c[i].id == c[j].id&&c[i].in !=0&&c[j].out != 0){
				cc[k].id = c[i].id;
				cc[k].in = c[i].in;
				cc[k].out = c[j].out;
				cc[k].time += cc[k].out - cc[k].in;
				k++;
				break;
			}
		}
	}
	sort(cc,cc+k,cmp);
	for(i = 0;i < k;++i)
		if(cc[i].time == cc[0].time)
			cout << cc[i].id << " ";
	int hour,min,sec;
	hour = cc[0].time/3600;
	min = (cc[0].time - 3600*hour)/60;
	sec = cc[0].time%60;
	printf("%02d:%02d:%02d",hour,min,sec);
	system("pause");
	return 0;
}