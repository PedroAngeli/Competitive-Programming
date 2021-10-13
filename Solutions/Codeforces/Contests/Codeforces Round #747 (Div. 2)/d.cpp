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

#define IMPOSTER 0
#define CREWMATE 1

int n, m;
vector <vector <pair <int,int>>> adj;
vector <int> role;
bool ok;
vector <int> color;

void bfs(int source){
  queue <int> q;
  q.push(source);
  role[source] = 0;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    color[role[u]]++;
    for(auto p:adj[u]){
      int v = p.f;
      int w = p.s;
      if(role[v] == -1){
        if(w == IMPOSTER)
          role[v] = 1-role[u];
        else
          role[v] = role[u];
        q.push(v);
      }else{
        if(w == IMPOSTER and role[v] != 1-role[u])
          ok = false;
        if(w == CREWMATE and role[v] != role[u])
          ok = false;
      }
    }
  }
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    adj.assign(n+1, vector<pair<int,int>>());
    role.assign(n+1, -1);
    ok = true;

    for(int i=0;i<m;i++){
      int u, v;
      string s;
      cin >> u >> v >>s;
      int w;
      if(s == "imposter")
        w = IMPOSTER;
      else
        w = CREWMATE;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    int ans = 0;
    for(int u=1;u<=n;u++){
      if(role[u] == -1){
        color.assign(2, 0);
        bfs(u);
        ans += max(color[0], color[1]);
      }
    }

    if(!ok){
      cout << -1 << endl;
      continue;
    }

    cout << ans << endl;
  }
  
  return 0;
} 
