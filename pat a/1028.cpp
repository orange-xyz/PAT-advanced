#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct man{
	char id[8];
	char name[8];
	int grade;
};
int c;
bool cmpc(char c1[8],char c2[8]){
	bool flg = true;
	for(int i = 0;i < 8;++i)
		if(c1[i] != c2[i]){
			flg = false;
			break;
		}
	return flg;
}

int cmp(man m1,man m2){
	int i = 0;
	if(c == 1){
		while(m1.id[i] == m2.id[i])
			i++;
		return m1.id[i] < m2.id[i];
	}
	else if(c == 2&&!cmpc(m1.name,m2.name)){
		i = 0;
		while(m1.name[i] == m2.name[i])
			i++;
		return m1.name[i] < m2.name[i];
	}
	else if(c == 3&&m1.grade != m2.grade)
		return m1.grade < m2.grade;
	else{
		i = 0;
		while(m1.id[i] == m2.id[i])
			i++;
		return m1.id[i] < m2.id[i];
	}
}
int main(void){
	int n;
	scanf("%d%d",&n,&c);
	int i;
	man m[10000];
	for(i = 0;i < n;++i){
		scanf("%s%s%d",m[i].id,m[i].name,&m[i].grade);
	}
	//cout << m[0].id << endl;
	sort(m,m+n,cmp);
	for(i = 0;i < n;++i)
		printf("%s %s %d\n",m[i].id,m[i].name,m[i].grade);
	system("pause");
	return 0;
}
