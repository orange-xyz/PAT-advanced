#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	int a,b,num,i = 0;
	scanf("%d%d",&a,&b);
	num = a+b;
	char s[8];
	sprintf(s,"%d",num);
	int count = 0;
	char temp;
	while(s[i]!='\0'){
		count++;
		i++;
	}
	for(i = 0;i < count;i++){
		temp = s[i];
		s[i] = s[count-i-1];
		s[count-i-1] = temp;
		}
	for(i = 0;i <= count-1;i++){
		if(num >= 0){
			if(((count-i)%3==0)&&(i!=0))
			printf(",");
			printf("%c",s[i]);
		}
		else{
			printf("%c",s[i]);
			if(((count-i)%3==1)&&(i != count-1)&&(i!=0))
			printf(",");
		}
	}
	return 0;
} 
