#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct prime{
	int v;
	int cnt;
};
prime p[50000];
bool isprime(int n){
	int i;
	bool flg = true;
	for(i = 2;i <= sqrt(n);++i)
		if(n%i == 0){
			flg = false;
			break;
		}
	return flg;
}

int addprime(int n){
	int i,j,k = 1,r;
	int tmp = n > 8000000?sqrt(n):n;
	for(i = 2;i <= tmp;++i){
		if(isprime(i)){
			int flg1 = 0;
			for(r = 0;r < k;++r){
				if(p[r].v == i){
				flg1 = 1;
				break;
			}
			}
			if(flg1 == 0){
				p[k].v = i;
				p[k++].cnt = 0;	
			}
		}
	}
	return k;
} 
int main(void){
	int n,k,i;
	cin >> n;
	if(isprime(n))
		printf("%d=%d",n,n);
	else{
	int n1 = n;
	p[0].v = 2;p[0].cnt = 0;
	k = addprime(n);
	while(n1 >= 2){
		for(i = k-1;i >= 0;i--){
			if(n1%p[i].v == 0){
				p[i].cnt++;
				n1 = n1/p[i].v;
			}
		}	
	}
	printf("%d=",n);
	int root;
	for(i = 0;i < k;++i){
		if(p[i].cnt > 0){
			root = i;
			break;
		} 
	}
		if(p[root].cnt > 1)
		printf("%d^%d",p[root].v,p[root].cnt);
		else if(p[root].cnt == 1)
		printf("%d",p[root].v);
	for(i = root+1;i < k;++i){
		if(p[i].cnt > 1)
		printf("*%d^%d",p[i].v,p[i].cnt);
		else if(p[i].cnt == 1)
		printf("*%d",p[i].v);
	}
	}
	system("pause");
	return 0;
}
