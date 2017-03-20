#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main(void){
	int s,k;
	int s1,k1;
	int s2,k2;
	long long g1,g2,g;
	int c1,c2;
	scanf("%lld.%d.%d",&g1,&s1,&k1);
	scanf("%lld.%d.%d",&g2,&s2,&k2);
	k = (k1+k2)%29;
	c1 = (k1+k2)/29;
	s = (s1+s2+c1)%17;
	c2 = (s1+s2+c1)/17;
	g = g1+g2+c2;
	printf("%lld.%d.%d",g,s,k);
	system("pause");
	return 0;
}