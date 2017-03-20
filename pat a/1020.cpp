#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}*bitree;

int n,i,j;
int post[30],inor[30];
bitree built(int le,int re,int ile,int ire){
	int tmp = 0;
	if(re >= le&&ire >= ile){
	bitree tmpn = new node;
	tmpn->data = post[re];
	for(i = ile;i <= ire;++i)
	if(inor[i] == post[re]){
		tmp = i;
		break;
	}
	tmpn->left = built(le,le+tmp-ile-1,ile,tmp-1);
    tmpn->right = built(re-1-(ire-tmp-1),re-1,tmp+1,ire);
	return tmpn;
	}
	else return NULL;
}
queue <bitree> q;
void level(bitree b,bitree stn){
	bitree p;
	q.push(b);
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(p == stn)
		cout << (*p).data;
		else cout << " " << (*p).data;
		if(p->left != NULL)
			q.push(p->left);
		if(p->right != NULL)
			q.push(p->right);	
	}
}

int main(void){
	bitree stn;
	cin >> n;
	for(i = 0;i < n;++i){
		cin >> post[i];
	}
	for(i = 0;i < n;++i){
		cin >> inor[i];
	}
	stn = built(0,n-1,0,n-1);
	level(stn,stn);
	return 0;
}
