#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
struct node{
	int key;
	int next;
	int pre;
};
struct node1{
	int add;
	int key;
	int next;
};
int main(void){
	int root,n,i;
	int add,key,next;
	int note[10000];
	for(i = 0;i < 10000;++i)
		note[i] = 0;
	node *no = new node[100000];
	node1 *no1 = new node1[100000];
	vector<int> v;
	cin >> root >> n;
	for(i = 0;i < n;++i){
		scanf("%d%d%d",&add,&key,&next);
		no[add].key = key;
		no[add].next = next;
		no[next].pre = add;
	}
	int tmpa = root;
	int k = 0;
	while(tmpa != -1){
		note[abs(no[tmpa].key)]++;
		if(note[abs(no[tmpa].key)] > 1){
			no[no[tmpa].pre].next = no[tmpa].next;
			no[no[tmpa].next].pre = no[tmpa].pre;
			no1[k].add = tmpa;
			no1[k].key = no[tmpa].key;
			k++;
		}
		tmpa = no[tmpa].next;
	}
	tmpa = root;
	while(tmpa != -1){
		printf("%05d %d ",tmpa,no[tmpa].key,no[tmpa].next);
		if(no[tmpa].next != -1)
			printf("%05d\n",no[tmpa].next);
		else 
			printf("-1\n");
		tmpa = no[tmpa].next;
	}
	for(i = 0;i < k-1;++i){
		no1[i].next = no1[i+1].add;
		
	}
	no1[k-1].next = -1;
	for(i = 0;i < k;++i){
	printf("%05d %d ",no1[i].add,no1[i].key);
	if(no1[i].next != -1)
		printf("%05d\n",no1[i].next);
	else 
		printf("-1\n");
	}
	system("pause");
	return 0;
}

