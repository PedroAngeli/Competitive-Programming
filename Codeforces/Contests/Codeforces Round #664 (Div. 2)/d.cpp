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
 
  int t=1;
  // cin >> t;
  while(t--){
    ll n,d,m;
    cin >> n >> d >> m;
    vll big;
    vll low;
    ll sum_low = 0;
    for(int i=0;i<n;i++){
      ll x;
      cin >> x;
      if(x > m)
        big.push_back(x);
      else
        low.push_back(x),sum_low+=x;
    }
    
    sort(big.begin(),big.end());
    reverse(big.begin(),big.end());
    sort(low.begin(),low.end());

    int b = 0;
    int l = 0;
    int leftover = n-1;
    int low_qtd = low.size();
    ll sum_big = 0;
    ll ans = sum_low;

    while(b < big.size() && leftover >= 0){
      sum_big += big[b];
      b++;

      while(low_qtd > leftover){
        low_qtd--;
        sum_low -= low[l];
        l++;
      }

      ans = max(ans,sum_low+sum_big);
      leftover -= d+1;
    }

    cout << ans << endl;
  }
 
  return 0;
}