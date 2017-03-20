#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,i;
	cin >> n;
	string flg[n];
	long long a[n],b[n],c[n];
	long long sum[n];
	for(i = 0;i < n;++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(i = 0;i < n;++i){
		sum[i] = a[i] + b[i];
		if(a[i] > 0&& b[i] > 0&& (a[i] > sum[i]||b[i] > sum[i]))
		flg[i] = "true";
		else if(a[i] < 0&& b[i] < 0&& (a[i] < sum[i]||b[i] < sum[i]))
		flg[i] = "false";
		else if(sum[i] > c[i])
		flg[i] = "true";
		else 
		flg[i] = "false";
	}
	for(i = 0;i < n;++i){
		cout << "Case #" << i+1 << ": " << flg[i] << endl;
	}
	return 0;
}
