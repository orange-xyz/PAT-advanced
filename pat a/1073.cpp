
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(void){
  string s;
  string ex;
  int i,e,exp;
  cin >> s;
  for(i = 0;i < s.size();++i){
    if(s[i] == 'E'){
      e = i;
      break;
    }
  }
  for(i = e+2;i < s.size();++i){
    ex += s[i];
  }
  exp = atoi(ex.c_str());
  if(s[0] == '-')
  cout << "-";
  
  if(s[e+1] == '-'){
  cout << "0.";
  for(i = 0;i < exp-1;++i)
  cout << "0";
  cout << s[1];
  for(i = 3;i < e;++i)
  cout << s[i];    
  }
  
  else{
  if(exp >= (e-3)){
  cout << s[1];
  for(i = 3;i < e;++i)
  cout << s[i];
  for(i = e-3;i < exp;++i)
  cout << "0";
  }
  else{
    cout << s[1];
    for(i = 3;i < exp+3;++i)
    cout << s[i];
    cout << ".";
    for(i = exp+3;i < e;++i)
    cout <<s[i];
  }  
  }

  return 0;
}


