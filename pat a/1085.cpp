#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(void){
	long long n,p,i,j;
	long long seq[10000];
	int len[88000];
	scanf("%lld%lld",&n,&p);
	for(i = 0;i < n;++i)
		scanf("%d",&seq[i]);
	sort(seq,seq+n);
	for(i = 0;i < n;++i)
		if(seq[i] > seq[0]*p){
			len[0] = i;
			break;
		}
	if(seq[n-1] <= seq[0]*p)
		len[0] = n;
	int max = len[0];
	for(i = 1;i < n-len[0];++i){
		for(j = i+max;j < n;++j){
			if(seq[j] > seq[i]*p){
				len[i] = j-i;
				break;
			}
		}
		if(seq[n-1] <= seq[i]*p)
		len[i] = n-i;
		if(len[i] > max)
			max = len[i];
	}
	cout << max;
	system("pause");
	return 0;
}