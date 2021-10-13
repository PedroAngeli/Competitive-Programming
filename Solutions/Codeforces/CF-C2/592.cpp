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
 
ll gcd(ll a, ll b){
  if(b == 0)
    return a;
  
  return gcd(b,a%b);
}
 
ll lcm(ll a,ll b){
  long double tmp1 = a;
  long double tmp2 = b;
  return (tmp1*tmp2)/gcd(a,b); 
}
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  ll t,w,b;
  cin >> t >> w >> b;
 
  ll mmc = lcm(w,b);
  ll k = t/mmc;
  ll aux = min(w,b)-1;
 
  ll ans = k + (k+1)*aux;
 
  ll last = (t/mmc)*mmc;
  ll dif = t-last;
  if(aux > dif)
    ans -= (aux-dif);
 
  ll mdc = gcd(ans,t);
 
  cout << ans/mdc << "/" << t/mdc << endl; 
 
  return 0;
}
