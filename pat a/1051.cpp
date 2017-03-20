#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stack>
using namespace std;
int main(void){
	int m,n,k,i,j;
	cin >> m >> n >> k;	
	
	int flg[k];
	for(j = 0;j < k;++j){
		stack<int> s;
		int input;
		int tmp = 1;
		flg[j] = 1;
		for(i = 0;i < n;++i){
			cin >> input;
			while(s.size() <= m&&flg[j] == 1){
				if(s.empty()||input != s.top())
				s.push(tmp++);
			else if(input == s.top()){
				s.pop();
				break;	
			}
			}
		   if(s.size() > m)
			flg[j] = 0;
		}
	//while(!s.empty())
//	s.pop();
	}
	for(i = 0;i < k;++i){
	if(flg[i] == 0)	cout << "NO" << endl;
	else if(flg[i] == 1)	cout << "YES" << endl;
	}
	return 0;
}
