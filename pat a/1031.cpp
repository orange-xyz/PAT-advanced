#include<iostream>
#include<string>
using namespace std;
int main(void){
	string s;
	int n,n2,i,j;
	cin >> s;
	n = s.size();
	n2 = (n%3==1)?(n/3+1):(n/3+2);
	for(i = 0; i < (n+2-n2)/2-1; ++i){
		cout << s[i];
		for(j = 0; j < n2-2; ++j)
			cout << ' ';
		cout << s[n-1-i] << endl;
	}
	for(i = (n+2-n2)/2-1; i < n-(n+2-n2)/2+1; ++i){
		cout << s[i];
	}
}
