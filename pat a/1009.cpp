#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct pro{
		int n;
		double an;
	};
bool cmp(pro a,pro b){
	return a.n > b.n;
}
int main(void){
	int k1,k2,i,j,m,r = 0;
	cin >> k1;
	int n1[k1];
	double an1[k1];
	for(i = 0;i < k1;++i)
	cin >> n1[i] >> an1[i];
	
	cin >> k2;
	int n2[k2];
	double an2[k2];
	for(i = 0;i < k2;++i)
	cin >> n2[i] >> an2[i];
	
	int flg = 0;
	int sig;
	
	pro p[20];
	
	for(i = 0;i < k1;++i){
		for(j = 0;j < k2;++j){
			flg = 0;
			for(m = 0;m < r;++m)
			if(n1[i] + n2[j] == p[m].n){
				flg = 1;
				sig = m;
				break;	
			}
			
			if(flg == 0){
			p[r].n = n1[i] + n2[j];
			p[r].an = an1[i] * an2[j];
			r++;	
			}
			else if(flg == 1)
			p[sig].an += an1[i] * an2[j];
			
		}
	}
	

	sort(p,p+r,cmp);
	printf("%d",r);
	for(i = 0;i < r;++i){
		printf(" %d %.1f",p[i].n,p[i].an);
	}	
	return 0;	
} 
