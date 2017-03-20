#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node{
	int num;
	node *lchild;
	node *rchild;
	int index;
};
node *no = new node[100];
int order[100];
int k = 0;
void inorder(node *root){
	if(root->lchild != NULL)
		inorder(root->lchild);
	order[k++] = root->num;
	if(root->rchild != NULL)
		inorder(root->rchild);
}
void lorder(node *root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node *tmp = q.front();
		if(tmp == no)
		cout << tmp->index;
		else
			cout << " " << tmp->index;
		q.pop();
		if(tmp->lchild != NULL)
			q.push(tmp->lchild);
		if(tmp->rchild != NULL)
			q.push(tmp->rchild);
	}
}
int main(void){
	int n,i,j;
	cin >> n;
	int l,r;
	for(i = 0;i < n;++i){
		scanf("%d%d",&l,&r);
		no[i].num = i;
		if(l == -1)
			no[i].lchild = NULL;
		else
		no[i].lchild = no+l;
		if(r == -1)
			no[i].rchild = NULL;
		else
		no[i].rchild = no+r;
	}
	int seq[100];
	for(i = 0;i < n;++i){
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+n);
	inorder(no);
	for(i = 0;i < n;++i)
		no[order[i]].index = seq[i];
	lorder(no);
	system("pause");
	return 0;
}