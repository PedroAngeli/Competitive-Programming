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

int n, k;

bool touch(int p1, int p2){
  if(p1 > p2) swap(p1, p2);
  return p1 + k > p2;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n >> k;
    vi h(n);
    vi idx(n);
    for(int i=0;i<n;i++){
      cin >> h[i];
      idx[i] = i;
    }
    sort(all(idx),[&](int i,int j){
      return h[i] > h[j];
    }); 

    vi pos(n, -1);
    pos[0] = h[0];
    pos[n-1] = h[n-1];

    bool can = true;
    for(int x:idx){
      if(x == 0 or x == n-1) continue;
      if(pos[x-1] == -1 and pos[x+1] == -1) pos[x] = h[x];
      else if(pos[x-1] == -1 and pos[x+1] != -1) pos[x] = max({0, pos[x+1]+1-k, h[x]});
      else if(pos[x-1] != -1 and pos[x+1] == -1) pos[x] = max({0, pos[x-1]+1-k, h[x]});
      else pos[x] = max({0, pos[x+1]+1-k, pos[x-1]+1-k, h[x]});
    }

    for(int i=0;i<n;i++){
      // debug(pos[i]);
      if(pos[i] > h[i] + k - 1) can = false;
      if(i < n-1 and !touch(pos[i], pos[i+1])) can = false;
      if(i > 0 and !touch(pos[i], pos[i-1])) can = false;
    }

    cout << (can ? "YES" : "NO") << endl;
  }
  
  return 0;
}