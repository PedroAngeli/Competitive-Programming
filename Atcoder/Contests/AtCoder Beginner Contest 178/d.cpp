#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
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

vi dp;
const int mod = 1e9 + 7;

int solve(int s){
  if(s == 0)
    return 1;

  int& state = dp[s];
  if(state != -1)
    return state;

  state = 0;
  for(int i=3;i<=s;i++)
    state += solve(s-i), state %= mod;

  return state;
}

int main(){
  fastio;

  int s;
  cin >> s;
  dp.assign(s+1,-1);
  cout << solve(s) << endl;

  return 0;
}