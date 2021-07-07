#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  const ll nax = 1e6 + 5;
  vector <bool> is_prime(nax,true);
  vector <ll> fac(nax,0);

  for(ll i=2;i<nax;i++){
    if(is_prime[i]){
      fac[i] = 1;
      for(ll j=2*i;j<nax;j+=i){
        is_prime[j] = false;
        ll cur = j;
        while(cur%i==0)
          fac[j]++,cur/=i;
      }
    }
  }

  vector <ll> pref(nax,0);
  for(int i=2;i<nax;i++)
    pref[i] = pref[i-1] + fac[i];

  int n;
  while(cin >> n){
    cout << pref[n] << endl;
  }
 
  return 0;
}