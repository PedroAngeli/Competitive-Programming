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

map <int,int> freq;
vi a;
int len;
const int mod = 998244353;
vector <vll> dp;

ll solve(int i,int k){
  if(k == 0)
    return 1;
  if(i >= len)
    return 0;
  ll& state = dp[i][k];
  if(state != -1)
    return state;
  
  return state = (solve(i+1,k)%mod + 1LL*freq[a[i]]*solve(i+1,k-1)%mod)%mod;
}

int main(){
  fastio;

  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    freq[x]++;
  }

  for(auto el:freq)
    a.pb(el.f);

  len = sz(a);
  dp.assign(len,vll(k+1,-1));
  cout << solve(0,k) << endl;
  
  return 0;
}