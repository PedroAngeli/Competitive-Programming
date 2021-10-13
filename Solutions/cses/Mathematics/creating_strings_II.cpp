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

const int m = 1e9 + 7;

int main(){
  fastio;

  string a;
  cin >> a;
  
  int n = sz(a);

  vi freq(26,0);
  for(char c:a)
    freq[c-'a']++;
  
  vll inv(n+1);
  inv[1] = 1;
  
  for(int i=2;i<=n;i++)
    inv[i] = (m - (m/i) * inv[m%i] % m) % m;

  vll f1(n+1),f2(n+1);
  f1[0] = 1;
  f2[0] = 1;

  for(int i=1;i<=n;i++){
    f1[i] = i*f1[i-1]%m;
    f2[i] = f2[i-1]*inv[i]%m;
  }

  ll ans = f1[n];

  for(int i=0;i<26;i++){
    ans *= f2[freq[i]];
    ans %= m;
  }

  cout << ans << endl;
  return 0;
}