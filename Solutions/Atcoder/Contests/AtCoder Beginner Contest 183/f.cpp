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

const int nax = 2e5 + 5;
map<int, int> classes[nax];
int parent[nax];
int set_size[nax];

  int find(int x){
    if(x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }
  void join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return;
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
    for(auto it:classes[x]) classes[y][it.first] += it.second;
  }

int main(){
  fastio;

  int n, q;
  cin >> n >> q;
  for(int i=1;i<=n;i++) parent[i] = i, set_size[i] = 1;

  for(int i=1;i<=n;i++){
    int c;
    cin >> c;
    classes[i][c] = 1;
  }

  while(q--){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1) join(a, b);
    else{
      int p = find(a);
      cout << classes[p][b] << endl;
    }
  }
  
  return 0;
}