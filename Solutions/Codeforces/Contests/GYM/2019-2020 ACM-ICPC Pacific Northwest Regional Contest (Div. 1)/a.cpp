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
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

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
int N;
vi t,subtree_size;
vll ans,tax,a,b;
vpii adj[nax];

void solve(int u,int p){
  tax[u] = t[u];
  for(auto el:adj[u]){
    int v = el.f;
    int w = el.s;
    if(p == v)
      continue;
    solve(v,u);
    subtree_size[u] += subtree_size[v];
    a[u] += a[v] + w*subtree_size[v];
    tax[u] += tax[v];
    b[u] += b[v] + w*tax[v];
  }
}

void solve2(int u,int p,int w=0){
  if(p != -1){
    a[u] = a[p] + w*(N - subtree_size[u]) - w*subtree_size[u];
    b[u] = b[p] + w*(tax[1] - tax[u]) - w*tax[u];
  }

  ans[u] = t[u]*a[u] + b[u];

  for(auto el:adj[u]){
    int v = el.f;
    int w = el.s;
    if(p == v)
      continue;
    solve2(v,u,w);
  }
}
int main(){
  fastio;

  cin >> N;
  t.resize(N+1);
  ans.resize(N+1);
  a.assign(N+1,0);
  b.assign(N+1,0);
  tax.assign(N+1,0);
  subtree_size.assign(N+1,1);
  
  for(int i=1;i<=N;i++)
    cin >> t[i];
  
  for(int i=0;i<N-1;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }

  solve(1,-1);
  solve2(1,-1);

  for(int i=1;i<=N;i++)
    cout << ans[i] << endl;
  return 0;
}