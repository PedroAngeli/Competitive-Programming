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

vll r,g,b;
ll dp[205][205][205];

const ll INF = 1e9 + 7;

ll solve(int R,int G,int B){
  if(R < 0 || G < 0 || B < 0)
    return -INF;

  int base = (R==0) + (G==0) + (B==0);
  if(base >= 2)
    return 0;

  ll& state = dp[R][G][B];

  if(state != -1)
    return state;

  return state = max({r[R]*g[G] + solve(R-1,G-1,B) , r[R]*b[B] + solve(R-1,G,B-1) , g[G]*b[B] + solve(R,G-1,B-1)});
}
int main(){
  fastio;

  int t=1;
  // cin >> t;
  while(t--){
    int R,G,B;
    cin >> R >> G >> B;
    memset(dp,-1,sizeof dp);
    r.assign(R+1,0);
    g.assign(G+1,0);
    b.assign(B+1,0);

    for(int i=1;i<=R;i++)
      cin >> r[i];
    for(int i=1;i<=G;i++)
      cin >> g[i];
      for(int i=1;i<=B;i++)
      cin >> b[i];

    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());

    cout << solve(R,G,B) << endl;
  }
  
  return 0;
}