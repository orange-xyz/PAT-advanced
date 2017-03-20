#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int seq[100];
int seq1[100];
void heap(int r){
	int i,j;
	int tmp = seq1[0];
	int key = 1;
	while(key < r){
		seq1[key-1] = seq1[key] >= seq1[key+1]?seq1[key]:seq1[key+1];
		key = 
		
	seq1[r] = tmp;
}
int main(void){
	int n,i,j;
	cin >> n;
	for(i = 0;i < n;++i){
		scanf("%d",&seq[i]);
	}
	for(i = 0;i < n;++i){
		scanf("%d",&seq1[i]);
	}
	int k;
	for(i = 0;i < n;++i){
		if(seq1[i+1] < seq1[i]){
			k = i;
			break;
		}
	}
	int flg = 0;
	for(i = k+1;i < n;++i){
		if(seq[i] != seq1[i]){
			flg = 1;
			break;
		}
	}
	if(flg == 0){
		for(i = 0;i < k+1;++i)
			if(seq1[i] <= seq1[k+1]&&seq1[i+1] > seq1[k+1]){
				int tmp = seq[k+1];
				for(j = k+1;j >= i+2;--j)
					seq1[j] = seq1[j-1];
				seq1[i+1] = tmp;
			}
		printf("Insertion Sort\n");
		for(i = 0;i < n-1;++i){
			printf("%d ",seq1[i]);
		}
		printf("%d",seq1[n-1]);
	}
	else if(flg == 1){
		int r;
		for(i = n-1;i >= 0;--i)
			if(seq1[i] < seq[0]){
				r = i;
				break;
			}

	system("pause");
	return 0;
}
