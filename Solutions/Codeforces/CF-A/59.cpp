#include <bits/stdc++.h>

using namespace std;

char minu(char c){
  if(c >='A' && c <='Z')
    return c-'A' + 'a';

  return c;
}

char maiu(char c){
  if(c >='a' && c <='z')
    return c-'a' + 'A';

  return c;
}

int main(){

 string s;
 cin >> s;

 int ma = 0, mi =0 ;

 for(int i=0;i<s.size();i++){
   if(s[i] >='a' && s[i] <='z')
    mi++;
  else
    ma++;
 }
  

  if(mi >= ma){
     for(int i=0;i<s.size();i++)
      cout << minu(s[i]);
      cout << endl;
  }else{
    for(int i=0;i<s.size();i++)
      cout << maiu(s[i]);
      cout << endl;
  }


  return 0;
}