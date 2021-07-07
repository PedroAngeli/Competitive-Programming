#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
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

const int nax = 2e5 + 5;
int n;
vi adj[nax];
int h[nax];
int d[nax];

void dfs(int u,int p=-1){
  multiset <int, greater <int> > S;

  for(int v:adj[u])
    if(v != p){
      dfs(v, u);
      d[u] = max(d[u], d[v]);
      h[u] = max(h[u], 1 + h[v]);
      S.insert(h[v]);
    }
  
  d[u]= max(d[u], h[u]);

  int h1, h2;
  if(sz(S) >= 2){
    h1 = *(S.begin());
    S.erase(S.begin());
    h2 = *(S.begin());
    d[u] = max(d[u], h1 + h2 + 2);
  }
}

int main(){
  fastio;

  cin >> n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1);

  cout << d[1] << endl;

  return 0;
}