#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

char change(char c){
  if(c >= 'a' && c <='z')
    return c - 'a' + 'A';

  return c-'A' + 'a';
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  string t;
  cin >> t;

  int n = s.size();

  multiset <char> ms;

  for(int i=0;i<n;i++)
    ms.insert(s[i]);

  int m = t.size();

  int y = 0;
  int w = 0;

  for(int i=0;i<m;i++){
    char cur = t[i];
    auto it = ms.find(cur);
    if(it != ms.end()){
      y++;
      ms.erase(it);
      t[i] = 0;
    }
  }

  for(int i=0;i<m;i++){
    char cur = t[i];
    if(!cur)
      continue;
    cur = change(cur);
    auto it = ms.find(cur);
    if(it != ms.end()){
      w++;
      ms.erase(it);
    }
  }
  

  cout << y << " " << w << endl;
  
  

  return 0;
}