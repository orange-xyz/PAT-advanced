#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
struct color{
	int num;
	int cnt;
};
bool cmp(color a,color b){
	return a.cnt > b.cnt;
}
int main(void){
	int n,m,l,i,j,k = 0;
	int tmp;
	color s1[10000];
	color s2[10000];
	vector<int> v;
	cin >> n;
	cin >> m;
	for(i = 0;i < m;++i){
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	cin >> l;
	for(i = 0;i < l;++i){
		scanf("%d",&s2[i].num);
	}

	for(i = 0;i < l;++i){
		int max = 0;
		vector<int>::iterator f1 = find(v.begin(),v.end(),s2[i].num);
		for(j = 0;j < i;++j){
			vector<int>::iterator f2 = find(v.begin(),v.end(),s2[j].num);
			if(f2 <= f1&&s2[j].cnt > max)
				max = s2[j].cnt;
		}
		s2[i].cnt = max + 1;
	}
	sort(s2,s2+l,cmp);
	cout << s2[0].cnt;
	system("pause");
	return 0;
}
