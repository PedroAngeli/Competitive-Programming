#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

ll n;
const int nax = 1e5 + 5;
vi adj[nax];
vll subTreeSize;
map <pii,ll> cnt;
const int mod = 1e9 + 7;

void dfs(int u,int p){
  subTreeSize[u] = 1;
  for(int v:adj[u]){
    if(v != p){
      dfs(v,u);
      subTreeSize[u] += subTreeSize[v];
    }
  }
  if(p != -1)
    cnt[{p,u}] = (n - subTreeSize[u])*subTreeSize[u];
}
int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=1;i<=n;i++)
      adj[i].clear();
    subTreeSize.assign(n+1,0);
    cnt.clear();

    for(int i=0;i<n-1;i++){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int m;
    cin >> m;

    vll p(m);
    for(int i=0;i<m;i++)
      cin >> p[i];
    
    dfs(1,-1);
    vll edges;
    
    for(auto el:cnt){
      edges.push_back(el.s);
    }
    sort(edges.begin(),edges.end());
    reverse(edges.begin(),edges.end());
    sort(p.begin(),p.end());

    while(edges.size() < p.size()){
      ll l1 = p.back();
      p.pop_back();
      ll l2 = p.back();
      p.pop_back();
      p.push_back((l1*l2)%mod);
    }

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    
    ll ans = 0;

    int i = 0,j = 0;

    while(i < edges.size() && j < m){
      ans += (edges[i]*p[j]);
      ans %= mod;
      i++;
      j++;
    }

    while(i < edges.size()){
      ans += edges[i];
      ans %= mod;
      i++;
    }

    if(ans < 0)
      ans += mod;
    cout << ans << endl;
  }
  
  return 0;
}