#include<stdio.h>
#include<malloc.h>
int *digi(long long n){
	int i = 0,j;
	int num[100];
	int *dig;
    dig = (int*)malloc(sizeof(int));
	for(j = 0; j < 10; ++j){
		dig[j] = 0;
	}
	while(n){
		num[i] = n%10;
		n /= 10;
		++i;
	}

	for(j = 0; j < i; ++j){
		dig[num[j]]++;
	}
	for(j = 0; j < 10; ++j)
//	printf("%d",dig[j]);
//	printf("\n");   
	return dig;
	free(dig);	
}


int main(void){
	long long n,m;
	int i,flg = 0;
	int *dig1,*dig2;
	scanf("%lld",&n);
	m = 2*n;
	dig1 = digi(n);
	dig2 = digi(m);
	for(i = 0; i < 10; i++){
//	printf("%d",dig1[i]);
//	printf("%d\n",dig2[i]);
		if(dig1[i] != dig2[i])
		flg = 1;
	}
	if(flg == 0)
	printf("Yes\n");
	else if(flg == 1)
	printf("No\n");
	
	printf("%lld",2*n);
	return 0;	
}
