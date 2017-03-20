#include<iostream>
using namespace std;
int main(void){
	int n,i,j,flg = 0;
	cin >> n;
	int num[n];
	int key[100000];
	for(i = 0;i < 100000; ++i){
		key[i] = 0;
	}
	for(i = 0;i < n; ++i){
		cin >> num[i];
		key[num[i]]++;
	}
	for(i = 0;i < n; ++i){
		if(key[num[i]] == 1){
		flg = 1;
		cout << num[i];
		break;			
		}
	}
	if(flg == 0)
	cout << "None";
	return 0;	
}