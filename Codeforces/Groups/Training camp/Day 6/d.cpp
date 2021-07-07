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

const int nax = 1e5+5;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;

  vii e[nax];

  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    e[w].push_back({u,v});
  }

  vi dp(n+1,0);
  vi temp(n+1,0);

  for(int i=1;i<nax;i++){
      for(auto el : e[i]){
        int v = el.s;
        temp[v] = 0;
      }
      for(auto el : e[i]){
        int u = el.f;
        int v = el.s;
        temp[v] = max(temp[v],1+dp[u]);
      }
      for(auto el : e[i]){
        int u = el.f;
        int v = el.s;
        dp[v] = max(dp[v],temp[v]);
      }
    }
  

  int ans = 0;
  for(int i=1;i<=n;i++)
    ans = max(ans,dp[i]);

  cout << ans << endl;
  
  return 0;
}