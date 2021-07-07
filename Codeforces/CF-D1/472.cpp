#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
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

vi parent;
vpii adj[2000];
vector <vi> dist;

bool solve(int u,int source,int p,ll total_w){

  if(dist[u][source] != total_w)
    return false;

  bool ret = true;

  for(auto el:adj[u]){
    int v = el.f;
    ll w = el.s;
    if(v == p)
      continue;
    ret = (ret && solve(v,source,u,w + total_w));
  }

  return ret;
}

int find(int x){
  if(x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

bool join(int x,int y){
  x = find(x);
  y = find(y);
  if(x != y){
    parent[x] = y;
    return true;
  }
  return false;
}
int main(){
  fastio;

  int n;
  cin >> n;
  
  dist.assign(n,vi(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> dist[i][j];
  
  vector <pair <int,pii> > edges;
  bool can = true;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(i == j && dist[i][j] > 0)
        can = false;
      else if(i < j && (dist[i][j] != dist[j][i] || dist[i][j] == 0))
        can = false;
      else if(i < j)
        edges.pb({dist[i][j],{i,j}});
    }

  if(!can){
    cout << "NO" << endl;
    return 0;
  }

  parent.resize(n);
  iota(all(parent),0);
  sort(all(edges));

  int e = 0;

  for(int i=0;i<sz(edges);i++){
    int u = edges[i].s.f;
    int v = edges[i].s.s;
    int w = edges[i].f;

    if(join(u,v)){
      e++;
      adj[u].pb({v,w});
      adj[v].pb({u,w});
    }
    if(e == n-1)
      break;
  }
  
  for(int i=0;i<n;i++){
    if(!solve(i,i,-1,0))
      can = false;
  }

  if(can)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;



  return 0;
}