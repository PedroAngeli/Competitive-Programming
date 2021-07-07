#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int n,k;
const int nax = 1e5 + 5;
const int INF = 1e9 + 7;
vector <int> adj[nax];
vector <int> dist;
vector <int> parent;
 
int bfs(int s){
  dist.assign(n+1,INF);
  parent.assign(n+1,0);
  dist[s] = 0;
  queue <int> q;
  q.push(s);
 
  while(!q.empty()){
    int v = q.front();
    q.pop();
 
    for(int w : adj[v]){
      if(dist[w] == INF){
        dist[w] = dist[v] + 1;
        q.push(w);
        parent[w] = v;
      }
    }
  }
 
  int mxV;
  int mxD = 0;
  for(int i=1;i<=n;i++){
    if(dist[i] > mxD){
      mxD = dist[i];
      mxV = i;
    }
  }
 
  return mxV;
}
 
bool solve(int u,int k,int p){
  int len = adj[u].size();
  if(p)
    len--;
  
  if(len < 3 && k > 0)
    return false;
  
  if(k == 0 && len > 0)
    return false;
  
  for(int v : adj[u]){
    bool ret = true;
    if(v != p)
      ret = solve(v,k-1,u);
    if(!ret)
      return false;
  }
  return true;
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >> k;
 
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(n <= 3){
    cout << "No" << endl;
    return 0;
  }
 
  int v = bfs(bfs(1));
  int diameter = dist[v]+1;
 
  if(diameter % 2 == 0){
    cout << "No" << endl;
    return 0;
  }
 
  int center;
  int distCenter = (diameter+1)/2;
 
  while(dist[v]+1 != distCenter){
    v = parent[v];
  }
  center = v;
 
  bool is = solve(center,k,0);
 
  if(is)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}