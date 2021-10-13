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

int grid[500][500];
int row[500];
int n, m, q;

int calc(int i){
  int mx = 0;
  int j = 0;
  while(j < m){
    int cnt = 0;
    while(j < m and grid[i][j]) j++, cnt++;
    mx = max(mx, cnt);
    while(j < m and !grid[i][j]) j++;
  }

  return mx;
}

int main(){
  fastio;

  cin >> n >> m >> q;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
       cin >> grid[i][j];

  for(int i=0;i<n;i++)
    row[i] = calc(i);

  while(q--){
    int i, j;
    cin >> i >> j;
    i--, j--;
    grid[i][j] ^= 1;
    row[i] = calc(i);
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, row[i]);
    cout << ans << endl; 
  }
  
  return 0;
}