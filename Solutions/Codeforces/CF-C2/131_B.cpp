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
  
  int n;
  cin >> n;
  map <int,ll> mp;

  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    mp[x]++;
  }

  ll ans = 0;

  for(auto p:mp){
    int x = p.first;
    ll cnt = p.second;
    if(x == 0){
      ans += ((cnt-1)*mp[x]);
      continue;
    }
    ans += (cnt*mp[-x]);
  }

  cout << ans/2 << endl;

  return 0;
}