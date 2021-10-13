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

vi a;
vi is_neg;
int dp[30][6005][31];
int used[6005];

void solve(int i,int sum, int open){
  if(i == sz(a)){
    used[sum + 3000] = true; 
    return;
  }

  int& state = dp[i][sum + 3000][open];
  if(state != -1)
    return;

  state = 1;

  sum += (a[i] * ((open % 2 == 1) ? -1 : 1));

  if(is_neg[i]) solve(i+1, sum, open + 1);
  if(open > 0) solve(i+1, sum, open - 1);
  solve(i+1, sum, open);
}

int main(){
  fastio;

  string line;
  while(getline(cin,line)){
    a.clear();
    is_neg.clear();
    stringstream ss(line);
    int x;
    char op;
    ss >> x;
    a.pb(x);
    is_neg.pb(0);
    while(ss >> op  >> x){
      if(op == '-') is_neg.pb(1), a.pb(-x);
      else is_neg.pb(0),a.pb(x);
    }
    memset(dp,-1,sizeof dp);
    memset(used,0,sizeof used);
    solve(0, 0, 0);
    int ans = 0;
    for(int i=0;i<=6000;i++) ans += used[i];
    cout << ans << endl;
  }
  return 0;
}