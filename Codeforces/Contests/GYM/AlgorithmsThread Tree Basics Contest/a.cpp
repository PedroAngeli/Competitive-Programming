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

const int nax = 3e5 + 5;
vi adj[nax];
vi dist;
int n;

int bfs(int root){
  dist.assign(n+1, nax);
  dist[root] = 0;
  queue <int> q;
  q.push(root);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:adj[u])
      if(dist[v] > dist[u] + 1){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  }

  int mx = 0, mx_node = 1;

  for(int i=1;i<=n;i++)
    if(dist[i] > mx){
      mx = dist[i];
      mx_node = i;
    }

  return mx_node;
}

int diameter(){
  return dist[bfs(bfs(1))];
}
int main(){
  fastio;

  cin >> n;
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int d = diameter();

  cout << 3*d << endl;

  return 0;
}