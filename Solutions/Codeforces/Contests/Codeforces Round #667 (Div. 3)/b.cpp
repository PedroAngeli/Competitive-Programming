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
    ll a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;

    ll b1 = max(b-n,y);
    ll a1 = max(a-(n-(b-b1)),x);

    ll a2 = max(a-n,x);
    ll b2 = max(b-(n-(a-a2)),y);


    cout << min(a2*b2,a1*b1) << endl;
  }

  return 0;
}