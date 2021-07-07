#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

  ll x,k,d;

  cin >> x >> k >> d;
  x = abs(x);
  ll k2 = x/d;

  x -= min(k2,k)*d;

  if(k2 < k){
    ll m = (k2%2 != k%2);
    x = min(abs(x-m*d),abs(x+m*d));
  }

  cout << abs(x) << endl;
  
  return 0;
}