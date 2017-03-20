#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;
typedef struct node{
	int index;
	node* lchild;
	node* rchild;
	node* father;
}*tree;
int preorder(node *root){
	return 0;
}
int main(void){
	int n,pcnt = 0,i;
	cin >> n;
	node *root = new node;
	stack<node*>s;
	string tmp;
	int tmp1;
	stringstream ss;
	cin >> tmp;
	ss << tmp;
	ss >> tmp1;
	root->index = tmp1;
/*	root->father = NULL;
	s.push(root);
	for(i = 1;i < 2*n;++i){
		scanf("%s",tmp);
		if(tmp[1] == 'u'){
			node *tmpn = new node;
			tmpn->index = atoi(tmp);
			if(pcnt == 0){
				root->lchild = tmpn;
				tmpn->father = root;
				s.push(tmpn);
				root = tmpn;
			}
			else{
			for(i = 0;i < pcnt-1;++i){
				s.pop();
			}
			root = s.top();
			root->rchild = tmpn;
			tmpn->father = root;
			s.pop();
			s.push(tmpn);
			}
			pcnt = 0;
		}
		else if(tmp == "Pop")
			pcnt ++;
	}
	while(root->father != NULL)
		root = root->father;
	preorder(root);
	*/
	cout << root->index;
	system("pause");
	return 0;
}
