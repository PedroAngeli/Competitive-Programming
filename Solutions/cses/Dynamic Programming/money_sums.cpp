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

bool dp[101][100005];
int n;
vi coins;
vi ans;

void solve(int i,int j){
  if(dp[i][j])
    return;

  dp[i][j] = true;
  if(i == n){
    if(j)
      ans.pb(j);
    return;
  }

  solve(i+1,j);
  solve(i+1,j+coins[i]);
}

int main(){
  fastio;

  memset(dp,false,sizeof dp);

  cin >> n;
  coins.resize(n);

  for(int i=0;i<n;i++)
    cin >> coins[i];
  
  solve(0,0);

  sort(all(ans));

  cout << sz(ans) << endl;
  for(int x:ans)
    cout << x << " ";
  cout << endl;
  return 0;
}