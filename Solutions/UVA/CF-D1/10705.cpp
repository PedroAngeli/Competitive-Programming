#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
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

  int t;
  cin >> t;

  while(t--){
    int k;
    cin >> k;
    string a;
    cin >> a;
    ll n;
    cin >> n;
    ll unsigned mx = 0,mn = 0;
    string ans;
    ans.resize(k);

    for(int i=0;i<k;i++){
      if(a[i] == 'p')
        ans[i] = '1', mx += (1ULL << (k-i-1));
      else
        ans[i] = '0', mn += (1ULL << (k-i-1));
    }

    if((n > 0 && n > mx) || (n < 0 && (ll)-n > mn)){
      cout << "Impossible" << endl;
      continue;
    }

    ll unsigned dif = mx - n;
    for(int i=0;i<k;i++){
      if(dif >= (1ULL << (k-i-1))){
        dif -= (1ULL << (k-i-1));
        if(a[i] == 'p')
          ans[i] = '0';
        else
          ans[i] = '1';
      }
    }
    cout << ans << endl;     
  }

  return 0;
}