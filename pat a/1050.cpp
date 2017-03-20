#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define max 1000
int main(void){
	string s1,s2;
	int i;
	getline(cin,s1);
	getline(cin,s2);
	vector<bool> exist(max,false);
	for(i = 0; i < s2.size(); ++i){
		exist[s2[i]] = true;
	}
	for(i = 0; i < s1.size(); ++i){
		if(exist[s1[i]] == false)
		cout << s1[i];
	}
	cout << endl;
	return 0;
} 
