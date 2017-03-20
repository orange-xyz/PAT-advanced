#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(void){
	int n,i,j,slash;
	double num,den;
	string nums,dens;
	cin >> n;
	string s[n];
	double v[n],sum = 0.0;
	for(i = 0;i < n;++i)
	cin >> s[i];
	for(i = 0;i < n;++i){
		for(j = 0;j < s[i].size();++j){
			if(s[i][j] == '/'){
				slash = j;break;
			}
		}
			if(s[i][0] == '-'){
				for(j = 1;j < slash;++j)
				nums += s[i][j];
				for(j = slash + 1;j < s[i].size();++j)
				dens += s[i][j];
			}
			else{
				for(j = 0;j < slash;++j)
				nums += s[i][j];
				for(j = slash + 1;j < s[i].size();++j)
				dens += s[i][j];				
			}
			num = atoi(nums.c_str());
			den = atoi(dens.c_str());
			nums = "";dens = "";
			v[i] = (s[i][0] == '-')?(-num/den):(num/den);	
			sum += v[i];
	}
	cout << sum;
	return 0;
} 
