#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
int main(void){
	string s;
	cin >> s;
	int i;
	long long p = 0,pa = 0,pat = 0;
	for(i = 0;i < s.size();++i){
		if(s[i] == 'P')
			p++;
		else if(s[i] == 'A')
			pa += p;
		else if(s[i] == 'T')
			pat += pa;
	}
	cout << pat%1000000007;
	system("pause");
	return 0;
}