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


const int mod = 1e9 + 7;

int main(){
  fastio;

  int n,m,k;
  cin >> n >> m >> k;
  if(k > n || k == 1){ 
    ll ans = 1;
    for(int i=0;i<n;i++)
      ans *= m,ans%=mod;
    cout << ans << endl;
  }else if(k == n){
    ll ans = 1;
    for(int i=0;i<(n+1)/2;i++)
      ans*=m,ans%=mod;
    cout << ans << endl;
  }else if(k%2 == 0)
    cout << m << endl;
  else
    cout << m*m << endl;

  return 0;
}