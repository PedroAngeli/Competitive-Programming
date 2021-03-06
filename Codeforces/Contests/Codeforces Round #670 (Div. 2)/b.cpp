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

  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vll a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];

    sort(all(a),[&](ll i,ll j){
      return llabs(i) > llabs(j);
    });

    ll ans = 1;
   
    for(int i=0;i<5;i++)
      ans *= a[i];
    
    if(ans < 0){
      ll mx = ans;
      for(int i=0;i<5;i++){
        ll tmp = ans/a[i];
        for(int j=5;j<n;j++){
          mx = max(mx, tmp * a[j]);
        }
      }
      ans = max(ans,mx);
      if(ans < 0){
        ans = 1;
        reverse(all(a));
        for(int i=0;i<5;i++)
          ans *= a[i];
      }
    }

    cout << ans << endl;
  }


  return 0;
}