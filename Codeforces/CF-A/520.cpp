#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string s;

  cin >> s;
  set <char> letters;

  for(int i=0;i<n;i++){
    if(s[i] >= 'A' && s[i] <='Z')
      letters.insert(s[i]-'A' + 'a');
    else 
      letters.insert(s[i]);
  }

  if(letters.size() == 26)
    cout << "YES\n";
  else
    cout << "NO\n";
  
  return 0;
}