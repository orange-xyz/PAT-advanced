#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,i,j;
	int max,start,end,sum = 0;
	cin >> n;
	int seq[n];
	for(i = 0;i < n;++i)
	cin >> seq[i];
	max = -1; start = 1; end = n;
	for(i = 0;i < n;++i){
		for(j = i;j < n;++j){
			sum += seq[j];
			if(sum > max){
				max = sum;
				start = i;
				end = j;
			}
		}
		sum = 0;
	}
	if(max < 0)	printf("0 %d %d",seq[0],seq[n-1]);
	else
	printf("%d %d %d",max,seq[start],seq[end]);
	return 0;
	}
