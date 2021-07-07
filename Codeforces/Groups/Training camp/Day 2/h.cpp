#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int n,m,k;
int s,t;
vector <vector <int> > adj;
vector <bool> icpc;
const int INF = 1e9+7;
 
 
bool can(int q){
  vector <int> dist(n+1,INF);
  
  dist[s] = 0;
  queue <int> fila;
  fila.push(s);
 
  while(!fila.empty()){
    int u = fila.front(); 
    fila.pop();

    if(icpc[u])
      dist[u] = 0;

    if(dist[u] < q){
      for(int v:adj[u]){
        if(dist[u]+1 < dist[v]){
          dist[v] = dist[u]+1;
          fila.push(v);
        }
      }
    }
  }
  
  return dist[t] != INF;
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >>m >> k;
  icpc.assign(n+1,false);

  for(int i=0;i<k;i++){
    int x;
    cin >> x;
    icpc[x] = true;
  }
 
  adj.resize(n+1);
 
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  cin >> s >> t;
 
  int l = 1;
  int r = n+1;
 
  int ans = INF;
 
  while(l <= r){
    int q = (l+r)/2;

    if(can(q)){
      ans = min(ans,q);
      r = q-1;
    }else{
      l = q+1;
    }
  }
 
  if(ans == n+1 || ans == INF)
    ans = -1;
  cout << ans << endl;
  
  return 0;
}