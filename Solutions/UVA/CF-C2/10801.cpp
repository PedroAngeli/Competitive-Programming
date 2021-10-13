#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int n,target;
const int INF = 1e9 + 7;
int cost[5];
vector <pair <int,int> > adj[500];
vector <int> dist;

void solve(int s){
  set <pair <int,int> > q;
  dist[s] = 0;
  q.insert({0,s});

  while(!q.empty()){
    auto it = q.begin();
    int u = it->second;
    q.erase(q.begin());
    
    for(pair <int,int> p : adj[u]){
      int v = p.first;
      int w = p.second;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        q.insert({dist[v],v});
      }
    }
  }
}

int main(){
 
  while(scanf("%d %d",&n,&target) == 2){
    for(int i=0;i<n;i++)
      scanf("%d",&cost[i]);
    for(int i=0;i<500;i++)
      adj[i].clear();

    dist.assign(500,INF);
    vector <int> init;
    
    for(int i=0;i<n;i++){
      vector <int> floor;
      while(true){
        char c;
        int f;
        int ret = scanf("%d%c",&f,&c);
        if(f == 0)
          init.push_back(i*100);
        floor.push_back(f);
        if((int)c == '\n' || ret != 2)
          break;
      }

      int len = floor.size();
  
      for(int j=0;j<len-1;j++){
        int n1 = floor[j];
        int n2 = floor[j+1];
        int mapN1 = i*100 + n1;
        int mapN2 = i*100 + n2;
        int w = (n2-n1)*cost[i];
        adj[mapN1].push_back({mapN2,w});
        adj[mapN2].push_back({mapN1,w});
      }  
    }

    for(int i=0;i<n;i++){
      for(int k=0;k<100;k++){
        for(int j=i+1;j<n;j++){
              adj[k + i*100].push_back({k+j*100,60});
              adj[k + j*100].push_back({k+i*100,60});
          }
        } 
    }

    for(int i=0;i<init.size();i++)
      solve(init[i]);

    int ans = min({dist[target],dist[target+100],dist[target+200],dist[target+300],dist[target+400]});

    if(ans == INF){
      printf("IMPOSSIBLE\n");
    }else
      printf("%d\n",ans);
  } 

  return 0;
}