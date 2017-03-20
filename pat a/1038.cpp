#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int cmp(string s1,string s2){
	int i,j = 0,flg = 0,minsize,maxsize;
	string s3 = "";
	minsize = s1.size()>s2.size()?s2.size():s1.size();
	maxsize = s1.size()>s2.size()?s1.size():s2.size();
	for(i = minsize;i < maxsize;++i){
		s3 += s1.size()>s2.size()?s1[i]:s2[i];
	}
	for(i = 0;i < minsize;++i)
		if(s1[i] != s2[i]){
		flg = 1;break;
		}
	if(s1 == ""||s2 == ""||flg == 1){
		return s1 < s2;
	}

	else {
		return cmp(s1.size()>s2.size()?s3:s1,s1.size()>s2.size()?s2:s3);
	}
	
}

int main(void){
	string s[10000];
	int n,i;
	cin >> n;
	for(i = 0;i < n;++i)
	cin >> s[i];
	sort(s,s+n,cmp);
	string ss;
	for(i = 0;i < n;++i)
	ss += s[i];
	int flg = 0;
	for(i = 0;i < ss.size();++i){
		if(ss[i] != '0' || flg == 1){
			flg = 1;
			cout << ss[i];
		}
	}
	if(flg == 0)
	cout << "0";
	return 0;
}
