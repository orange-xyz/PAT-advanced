#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n[3],i;
	string s = "#";
	cin >> n[0] >> n[1] >> n[2];
	for(i = 0; i < 3; ++i){
	if(n[i]/13 > 9)
	s += ('A'+n[i]/13-10);
	else
	s += ('0'+n[i]/13);
	
	if(n[i]%13 > 9)
	s += ('A'+n[i]%13-10);
	else
	s += ('0'+n[i]%13);
	}
	cout << s << '\n';
	return 0;
}
