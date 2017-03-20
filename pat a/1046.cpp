#include<iostream>
using namespace std;
int main(void){
	int m,n,i,j;
	cin >> n;
	int dis[n];
	int sum = 0;
	for(i = 0; i < n; ++i){
		cin >> dis[i];
		sum += dis[i];
	}
	cin >> m;
	int ex[m][2];
	int sum1[m];
	int big, small;
	for(i = 0; i < m; ++i){
		cin >> ex[i][0];
		cin >> ex[i][1];
		sum1[i] = 0;
	}
	for(i = 0; i < m; ++i){
		big = ex[i][1]; small = ex[i][0];
		if(ex[i][0] > ex[i][1]){
		big = ex[i][0]; small = ex[i][1];
		}
		for(j = small - 1; j < big - 1; ++j){
			sum1[i] += dis[j];
		}
		if(sum1[i] < sum - sum1[i])
		cout << sum1[i] << endl;
		else
		cout << sum - sum1[i] << endl;
	}
}
