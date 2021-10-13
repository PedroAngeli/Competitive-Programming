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

  ll n;
  cin >> n;

  ll num = 0;
  ll den = n;
  vll p(n);

  for(ll i=0;i<n;i++){
    cin >> p[i];
    num += p[i];
  }

  sort(p.begin(),p.end());
  ll sumPairs = 0;
  for(ll i=0;i<n;i++){
    sumPairs += (i*p[i]);
    sumPairs += -1*(p[i])*(n-1-i);
  }
  sumPairs *= 2;
  num += sumPairs;
  ll gcd = __gcd(num,den);
  cout << num/gcd << " " << den/gcd << endl;

  return 0;
}