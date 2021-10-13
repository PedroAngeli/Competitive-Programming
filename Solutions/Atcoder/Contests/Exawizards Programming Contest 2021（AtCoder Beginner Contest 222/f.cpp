#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

const int nax = 4e5 + 5;
const ll INF = 1e18;
int n;
vector <pair <int,int>> adj[nax];
int D[nax];

vector <ll> djikstra(int source){
  vector <ll> d(2*n+1, INF);
  d[source] = 0;
  priority_queue <pair <ll, int>, vector <pair<ll,int>>, greater<pair<ll,int>>> pq;
  pq.push({0, source});
  
  while(!pq.empty()){
    auto it = pq.top();
    int u = it.s;
    ll dist = it.f;
    pq.pop();
    if(dist > d[u])
      continue;      
    for(auto p:adj[u]){
      int v = p.f;
      int w = p.s;
      if(d[v] > d[u] + w){
        d[v] = d[u] + w;
        pq.push({d[v], v});
      }
    }
  }

  return d;
}

int farthest(int source){
  vector <ll> d = djikstra(source);
  int node = 0;
  ll mx = 0;
  for(int i=1;i<=2*n;i++){
    if(d[i] > mx){
        mx = d[i];
        node = i;
      }
  }
    
  return node;
}

pair <int,int> diameter(){
  int s = farthest(n+1);
  int t = farthest(s);
  return make_pair(s, t);
}

int main(){
  fastio;

  cin >> n;
  for(int i=0;i<n-1;i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for(int i=1;i<=n;i++)
    cin >> D[i];
  
  for(int i=1;i<=n;i++){
    int u = i;
    int v = i+n;
    int w = D[i];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  pair <int,int> st = diameter();
  int s = st.f;
  int t = st.s;

  vector <ll> ds = djikstra(s);
  vector <ll> dt = djikstra(t);

  for(int i=1;i<=n;i++){
    ll o1 = 0, o2 = 0;
    if(i+n != s)
      o1 = ds[i];
    if(i+n != t)
      o2 = dt[i];

    cout << max(o1, o2) << endl;

  }
  
  return 0;
}