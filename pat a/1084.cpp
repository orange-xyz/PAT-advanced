#include<iostream>
#include<vector>
#include<string>
using namespace std;

inline void prime(string &s){
	for(size_t i = 0;i != s.size();++i)
	if(s[i] >= 'a'&&s[i] <= 'z')
	s[i] = s[i] - 'a' + 'A';
} 
int main(void){
	int i,j = 0; 
	vector<bool> exist(1000,false);
	string s1,s2,broken;
	cin >> s1 >> s2;
	prime(s1);prime(s2); 
	for(i = 0;i != s1.size();++i){
		if(s1[i] != s2[j]){
			if(!exist[s1[i]]){
			exist[s1[i]] = true;
			broken += s1[i];	
			}
		}else
		j++;
	}
	cout << broken;
	return 0;
} 
