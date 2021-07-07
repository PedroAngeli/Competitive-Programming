#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

const int mod = 1e9 + 7;
const int nax = 1e5 + 1;
int dp[nax];
int t,k;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t >> k;

  memset(dp,0,sizeof dp);

  dp[0] = 1;
  for(int i=1;i<nax;i++){
    if(i-k>=0)
      dp[i] += dp[i-k];
    dp[i] += dp[i-1];
    dp[i] %= mod;
  }

  int pref[nax];

  pref[0]=0;
  for(int i=1;i<nax;i++){
    pref[i] = pref[i-1] + dp[i];
    pref[i] %= mod;
  }

  while(t--){
    int a,b;
    cin >> a >>b;
    int ans = pref[b]-pref[a-1];
    ans %= mod;
    if(ans < 0)
      ans += mod;
    cout << ans << endl;
  }

  return 0;
}