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
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

int n,m,k;
ll rel[19][19];
vector <vll> dp;
vll a;

ll solve(int mask,int last){
  int qtd = __builtin_popcount(mask);

  if(qtd == m)
    return 0;
   
  ll& state = dp[mask][last];
  if(state != -1)
    return state;
  
  state = 0;

  for(int i=1;i<=n;i++){
    int shift = i-1;
    if(mask & (1 << shift))
      continue;

    state = max(state, a[i] + rel[i][last] + solve(mask | (1 << shift),i));
  }

  return state;
}

int main(){
  fastio;

  cin >> n >> m >> k;
  dp.assign((1 << 18),vll(n+1,-1));
  a.resize(n+1);

  for(int i=1;i<=n;i++)
    cin >> a[i];

  while(k--){
    int x,y,c;
    cin >> x >> y >> c;
    rel[y][x] = c;
  }

  cout << solve(0,0) << endl;

  return 0;
}