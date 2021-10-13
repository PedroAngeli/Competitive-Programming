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
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vi vet(n+1);

    for(int i=1;i<=n;i++){
      char c;
      cin >> c;
      vet[i]=c-'0';
    }

    ll ans = 0;

    map <int,ll> cnt;
    cnt[0]=1;
    int pref = 0;
    for(int i=1;i<=n;i++){
      pref+=vet[i];
      ans += cnt[pref-i];
      cnt[pref-i]++;
    }
  
    cout << ans << endl;
  }
  
  return 0;
}