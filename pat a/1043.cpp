#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n;
int seq[1000];
typedef struct node{
	int v;
	node *rchild;
	node *lchild;
}*tree;
node *root = new node;
int built(node *root,int s,int e){
	//root = new node;
	int flg = 0;
	node *l = new node;
	node *r = new node;
	l->v = NULL;
	r->v = NULL;
	root->v = seq[s];
	if(s == e){
		root->lchild = NULL;
		root->rchild = NULL;
		return 0;
	}
	else{
	int k = s+1,j;
	for(j = s+1;j <= e;++j)
		if(seq[j] >= seq[s]){
			k = j;
			break;
		}
	for(j = k;j <= e;++j)
		if(seq[j] < seq[s]){
			flg = 1;
			break;
		}
	if(flg == 0){
	l->v = seq[s+1];
	r->v = seq[k];
	root->lchild = l;
	root->rchild = r;
	flg = built(l,s+1,k-1)&&built(r,k,e);
	}
	return flg;
	}
}
void postorder(node *root){
	cout << root->v << " ";
	postorder(root->lchild);
	postorder(root->rchild);

}
int main(void){
	int i,j;
	cin >> n;
	for(i = 0;i < n;++i)
		cin >> seq[i];
	if(built(root,0,n-1))
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
	}
	cout << root->v;
	postorder(root);
	system("pause");
	return 0;
}

