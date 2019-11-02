#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 20000
 
vector <int> adj[MAXN];
bool visitado[MAXN];
 
int bfs(int u,int v){
  queue < pair <int,int> > fila;
  fila.push({u,0});
 
  while(!fila.empty()){
    int w = fila.front().first;
    int d = fila.front().second;
    fila.pop();
 
    if(w == v){
      return d;
    }
 
    int v1 = w * 2;
    int v2 = w - 1;
 
    
    if(v1 < 2*v && !visitado[v1]){
      fila.push({v1,d+1});
      visitado[v1] = true;
    }
 
    if(v2 > 0 && !visitado[v2]){
      fila.push({v2,d+1});
      visitado[v2] = true;
    }
  }
}
 
int main(){
  int n,m;
 
  scanf("%d %d",&n,&m);
 
  printf("%d\n",bfs(n,m));
  return 0;
}