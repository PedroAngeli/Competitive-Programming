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

  int n;
  cin >> n;
  vll vet(n+1);

  for(int i=1;i<=n;i++)
    cin >> vet[i];
  
  vll pref(n+1,0);

  for(int i=1;i<=n;i++){
    pref[i] = pref[i-1] + vet[i];
    pref[i] %= mod;
  }

  
  ll ans = 0;

  for(int i=1;i<n;i++){
    ans += vet[i]*(pref[n]-pref[i]);
    ans %= mod;
  }

  if(ans < 0)
    ans += mod;
    
  cout << ans << endl;

  return 0;
}