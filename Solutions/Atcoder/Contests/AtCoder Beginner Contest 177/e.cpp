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


int main(){
  fastio;

  int n;
  cin >> n;
  vi a(n);

  int gcd = 0;

  vll primes;
  const int nax = 1e6 + 5;
  bitset <nax> is_prime;

  is_prime.set();

  for(ll i=2;i<=nax;i++){
    if(is_prime[i]){
      primes.pb(i);
      for(ll j = i*i;j<=nax;j += i)
        is_prime[j] = false;
    }
  }
  
  for(int i=0;i<n;i++){
    cin >> a[i];
    gcd = __gcd(a[i],gcd);
  }

  if(gcd != 1){
    cout << "not coprime" << endl;
    return 0;
  }

  vi freq(nax,0);

  for(int i=0;i<n;i++){
    int k = 0;
    while(primes[k]*primes[k] <= a[i]){
      int cnt = 0;
      while(a[i] % primes[k] == 0)
        cnt++,a[i] /= primes[k];
      if(cnt)
        freq[primes[k]]++;
      k++;
    }
    if(a[i] != 1)
      freq[a[i]]++;
  }

  bool pairwise = true;

  for(int i=2;i<nax;i++)
    if(freq[i] > 1){
      pairwise = false;
      break;
    }

  if(pairwise)
    cout << "pairwise coprime" << endl;
  else
    cout << "setwise coprime" << endl;

  return 0;
}