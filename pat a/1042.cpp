#include<iostream>
#include<string>
using namespace std;
int main(void){
	int k,i,j;
	int shu[54];
	string deck[54] = {
		"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
		"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
		"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
		"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
		"J1","J2"
	};
	cin >> k;
	for(i = 0;i < 54;++i){
		cin >> shu[i];
	}
	for(j = 0;j < k;++j)
	for(i = 0;i < 54;++i){
		deck[i] = deck[shu[i]];
	}
	for(i = 0;i < 53;++i){
		cout << deck[i] << ' ';
	}
	cout << deck[53];
	return 0;
}
