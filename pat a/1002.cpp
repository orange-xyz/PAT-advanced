#include<iostream>
#include<string>
using namespace std;
int main(void){
	int k1,k2,i,j,k;
	cin >> k1;
	int n1[k1];
	float an1[k1];
	for(i = 0;i < k1;++i){
		cin >> n1[i] >> an1[i];
	}
	cin >> k2;
	int n2[k2];
	float an2[k2];
	for(j = 0;j < k2;++j){
		cin >> n2[j] >> an2[j]; 
	}
	int n[k1+k2];
	float an[k1+k2];
	i = 0;j = 0;k = 0;
	while(i < k1&&j < k2){
		if(n1[i] == n2[j]){
			n[k] = n1[i];
			an[k] = an1[i] + an2[j];
			i++;j++;k++;
		}
		else if(n1[i] > n2[j]){
			n[k] = n1[i];
			an[k] = an1[i];
			i++;k++;
		}
		else if(n1[i] < n2[j]){
			n[k] = n2[j];
			an[k] = an2[j];
			j++;k++;
		}
	} 
	int tmp = i;
	if(i >= k1)
	for(i = j;i < k2;++i){
		n[k] = n2[i];
		an[k] = an2[i];
		k++;
	}
	else if(j >= k2)
	for(i = tmp;i < k1;++i){
		n[k] = n1[i];
		an[k] = an1[i];
		k++;
	}
	int cntz = 0;
	for(i = 0;i <k;++i)
		if(an[i] == 0)
			cntz++;
	cout << k-cntz;
	for(i = 0;i < k;++i){
		if(an[i] != 0){
		cout << " " << n[i] << " ";
		printf("%.1f",an[i]);	
		}

	} 
	return 0;
}
