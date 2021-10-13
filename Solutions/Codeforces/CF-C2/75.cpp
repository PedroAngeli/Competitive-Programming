#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

set <int> solve(long long x){
  set <int> div;
  for(long long i = 1;i*i<=x;i++){
    if(x % i == 0)
      div.insert(i),div.insert(x/i);
  }
  return div;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long a,b;
  int n;
  cin >> a >> b >> n;

  set <int> diva = solve(a);
  set <int> divb = solve(b);
  set <int> common;
  for(auto it = diva.begin();it!=diva.end();it++){
    int cur = *it;
    if(b % cur == 0)
      common.insert(cur);
  }

    for(auto it = divb.begin();it!=divb.end();it++){
    int cur = *it;
    if(a % cur == 0)
      common.insert(cur);
  }

  while(n--){
    int l,r;
    cin >> l >> r;
    int ans = -1;
    for(auto it=common.begin();it!=common.end();it++){
      int cur = *it;
      if(cur >= l && cur <= r)
        ans = max(cur,ans);
    }

    cout << ans << endl;
  }
 
  return 0;
}