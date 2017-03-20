#include<stdio.h>
int main(void){
	int n,b,i = 0,j,k;
	int flag = 1;
	int num[100];
	scanf("%d %d",&n,&b);
	while(n != 0){
		num[i] = n%b;
		n /= b;
		i++;
	}
	for(k = 0; k < i; ++k){
		if(num[k] != num[i-1-k])
		flag = 0;
	}
	
	if(flag == 0)
	printf("No\n");
	else if(flag == 1)
	printf("Yes\n");
	
	for(j = i-1; j > 0; --j){
		printf("%d ",num[j]);
	}
	printf("%d\n",num[0]);
	return 0;
}
