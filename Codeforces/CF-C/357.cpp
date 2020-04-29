#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;

  cin >> n >> m;

  set <int> s;

  int ans[n+1];
  memset(ans,-1,sizeof ans);

  for(int i=1;i<=n;i++)
    s.insert(i);


  while(m--){
    int l,r,x;
    cin >> l >> r >> x;

    auto it1 = s.lower_bound(l);
    auto it2 = s.lower_bound(r);

    if(it2 != s.end() && *it2 <= r)
    it2++;

    auto temp = it1;

    while(temp != it2){
      int cur = *temp;
      if(cur != x)
        ans[cur] = x;
      
      temp++;
    }
    
    s.erase(it1,it2);

    if(m == 0)
      ans[x] = 0;
      
    s.insert(x);
  }

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";

  cout << endl;


  return 0;
}