#include<iostream>
#include<algorithm>
using namespace std;
struct rat{
	int num;
	int w;
	int rank;
	int v;
};
bool cmp(rat r1,rat r2){
	return r1.w > r2.w;
}
bool cmpv(rat r1,rat r2){
	return r1.v > r2.v;
}
bool cmpn(rat r1,rat r2){
	return r1.num < r2.num;
}
int times(int a,int b){
	int cnt;
	while(a != 1){
		a = a/b+1;
		cnt++;
	}
	return cnt;
}
int remain(int a,int b,int t){
	int i;
	for(i = 0;i < t;++i)
	a = a/b+1;
	return a; 
}
int main(void){
	int np,ng,i,j;
	cin >> np >> ng;
	int order[1000];
	rat r[1000];
	int t = times(np,ng);
	for(i = 0;i < np;++i){
		cin >> r[i].w;
		r[i].num = i;	
	}
	for(i = 0;i < np;++i){
		cin >> order[i];
		r[i] = r[order[i]];
		r[i].v = 0;
	}

	for(i = 0;i < t;++i){
		for(j = 0;j < remain(np,ng,i);j+=ng){
			if(j+ng < remain(np,ng,i))
     		sort(r+j,r+j+ng,cmp);
			else sort(r+j,r+remain(np,ng,i),cmp);
			r[j].v++;
		}
		sort(r,r+remain(np,ng,i),cmpv);
		for(j = remain(np,ng,i+1);j < remain(np,ng,i);++j)
		r[j].rank = remain(np,ng,i+1)+1;
	}
	
	sort(r,r+np,cmpn);
	for(i = 0;i < np-1;++i)
	cout << r[i].rank << " ";
	cout << r[np-1].rank;
	return 0;
}
