#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isSequence(string t,string s){
  int n = s.size();
  int m = t.size();

  int i = 0, j = 0;

  while(i < n && j < m){
    if(s[i] == t[j])
      i++,j++;
    else
      i++;
  }

  return j == m;
}

int main(){

  int t;
  cin >> t;

  while(t--){
    string text;
    cin >> text;

    int kmax = 2*text.size()-1;
    string s;

    for(int k=1;k<=kmax;k++){
      s.assign(2*text.size(),'0');

      for(int i=0;i<s.size();i+=k)
        s[i] = '1';

      if(isSequence(text,s)){
        break;
      }

       s.assign(2*text.size(),'1');

      for(int i=0;i<s.size();i+=k)
        s[i] = '0';

      if(isSequence(text,s)){
        break;
      }
  }

  cout << s << endl;

}
  return 0;
}