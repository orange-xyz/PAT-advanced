#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct stud{
	string sid;
	int mark;	
	int fr;
	int ln;
	int lr;
};

bool cmp(stud a,stud b){
	return a.mark > b.mark;
}
bool cmps(stud a,stud b){
	return a.sid < b.sid;
}
int main(void){
	int n,i,j,sum = 0;
	stud sd[100][300];
	cin >> n;
	int k[n];
	for(i = 0;i < n;++i){
		cin >> k[i];
		sum += k[i];
		for(j = 0;j < k[i];++j){
			cin >> sd[i][j].sid >> sd[i][j].mark;
			sd[i][j].ln = i + 1;
		}
	}
	
	stud sds[sum];
	int m = 0;
	int tsum = 0;
	for(i = 0;i < n;++i){
		for(j = 0;j < k[i];++j){
			sds[m++] = sd[i][j];
		}
		stable_sort(sds+tsum,sds+tsum+k[i],cmp);
		for(j = tsum;j < tsum+k[i];++j){
		if(sds[j].mark == sds[j-1].mark)
		sds[j].lr = sds[j-1].lr;
		else
		sds[j].lr = j+1-tsum;
		}	
		tsum = k[i];
	}
	cout << sum << endl;
	stable_sort(sds,sds+sum,cmps);
	stable_sort(sds,sds+sum,cmp);
	for(i = 0;i < sum;++i){
		if(sds[i].mark == sds[i-1].mark)
		sds[i].fr = sds[i-1].fr;
		else
		sds[i].fr = i+1;
	}
	for(i = 0;i < sum;++i)
	printf("%s %d %d %d\n",sds[i].sid.c_str(),sds[i].fr,sds[i].ln,sds[i].lr);	
	return 0;
}
