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

int n,x;

int main(){
  fastio;

  
  while(cin >> n >> x){
    if(n == 0 && x == 0)
      break;

    vector <vll> dp(n+1,vll(151,0));

    dp[0][0] = 1;

    for(int i=1;i<=n;i++)
      for(int j=0;j<=6*n;j++)
        for(int k=1;k<=6;k++)
          if(j-k>=0)
            dp[i][j] += dp[i-1][j-k];

    ll num = 0,den = 0;
    for(int j=1;j<=6*n;j++){
      if(j >= x)
        num += dp[n][j];
      den += dp[n][j];
    }

    ll gcd = __gcd(num,den);
    num /= gcd;
    den /= gcd;
    if(num == 0)
      cout << 0 << endl;
    else if(num == den)
      cout << 1 << endl;
    else
      cout << num << "/" << den << endl;
  }


  return 0;
}