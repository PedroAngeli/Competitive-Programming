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
 
const int nax = 1e5 + 5;
int n;
vector <pair <pii, int> > trechos;
vi next_i;

ll dp[nax];
 
ll solve(int i){
  if(i == n) return 0;
  ll& state = dp[i];
  if(state != -1) return state;
  return state = max(solve(i+1), trechos[i].s + solve(next_i[i]));
}
 
int main(){
  fastio;
 
  cin >> n;
  trechos.resize(n);
  next_i.assign(n, n);
  memset(dp, -1, sizeof dp);
 
  for(int i=0;i<n;i++)
    cin >> trechos[i].f.f >> trechos[i].f.s, trechos[i].s = 1;
 
  sort(all(trechos));
 
  for(int i=0;i<n;i++)
    next_i[i] = lb(all(trechos), make_pair(make_pair(trechos[i].f.s+1, -1),-1)) - trechos.begin();
 
  cout << solve(0) << endl;
 
  return 0;
}