#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 0,sum = 0,j = 0;
	char n[100];
	char sumc[100];
	int num[100],count = 0;
	scanf("%s",&n);
	
	while(n[i] != '\0'){
		num[i] = n[i]-'0';
		sum +=num[i];
		i++;
	}
/*	while(num != 0){
		sum += num%10;
		num = num/10;
	}
*/	
    sprintf(sumc,"%d",sum);
	while(sumc[j] != '\0'){
		count++;
		j++;
	}

	for(j = 0; j < count-1; ++j){
		switch(sumc[j]){
			case '1': printf("one ");break;
			case '2': printf("two ");break;
			case '3': printf("three ");break;
			case '4': printf("four ");break;
			case '5': printf("five ");break;
			case '6': printf("six ");break;
			case '7': printf("seven ");break;
			case '8': printf("eight ");break;
			case '9': printf("nine ");break;
			case '0': printf("zero ");break;
		}
	}
	switch(sumc[count-1]){
			case '1': printf("one");break;
			case '2': printf("two");break;
			case '3': printf("three");break;
			case '4': printf("four");break;
			case '5': printf("five");break;
			case '6': printf("six");break;
			case '7': printf("seven");break;
			case '8': printf("eight");break;
			case '9': printf("nine");break;
			case '0': printf("zero");break;
	}
	return 0;
} 
