#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int a,b,c;
  cin >> a >> b >> c;
  int l = min({a,b,c});
  int r = max({a,b,c});
  int ans = INT_MAX;

  for(int i=l;i<=r;i++){
    ans = min(ans,abs(a-i)+abs(b-i)+abs(c-i));
  }

  cout << ans << endl;
    
  return 0;
}