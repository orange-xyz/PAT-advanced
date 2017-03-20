#include<iostream>
using namespace std;
int main(void){
	int m,n,i,j,k;
	cin >> n >> m;
	int pixel[m][n];
	int count[m*n][2];
	int num = 0;
	int domin = 0;
	for(i = 0;i < m*n;++i){
		count[i][1] = 0;
		count[i][0] = -1;
	}
	for(i = 0;i < m;++i)
		for(j = 0;j < n;++j){
			cin >> pixel[i][j];
		}
		
	for(i = 0;i < m;++i)
		for(j = 0;j < n;++j){
		for(k = 0;k < m*n;++k){
			if(pixel[i][j] == count[k][0])
			count[k][1]++;
			else {
			count[num][0] = pixel[i][j];	
			num++;
			}
		}
		}
	for(i = 0;i < num;++i){
		if(count[i][1] > count[domin][1])
		domin = i;
	}
	cout << count[domin][0] << endl;
	return 0;
}
