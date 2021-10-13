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

  int n;
  cin >> n;
  vector <vi> web(n);
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    while(k--){
      int x;
      cin >> x;
      web[i].pb(x);
    }
    sort(all(web[i]));
  }

  int ans = 0;

  for(int i=0;i<n;i++){
    int right = (i-1+n) % n;
    int left = (i+1) % n;
    
    for(int j=1;j<sz(web[i]);j++){
      int q1 = upper_bound(all(web[right]), web[i][j-1]) - upper_bound(all(web[right]),web[i][j]);
      int q2 = upper_bound(all(web[left]), web[i][j-1]) - upper_bound(all(web[left]),web[i][j]);
      if(q1 != q2)
        ans++;
    }
  }

  cout << ans << endl;
  return 0;
}