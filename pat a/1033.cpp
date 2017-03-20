#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct station{
	double price;
	int dist;
};
bool cmp(station s1,station s2){
	return s1.dist < s2.dist;
}
int main(void){
	int cmax,d,davg,n,i,j,dis = 0;
	double cost = 0.0;
	station s[500];
	for(i = 0;i < n;++i){
		cin >> s[i].price >> s[i].dist;
	}
	int flg = 0;
	sort(s,s+n,cmp);
	for(i = 0;i < n-1;++i)
		if(s[i+1].dist - s[i].dist > cmax*davg){
			dis = s[i].dist;
			flg = 1;
		}
	if(flg == 0&&d - s[n-1].dist > cmax*davg){
		dis = s[n-1].dist;
		flg = 1;
	}
	station now = s[0];
	if(flg == 0)
	for(i = 0;i < n;++i){
		if(s[i].price < now.price&&s[i].dist - now.dist > 0&&s[i].dist - now.dist < cmax*davg){
			cost +=now.price*(s[i].dist - now.dist);
			now = s[i];
		}
	}
	system("pause");
	return 0;
}