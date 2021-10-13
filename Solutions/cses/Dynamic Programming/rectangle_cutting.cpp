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

int dp[501][501];

int solve(int a,int b){
  if(a == b)
    return 0;
  
  int& state = dp[a][b];

  if(state != -1)
    return state;

  int mn = INT_MAX;

  for(int i=1;i<a;i++)
    mn = min(mn,1 + solve(i,b) + solve(a-i,b));

  for(int i=1;i<b;i++)
    mn = min(mn,1 + solve(a,i) + solve(a,b-i));

  return state = mn;
}

int main(){
  fastio;

  int a,b;
  cin >> a >> b;

  memset(dp,-1,sizeof dp);

  cout << solve(a,b) << endl;

  return 0;
}