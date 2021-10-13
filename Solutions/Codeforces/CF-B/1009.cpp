#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  bool trade = true;
  int n = s.size();
  int cnt = 0;

  for(int i=0;i<n;i++)
    if(s[i] == '1')
      cnt++;
  
  bool printed = false;

  for(int i=0;i<n;i++){
    if(s[i] != '1'){
      if(s[i] == '2' && !printed){
         while(cnt--)
          cout << "1";
        printed = true;
        cout << s[i];
      }else
        cout << s[i];
    }
  }

  if(cnt > 0)
  while(cnt--)
    cout << "1";

  cout << endl;

  
  return 0;
}