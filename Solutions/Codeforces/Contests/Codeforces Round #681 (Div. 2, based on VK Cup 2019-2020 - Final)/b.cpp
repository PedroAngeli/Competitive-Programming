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


vpii cost;
int a,b;
vi dp;

int solve(int i){
  if(i == sz(cost)) return a;
  int& state = dp[i];
  if(state != -1) return state;

  if(cost[i].f == 1) return state = solve(i+1);
  else return state = min(cost[i].s * b + solve(i+1), a + solve(i+1));
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> a >> b;
    string S;
    cin >> S;
    int n = sz(S);
    cost.clear();
    
    int i = 0;
    while(i < n && S[i] == '0') i++;
    int j = n-1;
    while(j >= 0 && S[j] == '0') j--;

    int k = i;
    while(k <= j){
      int q1 = 0;
      while(k <= j && S[k] == '1') k++,q1++;
      cost.pb({1,q1});
      int q0 = 0;
      while(k <=j && S[k] == '0') k++,q0++;
      cost.pb({0, q0});
    }
    
    if(sz(cost) == 0) cout << 0 << endl;
    else{
      dp.assign(sz(cost),-1);
      cout << solve(0) << endl;
    } 
  }
  return 0;
}