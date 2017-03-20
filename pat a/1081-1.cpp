#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
long long gcd(long long x,long long y){
	if(y == 0) return x;
	else return gcd(y,x%y);
}
long long lcm(long long x,long long y){
	return x*y/gcd(x,y);
}
int main(void){
	long long n,i;
	cin >> n;
	long long num[100],den[100];
	for(i = 0; i < n;++i)
		scanf("%lld/%lld",&num[i],&den[i]);
	long long tmp = den[0];
	for(i = 1;i < n;++i){
		tmp = lcm(tmp,den[i]);
	}
	long long snum = 0;
	for(i = 0;i < n;++i){
		snum += num[i]*tmp/den[i];
	}
	long long fnum = snum-tmp*(snum/tmp);
	if(snum/tmp != 0&&snum%tmp != 0)
		printf("%lld %lld/%lld",snum/tmp,fnum/gcd(fnum,tmp),tmp/gcd(fnum,tmp));
	else if(snum%tmp != 0)
		printf("%lld/%lld",fnum/gcd(fnum,tmp),tmp/gcd(fnum,tmp));
	else if(snum/tmp != 0)
		printf("%lld",snum/tmp);
	else if(snum/tmp == 0&&snum%tmp == 0)
		printf("0");
	system("pause");
	return 0;
}
