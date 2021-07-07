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

  int n,k;
  cin >> n >> k;
  vector <vi> d;
  d.resize(n+1);
  vi dist(n+1,0);
  vi edges(n+1,k);
  vi checkPossible(n+1);

  for(int i=1;i<=n;i++){
    cin >> dist[i];
    checkPossible[i] = dist[i];
    d[dist[i]].push_back(i);   
  }

  if(d[0].size() > 1 || d[0].size() == 0){
    cout << -1 << endl;
    return 0;
  }
  sort(checkPossible.begin(),checkPossible.end());
  for(int i=2;i<=n;i++){
    if(checkPossible[i]-checkPossible[i-1] > 1){
      cout << -1 << endl;
    return 0;
    }
  }

  vpii ans;

  int ini = d[0].back();
  d[0].pop_back();
  queue <int> q;
  q.push(ini);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    
    while(d[dist[u]+1].size() && edges[u]){
      int v = d[dist[u]+1].back();
      d[dist[u]+1].pop_back();
      ans.push_back({u,v});
      edges[u]--,edges[v]--;
      q.push(v);
    }
  }

  for(int i=0;i<n;i++){
    if(d[i].size() > 0){
      cout << -1 << endl;
      return 0;
    }
  }

  
  cout << ans.size() << endl;

  for(auto p:ans)
    cout << p.f << " " << p.s << endl;

  return 0;
}