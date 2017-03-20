#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
int main(void){
	int n,i,j;
	string low[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}; 
	string high[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	string num[100];
	cin >> n;
	getchar();
	for(i = 0;i < n;++i){
		getline(cin,num[i]);
	}
	for(i = 0;i < n;++i){
		if(num[i][0] >= '0' &&num[i][0] <= '9'){
			stringstream ss;
			int stmp;
			ss << num[i];
			ss >> stmp;
			if(stmp/13 != 0){
				cout << high[stmp/13-1];
				if(stmp%13 != 0)
					cout << " "<< low[stmp%13-1] << endl;
				else cout << endl;
			}
			else{
				if(num[i] == "0")
					cout << "tret" << endl;
				else 
				cout << low[stmp%13-1] << endl;
			}
			ss.clear();
		}
		else{
			if(num[i].size() < 6){
				string tmp;
				tmp += num[i][0];
				tmp += num[i][1];
				tmp += num[i][2];
				for(j = 0; j < 12;++j){
					if(tmp == low[j])
						cout << j+1 << endl;
					else if(tmp == high[j])
						cout << 13*(j+1) << endl;
				}
				if(tmp == "tre")
					cout << "0" << endl;
				tmp = "";
			}
			else{
				int sum = 0;
				string tmp1;
				string tmp2;
				tmp1 += num[i][0];
				tmp1 += num[i][1];
				tmp1 += num[i][2];
				tmp2 += num[i][4];
				tmp2 += num[i][5];
				tmp2 += num[i][6];
				for(j = 0;j < 12;++j){
					if(tmp1 == high[j])
						sum += 13*(j+1);
					if(tmp2 == low[j])
						sum += j+1;
				}
				cout << sum << endl;
				tmp1 = "";
				tmp2 = "";
				sum = 0;
			}
		}
	}
	system("pause");
	return 0;
}

