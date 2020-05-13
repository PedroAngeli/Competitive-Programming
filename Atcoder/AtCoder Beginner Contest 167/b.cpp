#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int a,b,c,k;

  cin >> a >> b >> c >> k;

  int ans;
 
  ans = min(a,k);
  k -= min(a,k);

  if(k){
    k -= min(b,k);
  }

  if(k){
    ans -= min(k,c);
  }

  cout << ans << endl;

  return 0;
}