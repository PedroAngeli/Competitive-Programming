#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m,T;
const int INF = 1e9 + 7;
vector <vector <pair<int,int> > > adj;
vector <vector <int> > dp;
vector <vector <int> > parent;
vector <bool> visit;

void solve(int u){
  if(visit[u])
    return;

  visit[u] = true;

  for(auto p:adj[u]){
    int v = p.first;
    int t = p.second;
    solve(v);
    for(int i=1;i<=n;i++){
      if(dp[u][i] > dp[v][i-1]+t){
        dp[u][i] = dp[v][i-1]+t;
        parent[u][i] = v;
      }
    }
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m >> T;

  adj.resize(n+1);
  dp.assign(n+1,vector <int>(n+1,INF));
  parent.assign(n+1,vector <int>(n+1));
  visit.assign(n+1,false);

  for(int i=0;i<m;i++){
    int u,v,t;
    cin >> u >> v >> t;
    adj[u].push_back({v,t});
  }

  dp[n][0] = 0;

  solve(1);
  int ans = 0;

  for(int i=1;i<=n;i++)
    if(dp[1][i] <= T)
      ans = i;

  cout << ans+1 << endl;
  
  int u = 1;

  while(u != n){
    cout << u << " ";
    u = parent[u][ans];
    ans--;
  }

  cout << n << endl;
  

  return 0;
}