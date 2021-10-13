#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
struct Graph{
  int VA, VB;
  vector <vector <int>> adj; 
  vector <int> matchA, matchB;
  vector <bool> visB;
  Graph(int VA,int VB): VA(VA), VB(VB){
    adj.resize(VA+1);
    matchA.resize(VA+1);
    matchB.resize(VB+1);
    visB.resize(VB+1);
  }
  void addEdge(int u,int v){
    adj[u].push_back(v);
  }
  bool dfs(int u){
    for(int v : adj[u]){
      if(visB[v]) continue;
      visB[v] = true;
      if(matchB[v] == -1 || dfs(matchB[v])){
        matchA[u] = v;
        matchB[v] = u;
        return true;
      }
    }
    return false;
  }
  int kuhn(){
    fill(all(matchA), -1);
    fill(all(matchB), -1);
    bool flag = true;
    int matched = 0;
    while(flag){
      flag = false;
      fill(all(visB), false);
      for(int i=1;i<=VA;i++){
        if(matchA[i] != -1) continue;
        if(dfs(i)){
          matched++;
          flag = true;
        }
      }
    }
    return matched;
  }
};