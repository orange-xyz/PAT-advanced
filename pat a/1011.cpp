#include<stdio.h>
int main(void){
	double odd[3][3];
	double temp[3];
	int key;
	int i,j;
	double sum = 1.0;
	for(i = 0; i < 3; ++i)
		for(j = 0; j < 3; ++j){
		    scanf("%lf",&odd[i][j]);
		}
		
	for(i = 0; i < 3; ++i){
		if(odd[i][0] > odd[i][1]){
		temp[i] = odd[i][0]; key = 0;	
		}
		else {
		temp[i] = odd[i][1]; key = 1;
		}
		if(temp[i] < odd[i][2])	{
			key = 2; temp[i] = odd[i][2];
		};
		switch(key){
			case 0:printf("W ");break;
			case 1:printf("T ");break;
			case 2:printf("L ");break;
		}
		sum *= temp[i];
		
	}
	sum = 2*(sum*0.65-1)
	printf("%.2f\n",sum);
	
}
