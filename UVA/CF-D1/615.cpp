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

int vis;
map <int,vi> adj;
map <int,int> in_degree;

void solve(int u,int p){
  vis++;
  for(int v : adj[u])
    if(v != p)
      solve(v,u);
}

int main(){
  fastio;

  int u,v;
  int ncase = 1;

  while(true){
    in_degree.clear();
    adj.clear();

    set <int> S;
    while(cin >> u >> v && u && v){
      if(u < 0 && v < 0)
        return 0;
      in_degree[v]++;
      S.insert(u);
      S.insert(v);
      adj[u].pb(v);
    }

    cout << "Case " << ncase++;

    if(sz(S) == 0){
      cout << " is a tree." << endl;
      continue;
    }

    int root = -1;
    int c1 = 0;
    bool can = true;

    for(int i : S){
      if(in_degree[i] == 0){
        root = i;
        c1++;
      }else if(in_degree[i] > 1)
        can = false;
    }
       
    if(c1 != 1 || !can){
      cout << " is not a tree." << endl;
      continue;
    }

    vis = 0;
    solve(root, -1);

    if(vis == sz(S)) cout << " is a tree." << endl;
    else cout << " is not a tree." << endl;
  }
  
  return 0;
}