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
vi centroids;
vi subtree_sz;
int n;

void dfs(int u,int p){
  subtree_sz[u] = 1;
  bool is_centroid = true;

  for(int v:adj[u]){
    if(v != p){
      dfs(v,u);
      subtree_sz[u] += subtree_sz[v];
      if(subtree_sz[v] > n/2)
        is_centroid = false;
    }
  }

  if ((n - subtree_sz[u]) > (n / 2)) 
    is_centroid = false;

  if (is_centroid) 
    centroids.pb(u);
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n;
    centroids.clear();
    subtree_sz.assign(n+1,0);
    for(int i=1;i<=n;i++)
      adj[i].clear();

    for(int i=0;i<n-1;i++){
      int u,v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    dfs(1,-1);
    if(sz(centroids) == 1){
      for(int i=0;i<2;i++)
        cout << 1 << " " << adj[1][0] << endl;
    }else{
      int c1 = centroids[0];
      int c2 = centroids[1];
      for(int v : adj[c1])
        if(v != c2){
          cout << c1 << " " << v << endl;
          cout << c2 << " " << v << endl;
          break;
        }
    }
  }


  return 0;
}