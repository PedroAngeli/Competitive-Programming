#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

struct comp{
  bool operator() (pll p1, pll p2){
    return ((p1.f*p1.s) - ((p1.f/2)*p1.s)) >= ((p2.f*p2.s) - ((p2.f/2)*p2.s));
  }
};

const int nax = 1e5 + 5;
vpll adj[nax];
multiset <pll,comp> myset;
vi leafs;
vector <pair <ii,ll> > edges;

int solve(int u, int p){
  bool isLeaf = true;

  for(auto pr:adj[u]){
    int v = pr.first;
    if(v != p)
      leafs[u] += solve(v,u), isLeaf = false;
  }

  if(isLeaf)
    leafs[u] = 1;

  return leafs[u];
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;
  while(t--){
    ll n, S;
    cin >> n >> S;

    for(int i=1;i<=n;i++)
      adj[i].clear();
    myset.clear();
    edges.clear();
    leafs.assign(n+1,0);

    for(int i=0;i<n-1;i++){
      ll u,v,w;
      cin >> u >> v >> w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
      edges.push_back({{u,v},w});
    }

    solve(1,0);
    ll total = 0;

    for(auto e:edges){
      ll times = min(leafs[e.f.f],leafs[e.f.s]);
      total += times*e.s;
      myset.insert({e.s,times});
    }

    int ans = 0;
    
    while(total > S){
      auto it = myset.begin();
      myset.erase(it);
      ll cnt = it->s;
      ll val = it->f;
      ll newVal = val/2;
      newVal *= cnt;
      ll mult = cnt*val;
      total -= mult;
      total += newVal;
      ans++;
      myset.insert({val/2,cnt});
    }

    cout << ans << endl;
  }

  return 0;
}