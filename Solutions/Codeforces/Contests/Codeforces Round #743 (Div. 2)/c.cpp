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


int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <int> in_degree(n+1, 0);
    vector <vector <int>>adj(n+1, vector<int>(0));
    for(int i=1;i<=n;i++){
      cin >> in_degree[i];
      for(int j=0;j<in_degree[i];j++){
        int u;
        cin >> u;
        adj[u].push_back(i);
      }
    }
    vector <int> cnt(n+1, 0);
    int vis = 0;
    queue <int> q;
    for(int i=1;i<=n;i++)
      if(in_degree[i] == 0)
        q.push(i);

    while(!q.empty()){
      int u = q.front();
      q.pop();
      vis++;
      for(int v:adj[u]){
        if(u > v)
          cnt[v] = max(cnt[v], 1 + cnt[u]);
        else
          cnt[v] = max(cnt[v], cnt[u]);
        if(--in_degree[v] == 0)
          q.push(v);
      }
    }
    if(vis < n){
      cout << -1 << endl;
      continue;
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
      ans = max(ans, cnt[i]);
    cout << ans+1 << endl;  
  }
  
  return 0;
}