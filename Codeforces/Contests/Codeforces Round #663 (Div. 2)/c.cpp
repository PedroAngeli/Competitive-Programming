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

ll fastExp(ll a, ll b){
  ll ans = 1;
  while(b > 0){
    if(b & 1){
      ans = (ans*a)%mod;
    }
    b /= 2;
    a = (a*a)%mod;
  }

  return ans;
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  //cin >> t;
  while(t--){
    ll n;
    cin >> n;
    ll fat[n+1];
    fat[0] = 1;

    for(int i=1;i<=n;i++){
      fat[i] = i * fat[i-1];
      fat[i] %= mod;
    }

    ll ret = fastExp(2,n-1);
    ll ans = fat[n] - ret;
    ans %= mod;
    if(ans < 0)
      ans += mod;
    cout << ans << endl;
    
  }


  return 0;
}