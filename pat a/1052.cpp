#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct node{
	string add;
	int data;
	string next;
}*link;
bool cmp(node a,node b){
	return a.data < b.data;
}

int main(void){
	int n,root,i;
	cin >> n >> root;
	node lis[n];
	for(i = 0;i < n;++i){
		cin >> lis[i].add >> lis[i].data >> lis[i].next;
	}
	stable_sort(lis,lis+n,cmp);
	for(i = 0;i < n-1;++i){
		lis[i].next = lis[i+1].add;
	}
	lis[n-1].next = "-1";
	printf("%d %s\n",n,lis[0].add.c_str());
	for(i = 0;i < n;++i){
		printf("%s %d %s\n",lis[i].add.c_str(),lis[i].data,lis[i].next.c_str());
	}
	return 0;
}
