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
 
ll myPow(ll a, ll b){
  ll ret = 1;

  for(int i=0;i<b;i++)
    ret *= a;

  return ret;
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n,k;
  cin >> n >> k;
  vll vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];
  
  map <ll,ll> cnt;
  ll sum = 0;
  cnt[0] = 1;
  ll ans = 0;

  for(int i=0;i<n;i++){
    sum += vet[i];
    int j = 0;
    while(true){
      ll pot = myPow(k,j);
      if(abs(pot) >= 2e14)
        break;
      if(k == 1 && j == 1)
        break;
      if(k == -1 && j == 2)
        break;
      ans += cnt[sum-pot];
      j++;
    }
    cnt[sum]++;
  }

  cout << ans << endl;
  return 0;
}