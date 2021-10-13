#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 1e5 + 5;
vpii adj[nax];
vector <bool> isLeaf;
vll path;

void solve(int u,int p,ll sum){
  for(auto e : adj[u]){
    int v = e.f;
    ll w = e.s;

    if(v != p)
      isLeaf[u] = false,solve(v,u,sum + w);
  }

  if(isLeaf[u])
    path[u] = sum;
}

int main(){
  fastio;

  int n;
  cin >> n;
  ll sum = 0;
  isLeaf.assign(n+1,true);
  path.assign(n+1,0);

  for(int i=0;i<n-1;i++){
    int u,v,w;
    cin >> u >> v >> w;
    sum += w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }

  sum *= 2;

  solve(1,-1,0);

  ll ans = LLONG_MAX;

  for(int i=1;i<=n;i++){
    if(!isLeaf[i])
      continue;
    ans = min(ans,sum-path[i]);
  }


  cout << ans << endl;

  return 0;
}