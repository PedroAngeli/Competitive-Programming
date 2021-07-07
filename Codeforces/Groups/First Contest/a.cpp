#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
vector < pair <int,long long> > adj[nax];
bitset <nax> is_prime;
vector <int> vertices;
int n;
vector <long long> dist1;
vector <long long> dist2;
bool visitado[nax];

void SieveOfEratosthenes(){
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;

  for(long long i = 2;i<=nax;i++){
    if(is_prime[i]){
      for(long long j = i*i;j<=nax;j+=i){
        is_prime[j] = 0;
      }
    }
  }
}

int bfs1(int u){

  visitado[u] = true;
  
  dist1[u] = 0;

  queue <int> q;
  q.push(u);

  long long maiorDist = 0;
  int verticeMaisDist = u;

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int i=0;i<adj[v].size();i++){
      int w = adj[v][i].first;
      int p = adj[v][i].second;

      if(dist1[w] == INF){
        visitado[w] = true;
        dist1[w] = p + dist1[v];
        q.push(w);

        if(dist1[w] > maiorDist){
          maiorDist = dist1[w];
          verticeMaisDist = w;
        }

      }
    }
  }

  return verticeMaisDist;
}

int bfs2(int u){

  visitado[u] = true;
  
  dist2[u] = 0;

  queue <int> q;
  q.push(u);

  long long maiorDist = 0;
  int verticeMaisDist = u;

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int i=0;i<adj[v].size();i++){
      int w = adj[v][i].first;
      int p = adj[v][i].second;

      if(dist2[w] == INF){
        visitado[w] = true;
        dist2[w] = p + dist2[v];
        q.push(w);

        if(dist2[w] > maiorDist){
          maiorDist = dist2[w];
          verticeMaisDist = w;
        }

      }
    }
  }

  return verticeMaisDist;
}

long long diameter(int u){
  return dist2[bfs2(bfs1(u))];
}

int main(){

  
  SieveOfEratosthenes();
  cin >> n;

  dist1 = vector <long long> (n+1,INF);
  dist2 = vector <long long> (n+1,INF);


  for(int i=0;i<n-1;i++){
    long long u,v,w;
    cin >> u >> v >> w;

    if(is_prime[w]){
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
  }

  long long ans = 0;

  for(int i=1;i<=n;i++){
      if(!visitado[i])
        ans = max(ans,diameter(i));
  }

  cout << ans << endl;

 
  

  return 0;
}