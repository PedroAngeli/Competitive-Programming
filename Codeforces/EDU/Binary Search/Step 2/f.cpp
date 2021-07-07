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

string t, p;
vi perm;
int n;

bool is_subsquence(string& a, string& b){
  int l1 = sz(a);
  int l2 = sz(b);
  int i = 0, j = 0;
  while(i < l1 and j < l2){
    if(a[i] == b[j]) j++;
    i++;
  }
  return j == l2;
}
bool can(int m){
  string a = t;
  string b = p;

  for(int i=1;i<=m;i++) a[perm[i]-1] = '#';

  return is_subsquence(a, b);
}

int main(){
  fastio;

  cin >> t >> p;

  n = sz(t);
  perm.resize(n + 1);
  for(int i=1;i<=n;i++) cin >> perm[i];

  int l = 1;
  int r = n;
  int ans = 0;

  while(l <= r){
    int m = (l + r)/2;
    if(can(m)) ans = m, l = m+1;
    else r = m-1;
  }  

  cout << ans << endl;
  return 0;
}