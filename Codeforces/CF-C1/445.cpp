#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;

  int v[n];

  for(int i=0;i<n;i++)
    cin >> v[i];

  double ans = 0;

  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;

    ans = max(ans,(double)(v[a]+v[b])/c);
  }

  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}