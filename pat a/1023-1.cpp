#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int dig[10];
void digi(string s){
	int i;
	for(i = 0;i < s.size();++i)
	dig[s[i] - '0']++;
}

void digi1(string s){
	int i;
	for(i = 0;i < s.size();++i)
	dig[s[i] - '0']--;
}
int main(void){
	int i;
	for(i = 0;i < 10;++i)
	dig[i] = 0;
	string s,s2;
	int carry = 0;
	char c;
	cin >> s;
	for(i = s.size()-1;i >= 0;--i){
		c = ((2*(s[i] - '0')+carry)%10 + '0');
		s2 = c + s2;
		carry = (2*(s[i] - '0')+carry)/10;
	}
	if(carry > 0){
		c ='0' + carry;
		s2 = c + s2;
	}
	int flg = 1;
	digi(s);
	digi1(s2);
	for(i = 0;i < 10;++i){
		if(dig[i] != 0){
		flg = 0;
		break;
		}
	}
	if(flg) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << s2;
	return 0;
}
