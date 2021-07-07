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

int n,m,c,k;
const int nax = 255;
const int INF = 1e9 + 7;

int main(){
  fastio;

  while(cin >> n >> m >> c >> k){
    if(!n && !m && !c && !k)
      break;

    int dist[n][n];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        dist[i][j] = INF;

    for(int i=0;i<m;i++){
      int u,v,p;
      cin >> u >> v >> p;
      if(u > v)
        swap(u,v);

      if(u < c && v < c){
        if(v == u+1)
          dist[u][v] = p;
      }
      else if(u < c)
        dist[v][u] = p;
      else
        dist[u][v] = dist[v][u] = p;
    }

    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          
    cout << dist[k][c-1] << endl;
  }

    
  return 0;
}