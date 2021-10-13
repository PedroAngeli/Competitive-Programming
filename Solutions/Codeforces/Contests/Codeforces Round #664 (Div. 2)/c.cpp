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
    int n,m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    for(int i=0;i<n;i++)
      cin >> a[i];
    for(int i=0;i<m;i++)
      cin >> b[i];

    int ans = 0;

    for(int mask=0;mask<(1 << 9);mask++){
      int cnt = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          int x = a[i] & b[j];
          int y = x | mask;
          if(y == mask){
            cnt++;
            break;
          }
        }
      }
      if(cnt == n){
        ans = mask;
        break;
      }
    }

    cout << ans << endl;
  }
  return 0;
}