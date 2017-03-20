//名次并列的问题没有解决？？？ 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct stud{
	int sid,c,m,e;
	double a;
};
struct check{
	int sid;
	int st[4];
};
bool cmp_e(stud x,stud y){
	return x.e > y.e;
}
bool cmp_m(stud x,stud y){
	return x.m > y.m;
}
bool cmp_c(stud x,stud y){
	return x.c > y.c;
}
bool cmp_a(stud x,stud y){
	return x.a > y.a;
}
int main(void){
	int n,m,i,j;
	cin >> n >> m;
	stud s[n];
	stud sa[n],sc[n],sm[n],se[n];
	check ck[m];
	for(i = 0;i < n;++i)
	cin >> s[i].sid >> s[i].c >> s[i].m >> s[i].e;
	for(i = 0;i < m;++i)
	cin >> ck[i].sid;
	for(i = 0;i < n;++i)
	s[i].a = (s[i].c+s[i].m+s[i].e)/3;
	for(i = 0;i < n;++i){
		sa[i] = s[i];
		sc[i] = s[i];
		sm[i] = s[i];
		se[i] = s[i];
	}
	stable_sort(sa,sa+n,cmp_e);
	stable_sort(sa,sa+n,cmp_m);
	stable_sort(sa,sa+n,cmp_c);
	stable_sort(sa,sa+n,cmp_a);
	
	stable_sort(sc,sc+n,cmp_e);
	stable_sort(sc,sc+n,cmp_m);
	stable_sort(sc,sc+n,cmp_a);
	stable_sort(sc,sc+n,cmp_c);
	
	stable_sort(sm,sm+n,cmp_e);
	stable_sort(sm,sm+n,cmp_c);
	stable_sort(sm,sm+n,cmp_a);
	stable_sort(sm,sm+n,cmp_m);
	
	stable_sort(se,se+n,cmp_m);
	stable_sort(se,se+n,cmp_c);
	stable_sort(se,se+n,cmp_a);
	stable_sort(se,se+n,cmp_e);
	
	int k,key = 0,mi,flg;
	for(i = 0;i < m;++i){
		flg = 0;
		for(j = 0;j < n;++j){
			if(ck[i].sid == sa[j].sid){
				ck[i].st[0] = j+1; flg = 1;	
			}
			if(ck[i].sid == sc[j].sid){
				ck[i].st[1] = j+1; 
			}
			
			if(ck[i].sid == sm[j].sid){
				ck[i].st[2] = j+1;	
			}
			
			if(ck[i].sid == se[j].sid){
				ck[i].st[3] = j+1;	
			}
			
		}	
		if(flg == 0)
		cout << "N/A" << endl;
		else{
		mi = ck[i].st[key];
		for(k = 0;k < 4;++k){
			if(ck[i].st[k] < mi){
				mi = ck[i].st[k];
				key = k;
			}
		}
		cout << mi << " ";
		if(key == 0) cout << "A" << endl;
		else if(key == 1) cout << "C" << endl;
		else if(key == 2) cout << "M" << endl;
		else if(key == 3) cout << "E" << endl;	
		}
		
	}
return 0;	
}
