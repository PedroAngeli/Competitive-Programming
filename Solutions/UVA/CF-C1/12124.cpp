#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

map <string,vpll> mp;
ll n,b;

bool can(ll m){
  ll sum = 0;
  for(auto item:mp){
    ll small = 1e9;
    for(auto p:item.second){
      if(p.second >= m)
        small = min(small,p.first);
    }
    sum += small;
  }
  return sum <= b;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    cin >> n >> b;
    mp.clear();
    while(n--){
      string type,name;
      ll price,quality;
      cin >> type >> name >> price >> quality;
      mp[type].push_back({price,quality});
    }

    ll l = 0;
    ll r = 1e9;
    ll ans = 0;

    while(l <= r){
      ll m = (l+r)/2;
      if(can(m)){
        ans = m;
        l = m+1;
      }else{
        r = m-1;
      }
    }

    cout << ans << endl;
  }

  return 0;
}