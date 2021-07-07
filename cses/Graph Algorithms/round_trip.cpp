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
vi adj[nax];
int n,m;
bool in_cycle[nax];
bool vis[nax];

void findCycle(int u,int p){
  vis[u] = true;

  for(int v : adj[u]){
    if(!vis[v])
      findCycle(v,u);
    else if(v != p)
      in_cycle[u] = true;
  }
}

bool solve(int ini,int u,int p,vi& path){
  vis[u] = true;
  path.pb(u);

  for(int v : adj[u]){
    if(!vis[v]){
      bool ret = solve(ini,v,u,path);
      if(ret)
        return true;
    }
    else if(v != p && v == ini){
      path.pb(ini);
      cout << sz(path) << endl;
      for(int x : path)
        cout << x << " ";
      cout << endl;
      return true;
    }
  }

  path.pop_back();
  return false;
}
int main(){
  fastio;
  
  cin >> n >> m;

  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  for(int i=1;i<=n;i++)
    if(!vis[i])
    findCycle(i,-1);

  int u = -1;

  for(int i=1;i<=n;i++)
    if(in_cycle[i])
      u = i;

  if(u == -1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  memset(vis,false,sizeof vis);
  vi path;
  solve(u,u,-1,path);
  return 0;
}