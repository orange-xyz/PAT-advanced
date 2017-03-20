#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(void){
	string s1,s2;
	vector<char> v1,v2;
	cin >> s1 >> s2;
	unsigned int i,j,flg =0;
	int miss = 0,extra = 0;
	for(i = 0;i < s1.size();++i)
		v1.push_back(s1[i]);
	for(i = 0;i < s2.size();++i){
		vector<char>::iterator it = find(v1.begin(),v1.end(),s2[i]);
		if(it == v1.end()){
			flg = 1;
			miss++;
		}
		else if(it != v1.end())
			v1.erase(it);
	}
	extra = s1.size() - s2.size();
	if(flg == 0)
		cout << "Yes " << extra;
	else 
		cout << "No " << miss;
	system("pause");
	return 0;
}