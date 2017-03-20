#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
string change(string n,int r1,int r2){
	int num = 0,i;
	string re;
	char *tmp,temp;
	for(i = n.size()-1;i >= 0;--i){
		if(n[i] >= '0'&&n[i] <= '9')
		num += (n[i] - '0')* pow(r1,n.size()-i-1);	
		else if(n[i] >= 'a'&&n[i] <= 'z')
		num += (n[i] - 'a' + 10) * pow(r1,n.size()-i-1);
	}
	while(num){
		if(num%r2 < 10)
		sprintf(tmp,"%d",num%r2);
		else
		sprintf(tmp,"%c",'a'+num%r2-10);
		re += tmp;
		num = num/r2;
	}
	for(i = 0;i < re.size();++i){
		temp = re[i];
		re[i] = re[re.size()-i-1];
		re[re.size()-i-1] = temp;
	}
	return re;	
}
int main(void){
	string num1,num2;
	int tag,radix,i,j;
	cin >> num1 >> num2 >> tag >> radix;
	if(tag == 1){
		for(i = 1;i < 35;++i){
			if(change(num1,radix,i) == num2)
			break;
		} 
		if(i != 35)
		cout << i;
		else
		cout << "Impossible";
	}
	else if(tag == 2){
		for(i = 1;i < 35;++i){
			if(change(num2,radix,i) == num1)
			break;
		} 
		if(i != 35)
		cout << i;
		else
		cout << "Impossible";
	}
	return 0;
}
