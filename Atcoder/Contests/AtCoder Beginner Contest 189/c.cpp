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

const int nax = 1e4 + 5;
const int max_log = 20;

struct SparseTable{
  int n;
  int logs[nax];
  int table[max_log][nax]; //table[k][i] - min starting at index i with size 2^k
  vi a;
  void computeLogs(){
    logs[1] = 0;
    for(int i=2;i<=n;i++)
      logs[i] = logs[i / 2] + 1;
  }

  void build(){
    for(int k=0;k<=logs[n];k++){
      int curLen = 1 << k;
      for(int i=0;i+curLen <= n;i++){
        if(curLen == 1) table[k][i] = a[i];
        else table[k][i] = min(table[k-1][i], table[k-1][i + (curLen / 2)]);
      }
    }
  }

  int get_min(int l,int r){
    int p = logs[r - l + 1];
    int pLen = 1 << p;
    return min(table[p][l], table[p][r - pLen + 1]);
  }

  SparseTable(vi& a):a(a){
    n = sz(a);
    computeLogs();
    build();
  }
};

int main(){
  fastio;

  int n;
  cin >> n;

  vi a(n);

  for(int i=0;i<n;i++) cin >> a[i];

  SparseTable table(a);

  int ans = 0;

  for(int l=0;l<n;l++)
    for(int r=l;r<n;r++){
      int mn = table.get_min(l, r);
      ans = max(ans, mn * (r-l+1));
    }

  
  cout << ans << endl;
  return 0;
}