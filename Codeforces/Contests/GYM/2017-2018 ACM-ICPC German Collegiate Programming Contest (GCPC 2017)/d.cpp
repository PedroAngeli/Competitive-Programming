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

const int nax = 205;
vi adj[nax];
vi rev_adj[nax];
map <string,int> mp;
vi vis;

bool fact(int u,int dest){
  if(u == dest) return true;
  vis[u] = 1;
  bool ret = false;
  for(int v:adj[u])
    if(!vis[v])
      ret = (ret || fact(v,dest));
  return ret;
}

bool alt_fact(int u,int dest){
  if(u == dest) return true;
  vis[u] = 1;
  bool ret = false;
  for(int v:rev_adj[u])
    if(!vis[v])
      ret = (ret || alt_fact(v,dest));
   
  return ret;
}
int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  int idx = 0;
  for(int i=0;i<n;i++){
    string a, are, worse, than, b;
    cin >> a >> are >> worse >> than >> b;
    if(!mp.count(a)) mp[a] = idx++;
    if(!mp.count(b)) mp[b] = idx++;
    int u = mp[a];
    int v = mp[b];
    adj[u].pb(v);
    rev_adj[v].pb(u);
  }

  while(m--){
    vis.assign(200,0);
    string a, are, worse, than, b;
    cin >> a >> are >> worse >> than >> b;
    if(!mp.count(a)) mp[a] = idx++;
    if(!mp.count(b)) mp[b] = idx++;
    int u = mp[a];
    int v = mp[b];
    if(fact(u,v)){
      cout << "Fact" << endl;
      continue;
    } 
    vis.assign(200,0);
    if(alt_fact(u,v)) cout << "Alternative Fact" << endl;
    else cout << "Pants on Fire" << endl;
  }
  
  return 0;
}