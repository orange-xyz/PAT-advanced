#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct seq{
	int num;
	int v;
};
bool cmp(seq s1,seq s2){
	return s1.v < s2.v;
}
int main(void){
	int n,i,j;
	seq se[10000];
	cin >> n;
	for(i = 2;i < n/2;++i){
		int nn = n;
		j = i;
		while(nn%j == 0){
			nn/=j;
			j++;
		}
		se[i].v = j-i;
		se[i].num = i;
	}
	sort(se+2,se+n/2,cmp);
	cout << se[n/2-1].v << endl;
	printf("%d",se[n/2-1].num);
	for(i = 1;i < se[n/2-1].v;++i)
		printf("*%d",se[n/2-1].num+i);
	system("pause");
	return 0;
}