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

const int nax = 5001;
vi adj[nax];
vector <bool> vis;
vll c;
vll pont;

void solve(int u){
  vis[u]=true;
  for(int v:adj[u]){
    pont.push_back(c[v]);
    if(!vis[v])
      solve(v);
  }
  vis[u]=false;
}
int main(){
  fastio;

  int n,k;
  cin >> n >> k;
  vi p(n+1);
  c.resize(n+1);
  vis.assign(n+1,false);

  for(int i=1;i<=n;i++){
    cin >> p[i];
    adj[i].push_back(p[i]);
  }

   for(int i=1;i<=n;i++)
    cin >> c[i];

  ll ans = -1e18;

  for(int i=1;i<=n;i++){
    pont.clear();
    solve(i);
    ll len = pont.size();
    if(len >= k){
      ll mx = -1e18;
      ll sum = 0;
      for(int j=0;j<k;j++){
        sum += pont[j];
        mx = max(mx,sum);
      }
     ans = max(ans,mx);
    }else{  
      ll sum = 0;
      ll mx = -1e18;
      for(ll x:pont){
        sum += x;
        mx = max(mx,sum);
      }
      if(sum <= 0){
        ll rest = k%len;
        mx = max(mx,sum);
        for(int j=0;j<rest;j++){
          sum += pont[j];
          mx = max(mx,sum);
        }
        ans = max(ans,mx);
      }else{
        ll times = k/len;
        sum *= times;
        mx = max(mx,sum);
        ll rest = k%len;
        for(int j=0;j<rest;j++){
          sum += pont[j];
          mx = max(mx,sum);
        }
        sum = 0;
        for(ll x:pont){
          sum += x;
        }
        times--;
        sum *= times;
        mx = max(mx,sum);
        for(int j=0;j<len;j++){
          sum += pont[j];
          mx = max(mx,sum);
        }
        ans = max(ans,mx);
      }
    }
  }

  cout << ans << endl;

  return 0;
}