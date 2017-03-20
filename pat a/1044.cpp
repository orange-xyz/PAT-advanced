#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;
struct chain{
	int s;
	int end;
	int v;
};
int cmp(const void* c1,const void* c2){
	return (*(chain *)c1).v > (*(chain *)c2).v;
}
int main(void){
	int n,m;
	int a[10000];
	chain c[10000];
	int i,j,value = 0;
	cin >> n >> m;
	for(i = 0;i < n;++i)
		scanf("%d",&a[i]);
	for(i = 0;i < n;++i){
		value = 0;
		j = i;
		while(value < m){
			value += a[j++];
		}
		c[i].v = value;
		c[i].end = j-1;
		c[i].s = i;
	}
	qsort(c,n-1,sizeof(chain),cmp);
	int k;
	cout << c[1].v;
	for(i = 1;i < n;++i)
		if(c[i].v > c[0].v){
			k = i;
			break;
		}
	for(i = 0;i < k;++i){
		printf("%d-%d\n",c[i].s+1,c[i].end+1);
	}
	system("pause");
	return 0;
}