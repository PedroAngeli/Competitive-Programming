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

const int nax = 50005;
vi adj[nax];
ll dp1[nax][505];
ll dp2[nax][505];
int n,k;

void solve(int u,int p){

  for(int v : adj[u]){
    if(v != p){
      solve(v,u);
      for(int i=1;i<=k;i++)
        dp2[u][i] += dp2[v][i-1];
    }
  }
}

void solve2(int u,int p){
   for(int i=1;i<=k;i++){
    if(p == 0)
      dp1[u][i] = dp2[u][i];
    else{
      if(i > 1)
        dp1[u][i] = dp2[u][i] + (dp1[p][i-1] - dp2[u][i-2]);
      else
        dp1[u][i] = dp2[u][i] + 1;
    }
  }
  for(int v : adj[u])
    if(v != p)
      solve2(v,u);
}

int main(){
  fastio;

  cin >> n >> k;

  for(int i=1;i<=n;i++)
    dp2[i][0] = 1;

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  solve(1,0);
  solve2(1,0);


  ll ans = 0;

  for(int i=1;i<=n;i++)
    ans += dp1[i][k];

  cout << ans/2 << endl;

  return 0;
}