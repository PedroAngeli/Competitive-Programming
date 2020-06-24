#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    int n;
    string s;
    cin >> n >> s;
    int z = 0;
    string ans = "";

    while(z < n && s[z] == '0')
      z++;
    
    int o = n-1;
    while(o>=0 && s[o] == '1')
      o--;

    // cout << z << " " << o << endl;

    for(int i=0;i<z;i++)
      ans += '0';
    if(z < o)
      ans += '0';
    for(int i=0;i<n-o-1;i++)
      ans+='1';

    cout << ans << endl;

  }
  

  return 0;
}