#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
struct Graph{
  int V;
  vector <vector <int>> adj; 
  vector <int> match;
  vector <int> vis;
  Graph(int V): V(V){
    adj.resize(V+1);
    match.resize(V+1);
    vis.resize(V+1);
  }
  bool dfs(int u){
    vis[u] = true;
    for(int v:adj[u]){
      if(match[v] == -1 || (!vis[match[v]] && dfs(match[v]))){
        match[v] = u;
        return true;
      }
    }
    return false;
  }
  int solve(){
    fill(all(match), -1);
    bool flag = true;
    int max_match = 0;
    for(int i=1;i<=V;i++){
      fill(all(vis), false);
      if(dfs(i)) max_match++;
    }
    return max_match;
  }
};


