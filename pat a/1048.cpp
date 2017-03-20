#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
	int n,m,i,j,half;
	cin >> n >> m;
	int coin[100000];
	for(i = 0;i < n;++i)
	cin >> coin[i];
	sort(coin,coin+n);
	for(i = 0;i < n;++i){
		if(coin[i] >= m/2){
			if(coin[i] == m/2)
			half = i+1;
			else half = i;
			break; 
		}
	}
	int flg = 0,n1 = n;
	for(i = 0;i < half;++i){
	for(j = half;j < n1;++j)
		if(coin[i]+coin[j] > m){
			n1 = j;break;
		}

	for(j = half;j < n1;++j)
		if(coin[i]+coin[j] == m){
		printf("%d %d",coin[i],coin[j]);
		flg = 1;
		break;
		} 
		if(flg == 1)
		break;
				
	}
	
	if(flg == 0)
	cout << "No Solution";
	return 0;
}
