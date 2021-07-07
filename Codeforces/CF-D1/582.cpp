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


int main(){
  fastio;

  int n, T;
  cin >> n >> T;
  vi a(n);
  for(int i=0;i<n;i++) cin >> a[i];


  vector <vi> lis(1000, vi(n,1));

  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++) if(a[i] >= a[j]) lis[0][i] = max(lis[0][i], lis[0][j] + 1);

  int k;
  for(k=1;k<min(1000, T);k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) if(a[i] >= a[j]) lis[k][i] = max(lis[k][i], lis[k-1][j] + 1);
      for(int j=0;j<i;j++) if(a[i] >= a[j]) lis[k][i] = max(lis[k][i], lis[k][j] + 1);
    }
  }
  k--;
  int mx_cur = 0;
  for(int i=0;i<n;i++) mx_cur = max(mx_cur, lis[k][i]);
  if(k + 1 == T){
    cout << mx_cur << endl;
    return 0;
  } 

  int mx_last = 0;
  for(int i=0;i<n;i++) mx_last = max(mx_last, lis[k-1][i]);

  int dif = mx_cur - mx_last;

  cout << mx_cur + dif*(T - k - 1) << endl;
  
  return 0; 
}