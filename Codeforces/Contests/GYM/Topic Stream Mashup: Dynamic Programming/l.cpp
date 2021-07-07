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

const int nax = 1005;
int n, k;
int r[nax], c[nax], p[nax], id[nax], id_2[nax];
int dp[nax][nax];
vpii ans;
const int INF = 1e9 + 7;

int solve(int i,int j){
  if(i == n or j == k) return 0;
  int& state = dp[i][j];
  if(state != -1) return state;

  state = 0;

  if(c[id[i]] <= r[id_2[j]]) state = max(state, p[id[i]] + solve(i+1, j+1));
  else return state = solve(i, j+1);

  return state = max(state, solve(i+1, j));
}

void construct(int i,int j){
  if(i == n or j == k) return;

  int& state = dp[i][j];

  if(c[id[i]] <= r[id_2[j]]){
    if(state == p[id[i]] + solve(i+1, j+1)){
      ans.pb({id[i], id_2[j]});
      construct(i+1, j+1);
      return;
    }
  }else{
    construct(i, j+1);
    return;
  }

  construct(i+1, j);
}

int main(){
  fastio;
  memset(dp, -1,sizeof dp);
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> c[i] >> p[i];
    id[i] = i;
  } 

  sort(id, id+n,[&](int i,int j){
    return (c[i] < c[j]) or (c[i] == c[j] and p[i] > p[j]);
  });

  cin >> k;
  
  for(int i=0;i<k;i++){
    cin >> r[i];
    id_2[i] = i;
  } 
  
  sort(id_2, id_2+k,[&](int i,int j){
    return r[i] < r[j];
  });

  int total_money = solve(0, 0);

  construct(0, 0);

  cout << sz(ans) << " " << total_money << endl;

  for(auto x:ans)
    cout << x.f+1 << " " << x.s+1 << endl;
  return 0;
}