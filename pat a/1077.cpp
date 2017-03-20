#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,i,j,k;
	cin >> n;
	string s[n];
	string ku,kub;
	for(i = 0;i < n;++i){
		getline(cin,s[i]);
	}
	
	i = s[0].size();
	j = s[1].size(); 
	while(i > 0&&j > 0){
		if(s[0][i-1] != s[1][j-1])
		break;
		ku += s[1][i-1];
		i--;j--;
	}
	
	for(k = 3;k < n;++k){
		i = s[k].size();
		j = ku.size();
		while(i > 0&&j > 0){
			if(s[k][i-1] != ku[j-1])
			break;
			kub += ku[j-1];
			i--;j--;
		}
		ku = kub;
		kub = "";
	}
	if(ku == "")
	cout << "nai";
	else
	for(i = ku.size()-1;i >= 0;--i)
	cout << ku[i];
	return 0;
}
