#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool prime(int n){
	int i;
	bool flg = true;
	for(i = 2;i <= sqrt(n);++i)
	if(n%i == 0){
		flg = false;
		break;
	}
	if(n == 2||n == 3)
	flg = true;
	else if(n == 0||n == 1)
	flg = false;
return flg;
} 

int reverse(int n,int d){
	int num[1000],sum = 0,i;
	int p = 0;
	while(n){
		num[p] = n%d;
		n /= d;
		p++;
	}
	for(i = 0;i < p;++i)
	sum += num[i]*pow(d,p-i-1);
	
	return sum;
}

int main(void){
	int i,j;
	int n[1000];
	int d[1000];
	for(i = 0;i < 1000;++i){
		n[i] = -1;
		d[i] = -1;
	}
	i = 0;
	cin >> n[0];
	while(n[i] >= 0){
		cin >> d[i++];
		cin >> n[i]; 
	}
	i = 0;
	while(n[i] >= 0){
		if(prime(n[i])&&prime(reverse(n[i],d[i]))){
		//cout << n[i] << reverse(n[i],d[i]) << endl;
		cout << "Yes" << endl;
		}

		else {
		//cout << n[i] << reverse(n[i],d[i]) << endl;
		cout << "No" << endl;		
		}
	
		i++;
	}
	return 0;
}
