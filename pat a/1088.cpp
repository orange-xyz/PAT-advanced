#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<sstream>
#include<math.h>
using namespace std;
int gcd(int x,int y){
	if(y == 0) return x;
	else return gcd(y,x%y);
	}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
char s[100][100];
int k = 0;
void c(int n,int d){
	 if(d == 0)
		sprintf(s[k],"Inf");
	else if(abs(n) > d&&n%d !=0)
		sprintf(s[k],"%d %d/%d",n/d,abs((n-d*(n/d))/gcd(n,d)),abs(d/gcd(n,d)));
	else if(abs(n) < d&& n!= 0)
		sprintf(s[k],"%d/%d",gcd(n,d)>0?n/gcd(n,d):-n/gcd(n,d),abs(d/gcd(n,d)));
	else if(n%d == 0)
		sprintf(s[k],"%d",n/d);

	if(n < 0){
		char tmp[100];
		sprintf(tmp,"(%s)",s[k]);
		sprintf(s[k],"%s",tmp);
	}
	k++;
}

int main(void){
	int n1,n2,d1,d2,i,j;
	scanf("%d/%d %d/%d",&n1,&d1,&n2,&d2);
	int num[4],den[4];
	num[0] = n1*d2+n2*d1;den[0] = d1*d2;
	num[1] = n1*d2-n2*d1;den[1] = d1*d2;
	num[2] = n1*n2;den[2] = d1*d2;
	num[3] = n1*d2;den[3] = n2*d1;
	c(n1,d1);c(n2,d2);
	for(i = 0;i < 4;++i){
		if(den[i] < 0){
			num[i] = -num[i];
			den[i] = -den[i];
		}
		c(num[i],den[i]);
	}
	for(i = 0;i < 4;++i){
				switch(i){
		case 0:
			sprintf(s[k],"%s + %s = %s",s[0],s[1],s[2]);
			k++;
			break;
		case 1:
			sprintf(s[k],"%s - %s = %s",s[0],s[1],s[3]);
			k++;
			break;
		case 2:
			sprintf(s[k],"%s * %s = %s",s[0],s[1],s[4]);
			k++;
			break;
		case 3:
			sprintf(s[k],"%s / %s = %s",s[0],s[1],s[5]);
			k++;
			break;
		}
	}
	for(i = 6;i < 10;++i){
		cout << s[i] << endl;
	}
	system("pause");
	return 0;
}
