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


int main(){
  fastio;

  int n,m;
  cin >> n >> m;
  
  vector <vi> dist(n+5);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    dist[x].pb(i);
  }

  vpii ans;
  vector <vi> used(n,vi(n,0));

  for(int i=1;i<=n-1;i++){
    for(int el:dist[i]){
      ans.pb({dist[i-1].back(),el}),m--;
      used[dist[i-1].back()][el] = 1;
      used[el][dist[i-1].back()] = 1;
    }
  }
  int d = 1;
  while(m){
    vi tmp = dist[d];
    for(int i=0;i<sz(tmp) && m;i++)
      for(int j=0;j<sz(tmp) && m;j++){
        int u = tmp[i];
        int v = tmp[j];
        if(u == v)
          continue;
        if(!used[u][v]){
          ans.pb({u,v});
          used[u][v] = 1;
          used[v][u] = 1;
          m--;
        }
      }
    vi tmp2 = dist[d+1];
    for(int i=0;i<sz(tmp) && m;i++)
      for(int j=0;j<sz(tmp2) && m;j++){
        int u = tmp[i];
        int v = tmp2[j];
        if(u == v)
          continue;
        if(!used[u][v]){
          ans.pb({u,v});
          used[u][v] = 1;
          used[v][u] = 1;
          m--;
        }
      }
      d++;
  }

  for(auto p:ans)
    cout << p.f+1 << " " << p.s+1 << endl;

  
  return 0;
}