#include <bits/stdc++.h>

using namespace std;


char minu(char c){
  if(c >= 'A' && c <='Z')
    c = c-'A' + 'a';

  return c;
}
int main(){

  string s1,s2;

  cin >> s1 >> s2;


  for(int i=0;i<s1.size();i++)
    s1[i] = minu(s1[i]);

   for(int i=0;i<s2.size();i++)
    s2[i] = minu(s2[i]);

  if(s1 == s2)
    cout << "0\n";
  else if(s1 < s2)
    cout << "-1\n";
  else
    cout << "1\n";
 


  return 0;
}