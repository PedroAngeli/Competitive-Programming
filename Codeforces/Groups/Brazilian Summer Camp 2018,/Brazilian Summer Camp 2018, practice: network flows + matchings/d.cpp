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

const int nax = 4005;
set <int> Z[2];
vi U;
vi adj[nax][2];
int matched[nax][2];
bool vis[nax][2];

void dfs(int u,int side){
    vis[u][side] = true;
    Z[side].insert(u);
    for(int v:adj[u][side]){
      if(side){
        if(matched[u][side] != v or vis[v][1-side]) continue;
        dfs(v, 1-side);
      }else{
        if(matched[u][side] == v or vis[v][1-side]) continue;
        dfs(v, 1-side);
      }
    }
}

int main(){
  fastio;

  int n, m;
  cin >> n >> m;
  
  for(int i=1;i<=n;i++){
    int k;
    cin >> k;
    while(k--){
      int v;
      cin >> v;
      adj[i][0].pb(v);
      adj[v][1].pb(i);
    }
  }

  int flow = 0;
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    if(x){
      flow++;
      matched[i][0] = x;
      matched[x][1] = i;
    }
    else U.pb(i);
  }

  for(int u:U){
    dfs(u, 0);
  }

  vi A, B;

  for(int i=1;i<=n;i++) if(Z[0].count(i) == 0) A.pb(i);
  for(int i=1;i<=m;i++) if(Z[1].count(i)) B.pb(i);
  
  assert(sz(A) + sz(B) == flow);

  cout << flow << endl;
  cout << sz(A);

  for(int u:A)
    cout << " " << u;
  cout << endl;

  cout << sz(B);

  for(int u:B)
    cout << " " << u;
  cout << endl;

  return 0;
}