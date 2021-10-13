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

map <int, vi> adj;
map <int,int> val;

bool solve(int u,int p=-1){
  int sum = 0;
  bool can = true;
  for(int v:adj[u])
    if(v != p){
      can = (can and solve(v, u));
      sum += val[v];
    }

  return (can and (sum < val[u]));
}

int main(){
  fastio;

  string line;
  while(getline(cin, line)){
    if(sz(line) == 0){
      cout << ":-) Matrioshka!" << endl;
      continue;
    } 
    stringstream ss(line);

    int n;
    stack <pii> S;
    adj.clear();
    val.clear();

    int root = 0;
    bool can = true;
    int node = 1;

    while(ss >> n){
      if(n < 0){
        S.push({node, -n});
        val[node] = -n;
        node++;
      } 
      else{
        int child;
        if(S.empty() or S.top().s != n){
          can = false;
          break;
        }
        else{
          child = S.top().f;
          S.pop();
        }

        if(S.empty()) root = child;
        else adj[S.top().f].pb(child);
      }
    }

    if(can and solve(root)) cout << ":-) Matrioshka!" << endl;
    else cout << ":-( Try again." << endl;
  }

  return 0;
}