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

vll a;
int n,q;
vector <vll> dp;

ll solve(int i,int pos){
  if(i == n)
    return 0;
  ll& state = dp[i][pos];
  if(state != -1)
    return state;

  if(pos)
    state = max(solve(i+1,pos),a[i] + solve(i+1,0));
  else
    state = max(solve(i+1,pos),-a[i] + solve(i+1,1));
  return state;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n >> q;
    a.resize(n);
    dp.assign(n,vll(2,-1));
    for(int i=0;i<n;i++)
      cin >> a[i];
    cout << solve(0,1) << endl;
  }

  return 0;
}