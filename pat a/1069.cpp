#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;
string incr(string s){
	int i,j;
	char tmp;
	for(i = 0;i < s.size();++i)
		for(j = 0;j < s.size()-i-1;++j){
			if(s[j] > s[j+1]){
				tmp = s[j]; s[j] = s[j+1]; s[j+1] = tmp;	
			}
		}
		return s;
}

string decr(string s){
	int i,j;
	char tmp;
	for(i = 0;i < s.size();++i)
		for(j = 0;j < s.size()-i-1;++j){
			if(s[j] < s[j+1]){
				tmp = s[j]; s[j] = s[j+1]; s[j+1] = tmp;	
			}
		}
		return s;
}

int main(void){
	string s;
	stringstream ss;
	int s1,s2,s3 = 0;
	cin >> s;
	if(s[0] == s[1]&&s[0] == s[2]&&s[0] == s[3])
	cout << s << " - " << s << " = 0000" << endl;
	else{
	while(s3 != 6174){
	s1 = atoi(incr(s).c_str());
	s2 = atoi(decr(s).c_str());
		s3 = s2 - s1;
		printf("%s - %s = %d\n",decr(s).c_str(),incr(s).c_str(),s3);
		ss << s3;
		ss >> s;
		ss.clear();
		ss.str("");	
	}
	}
	return 0;
}
