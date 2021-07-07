#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;

  int h[n+1];

  for(int i=1;i<=n;i++)
    cin >> h[i];

  bool good[n+1];

  for(int i=1;i<=n;i++)
    good[i] = true;

  while(m--){
    int a,b;
    cin >> a >> b;
    if(h[a] > h[b])
      good[b] = false;
    else if(h[b] > h[a])
      good[a] = false;  
    else
      good[a] = good[b] = false;
  }

  int ans = 0;

  for(int i=1;i<=n;i++)
    if(good[i])
      ans++;

  cout << ans << endl;

  return 0;
}