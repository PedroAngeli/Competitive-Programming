#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

int mod = 1e9 + 9;
int dp[128][1000][129];
int k;

int fastexp(ll a,ll b){
  ll ans = 1;

  while(b){
    if(b&1)
      ans = (a * ans)%k;
    a = (a * a)%k;
    b /= 2;
  }

  return ans;
}

int solve(int i,int n,int cnt){
  if(i == -1)
    return n == 0 ? cnt : 0;

  int& state = dp[i][n][cnt];
  if(state != -1)
    return state;

  int p = fastexp(2,i);
  return state = (solve(i-1, n, cnt) + solve(i-1,(p + n)%k,cnt+1))%mod;
}

int main(){
  fastio;

  memset(dp,-1,sizeof dp);
  int b;
  cin >> k >> b;

  cout << solve(b-1,0,0) << endl;
  
  
  return 0;
}
