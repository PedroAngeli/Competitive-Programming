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

vector <vector <int>> adj;
vector <int> XOR;
int n, k;
vector <int> a;
vector <int> parent;
int target;
int chosen;

int dfs(int u, int p = -1){
  XOR[u] = a[u];
  for(int v:adj[u]){
    if(v == p or v == chosen) continue;
    int ret = dfs(v, u);
    if(ret != -1)
      return ret;
    XOR[u] = XOR[u] ^ XOR[v]; 
  }
  if(XOR[u] == target) return u;
  return -1;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n >> k;
    
    a.resize(n+1);
    parent.resize(n+1);
    adj.assign(n+1, vector <int>());
    XOR.assign(n+1, 0);
    target = 0;
    chosen = -1;

    for(int i=1;i<=n;i++)
      cin >> a[i], target ^= a[i];
    
    for(int i=0;i<n-1;i++){
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    if(target == 0){
      cout << "YES" << endl;
    }else if(k == 2){
      cout << "NO" << endl;
    }else{
      bool can = true;
      for(int i=0;i<2;i++){
        chosen = dfs(1);
        if(chosen <= 1){
          cout << "NO" << endl;
          can = false;
          break;
        }
      }
      if(can)
        cout << "YES" << endl;
    } 

  }
  return 0;
}