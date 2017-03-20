#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
string plusreverse(string n){
	int i,carry[100];
	string result;
	char c;
	carry[0] = 0;
	for(i = 0;i < n.size();++i){
		c = (n[i]-'0'+n[n.size()-i-1]-'0'+carry[i])%10 + '0';
		carry[i+1] = (n[i]-'0'+n[n.size()-i-1]-'0')/10;
		result = c + result;
	}
	if(carry[n.size()] > 0){
		c = carry[n.size()]+'0';
		result = c + result;
	}
	return result;
}
int pali(string n){
	int i,flg = 1;
	for(i = 0;i < n.size();++i){
		if(n[i] != n[n.size()-i-1]){
			flg = 0; break;
		}
	}
	return flg;
}

int main(void){
	int k,i;
	string n;
	cin >> n >> k;
	for(i = 0;i <= k;++i){
		//if(pali(n)||(i == k)){
			cout << n << endl;
			cout << i << endl;
			//break;
		//}
		 n = plusreverse(n);
	}
	system("pause");
	return 0;
}