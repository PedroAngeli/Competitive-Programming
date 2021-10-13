#include <bits/stdc++.h>

using namespace std;

int main(){

  string s;

  cin >> s;
  
  int ans = 0;
  int at = 0;

  for(int i=0;i<s.size();i++){
    int j=at;
    int c1 = 0;

    while(j != s[i]-'a'){
      j = (j+1)%26;
      c1++;
    }

    j = at;
    int c2 = 0;
    while(j != s[i]-'a'){
      j = ((j-1)%26 + 26)%26;
      c2++;
    }

    ans += min(c1,c2);

    at = s[i] - 'a';
  }

  cout << ans << endl;

  return 0;
}