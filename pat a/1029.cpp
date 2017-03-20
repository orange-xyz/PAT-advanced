#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	int i,j;
	int n1,n2;
	vector<int>s;
	cin >> n1;
	int tmp; 
	for(i = 0;i < n1;++i){
		scanf("%d",&tmp);
	    s.push_back(tmp);
	}
	cin >> n2;
	for(i = n1;i < n1+n2;++i){
		scanf("%d",&tmp);
	    s.push_back(tmp);
	}
	
	sort(s.begin(),s.end());
	if((n1+n2)%2 == 0)
	cout << s[(n1+n2)/2-1];
	else 
	cout << s[(n1+n2)/2];
return 0;
} 
