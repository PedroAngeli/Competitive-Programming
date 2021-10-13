#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
const int nax = 2e5 + 5;
int n,m;
vector <pair <int,int> > edgesUn;
vector <int> topo;
vector <int> adj[nax];
vector <bool> vis;
 
void dfs(int u){
  vis[u] = true;
 
  for(int v:adj[u]){
    if(!vis[v])
      dfs(v);
  }
  topo.push_back(u);
}
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;
  while(t--){
    cin >> n >> m;
 
    edgesUn.clear();
    topo.clear();
    vis.assign(nax,false);
 
    vector <pair <int,int> > ans;
 
    for(int i=1;i<=n;i++){
      adj[i].clear();
    }
 
    for(int i=0;i<m;i++){
      int type,x,y;
      cin >> type >> x >> y;
 
      if(type == 0){
        edgesUn.push_back({x,y});
      }else{
        adj[x].push_back(y);
        ans.push_back({x,y});
      }
    }
            
    for(int i=1;i<=n;i++){
      if(!vis[i])
        dfs(i);
    }
 
    reverse(topo.begin(),topo.end());
    vector <int> pos(n+1);
 
    for(int i=0;i<topo.size();i++){
      int u = topo[i];
      pos[u] = i;
    }
 
    for(auto p:edgesUn){
      int u = p.first;
      int v = p.second;
      if(pos[u] < pos[v])
        ans.push_back({u,v});
      else
        ans.push_back({v,u});
    }

    bool can = true;

    for(auto p:ans){
      if(pos[p.second] < pos[p.first]){
        can = false;
        break;
      }
    }

    if(!can){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
      for(auto p:ans)
        cout << p.first << " " << p.second << endl;
    }
  }
    
  return 0;
}