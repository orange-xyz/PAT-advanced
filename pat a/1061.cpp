#include<iostream>
#include<string>
using namespace std;
int main(void){
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int i,cnt = 0;
	for(i = 0;i < s1.size();++i){
		if(s1[i]-'A' >= 0&&s1[i]-'A' <= 7&&s1[i] == s2[i]&&cnt == 0){
				switch(s1[i]){
					case 'A': cout << "MON "; break;
					case 'B': cout << "TUE "; break;
					case 'C': cout << "WED "; break;
					case 'D': cout << "THU "; break;
					case 'E': cout << "FRI "; break;
					case 'F': cout << "SAT "; break;
					case 'G': cout << "SUN "; break;
				}
			cnt++;
		}
		else if(s1[i] == s2[i]&&((s1[i]-'A' >= 0&&s1[i]-'A' <= 13)||(s1[i]-'0' >= 0&&s1[i]-'0' <= 9))&&cnt ==1){
			if(s1[i]-'A' >= 0&&s1[i]-'A' <= 13)
			cout << s1[i]-'A'+10;
			else if(s1[i]-'0' >= 0&&s1[i]-'0' <= 9)
			cout << '0' << s1[i]-'0';
			cnt++;
		}
	}
	
	for(i = 0;i < s3.size();++i){
		if(s3[i] == s4[i]&&((s3[i]-'a' >= 0&&s3[i]-'a' <= 25)||(s3[i]-'A' >= 0&&s3[i]-'A' <= 25)))
		if(i < 10)
		cout << ':' << '0' << i << endl;
		else
		cout << ':' << i << endl; 
	}
	return 0;
}
