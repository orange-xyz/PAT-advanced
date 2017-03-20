#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
struct list{
	string add;
	char c;
	string next;
};
int main(void){
	string w1,w2;
	int n,i,j;
	list l[1000];
	string add1[1000],add2[1000];
	cin >> w1 >> w2 >> n;
	for(i = 0;i < n;++i){
		cin >> l[i].add >> l[i].c >> l[i].next;
	}
	int flg = 0;
	int k = 0,r = 0;
	add1[0] = w1,add2[0] = w2;
	while(add1[k] != "-1")
	for(i = 0;i < n;++i){
		if(l[i].add == add1[k]){
			add1[++k] = l[i].next;
			break;
		}
	}
	while(add2[r] != "-1")
	for(i = 0;i < n;++i){
		if(l[i].add == add2[r]){
			add2[++r] = l[i].next;
			break;
		}
	}
	for(i = 0;i < k;++i){
		for(j = 0;j < r;++j)
			if(add1[i] == add2[j]){
				cout << add2[j];
				flg = 1;
				break;
			}
		if(flg == 1)
			break;
	}

	if(flg == 0)
		cout << "-1";
	system("pause");
	return 0;
}
			