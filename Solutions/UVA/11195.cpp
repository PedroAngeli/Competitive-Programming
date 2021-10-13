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

int n;
bool is_good[15][15];
int ans;
int placed;

void solve(int r, int d1, int d2){
  int col = __builtin_popcount(r);
  if(col == n){
    ans++;
    return;
  }
  int available = placed & (~(r | d1 | d2));

  while(available){
    int row = (available & (-available));
    available -= row;
    if(!is_good[(int)log2(row)][col]) continue;
    solve(r | row, (d1 | row) << 1, (d2 | row) >> 1);
  }
}

int main(){
  fastio;

  int ncase = 1;
  while(cin >> n and n){
    cout << "Case " << ncase++ << ": ";
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        char c;
        cin >> c;
        is_good[i][j] = (c == '.');
      }
    ans = 0;
    placed = (1 << n) - 1;
    solve(0, 0, 0);
    cout << ans << endl;
  }
  
  return 0;
}