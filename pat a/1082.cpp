#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
char num[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char num1[4][10] = {"qian","bai","shi",""};
void four(string s){
	if(s[0] == '-'){
		cout << "fu ";
		i = 1;
	}
	if(s.size()-i <= 4){
		for(j = s.size()-1-i;j > 0;--j){
			int flg = 0;
				if(s[s.size()-j-1] != '0'){
					if(s[s.size()-j-2] == '0')
						cout << num[0] << " ";
				cout << num[s[s.size()-j-1] - '0'] << " " << num1[3-j];
				for(int k = s.size()-j;k < s.size();++k)
					if(s[k] != '0'){
						flg = 1;
						break;
					}
				if(flg == 1)
					cout << " ";
				flg = 0;
				}
		}
		if(s[s.size()-1] != '0'){
			if(s[s.size()-2] == '0')
					cout << num[0] << " ";
		cout << num[s[s.size()-1] - '0'];
		}
	}
}
int main(void){
	
	string s;
	char ans[100];
	int i = 0,j;
	cin >> s;
	if(s[0] == '-'){
		cout << "fu ";
		i = 1;
	}
	if(s.size()-i <= 4){
		for(j = s.size()-1-i;j > 0;--j){
			int flg = 0;
				if(s[s.size()-j-1] != '0'){
					if(s[s.size()-j-2] == '0')
						cout << num[0] << " ";
				cout << num[s[s.size()-j-1] - '0'] << " " << num1[3-j];
				for(int k = s.size()-j;k < s.size();++k)
					if(s[k] != '0'){
						flg = 1;
						break;
					}
				if(flg == 1)
					cout << " ";
				flg = 0;
				}
		}
		if(s[s.size()-1] != '0'){
			if(s[s.size()-2] == '0')
					cout << num[0] << " ";
		cout << num[s[s.size()-1] - '0'];
		}
	}
	system("pause");
	return 0;
}

