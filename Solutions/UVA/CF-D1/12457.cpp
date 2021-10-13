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

ld prob;
vector <vector <ld> > dp;
int n;
const ld EPS = 1e-9;

ld solve(int i,int j){
  int b = ((2*n-1)-i)-j;
  if(b == n || (i == 0 && j < n)) 
    return 0;

  if(j == n)
    return 1;

  ld& state = dp[i][j];
  if(state >= 0)
    return state;

  state = prob*solve(i-1,j+1) + (1-prob)*solve(i-1,j);

  return state;
}
int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    cin >> n;
    cin >> prob;
    dp.assign(2*n+2,vector<ld>(n+1,-1));
    cout << fixed << setprecision(2) << solve(2*n-1,0) << endl;
  }


  return 0;
}