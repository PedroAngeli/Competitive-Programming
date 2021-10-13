#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
struct Graph{
  vector <vector <int> > adj;
  int V;
  vector <int> parent;
  Graph(int V): V(V){
    adj.resize(V+1, vector <int>(V+1,0));
  }
  //Grafo dirigido ou não?
  void addEdge(int u,int v,int w){
    adj[u][v] = w;
    adj[v][u] = 0;
  }
  bool augment_path(int source,int sink){
    vector <bool> vis(V+1,false);
    queue <int> q;
    vis[source] = true;
    q.push(source);
      while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0;v<=sink;v++){
          if(adj[u][v] == 0 || vis[v]) continue;
          vis[v] = true;
          q.push(v);
          parent[v] = u;
        }
    }
    return vis[sink];
  }
  //Recebe source e sink e retorna o fluxo máximo
  //O(VE²) no geral e O(VE) em grafo bipartido
  int edmonds_karp(int source,int sink){ 
    int max_flow = 0;
    parent.resize(V+1);
    while(augment_path(source,sink)){
      int path_flow = INF;
      int v = sink;
      while(v != source){
        int u = parent[v];
        path_flow = min(path_flow, adj[u][v]);
        v = u;
      }
      v = sink;
      while(v != source){
        int u = parent[v];
        adj[u][v] -= path_flow;
        adj[v][u] += path_flow;
        v = u;
      }
      max_flow += path_flow;
    }
    return max_flow;
  }
};