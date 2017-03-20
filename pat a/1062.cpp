#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct man{
	int id;
	int v;
	int t;
	int total;
};
bool cmp(man m1,man m2){
	if(m1.total != m2.total)
		return m1.total > m2.total;
	else if(m1.v != m2.v)
		return m1.v > m2.v;
	else return m1.id < m2.id;
}
int main(void){
	int n,l,h;
	cin >> n >> l >> h;
	int i,j;
	vector<man> m;
	man mm;
	for(i = 0;i < n;++i){
		scanf("%d%d%d",&mm.id,&mm.v,&mm.t);
		if(mm.v >= l&&mm.t >= l){
		mm.total = mm.v + mm.t;
		m.push_back(mm);
		}
	}
	//sort(m.begin(),m.end(),cmp);
	vector<man> sage;
	vector<man> nobleman;
	vector<man> fool;
	vector<man> elseman;
	for(auto it = m.begin();it != m.end();++it){
		if(it->v >= h&&it->t >= h){
			sage.push_back(*(it));
		}
		else if(it->v >= h&&it->t < h)
			nobleman.push_back(*(it));
		else if((it->v >= it->t)&&(it->v < h)&&(it->t < h))
			fool.push_back(*(it));
		else
			elseman.push_back(*(it));
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(nobleman.begin(),nobleman.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(elseman.begin(),elseman.end(),cmp);
	cout << m.size() << endl;
	for(auto it = sage.begin();it != sage.end();++it){
		printf("%08d %d %d\n",it->id,it->v,it->t);
	}
	for(auto it = nobleman.begin();it != nobleman.end();++it){
		printf("%08d %d %d\n",it->id,it->v,it->t);
	}
	for(auto it = fool.begin();it != fool.end();++it){
		printf("%08d %d %d\n",it->id,it->v,it->t);
	}
	for(auto it = elseman.begin();it != elseman.end();++it){
		printf("%08d %d %d\n",it->id,it->v,it->t);
	}
	system("pause");
	return 0;
}