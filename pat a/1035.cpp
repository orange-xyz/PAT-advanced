#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,i,j,k = 0,count = 0;
	int key[1000];
	string name[1000],psw[1000];
	cin >> n;
	for(i = 0; i < n; ++i){
		cin >> name[i] >> psw[i];
	}
	for(i = 0; i < n; ++i)
		for(j = 0; j < psw[i].size(); ++j){
			if(psw[i][j] == '1' || psw[i][j] == '0' || psw[i][j] == 'O' || psw[i][j] == 'l'){
				key[k] = i;
				k++;
				count++;
				break;
			}	
		}
	if(count == 0)
	if(n == 1)
	cout << "There is " << n << " account and no account is modified" << endl;
	else
	cout << "There are " << n << " accounts and no account is modified" << endl;
	else cout << count << endl;
	
	for(i = 0; i < n; ++i)
		for(j = 0; j < psw[i].size(); ++j){
			if(psw[i][j] == '1')
			psw[i][j] = '@';
			else if(psw[i][j] == '0')
			psw[i][j] = '%';
			else if(psw[i][j] == 'O')
			psw[i][j] = 'o';
			else if(psw[i][j] == 'l')
			psw[i][j] = 'L';
		}
		
	for(i = 0; i < k; ++i){
		cout << name[key[i]] << ' ' << psw[key[i]] << endl;
	}	
	return 0;
}
