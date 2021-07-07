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


map <ll, set <ll> > adj;
map <int, vi> colLineBlack;
map <int, vi> colLineValid;
map <int, bool> isBlack;
int n, m;


ll mapIdx(ll i, ll j){
  return i*n + j;
}

int main(){
  fastio;

  cin >> n >> m;
  ll x[m], y[m];

  for(int i=0;i<m;i++){
    cin >> x[i] >> y[i];
    colLineBlack[y[i]].pb(x[i]);
  }

  for(int i=0;i<m;i++){
    ll idx = mapIdx(x[i], y[i]);
    isBlack[idx] = true;
    colLineBlack[y[i]].pb(0);
    sort(all(colLineBlack[y[i]]));

    int nextPos = lb(all(colLineBlack[y[i]]), x[i]) - colLineBlack[y[i]].begin() - 1;
    int nextLine = colLineBlack[y[i]][nextPos];

    ll nextIdx = mapIdx(nextLine, y[i]);

    adj[nextIdx].insert(idx);
  
    if(y[i]-1 > 0){
      ll idx_right = mapIdx(x[i]-1, y[i]-1);
      colLineValid[y[i] - 1].pb(x[i]-1);
      adj[idx_right].insert(idx);
    }

    if(y[i]+1 <= 2*n){
      ll idx_left = mapIdx(x[i]-1, y[i]+1);
      colLineValid[y[i]+1].pb(x[i]-1);
      adj[idx_left].pb(idx);
    }
  }

  
  
  
  return 0;
}