#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 205;
int adj[nax][nax];
int n;
const int INF = 1e9 + 7;

bool augment_path(int source,int sink,vi& parent){
  vector <bool> vis(2*n+2,false);
  vis[source] = true;
  queue <int> q;
  q.push(source);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    if(u == sink)
      break;
    for(int v=0;v<=2*n+1;v++){
      if(adj[u][v] == 0)
        continue;
      if(!vis[v]){
        vis[v] = true;
        parent[v] = u;
        q.push(v);
      }
    }
  }

  return vis[sink];
}
int Max_Flow(){
  int source = 0;
  int sink = 2*n + 1;

  vi parent(2*n+2);
  int max_flow = 0;

  while(augment_path(source, sink, parent)){
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

int main(){
  fastio;

  while(cin >> n){
    for(int i=0;i<=2*n+1;i++)
      for(int j=0;j<=2*n+1;j++)
        adj[i][j] = 0;

    for(int i=1;i<=n;i++){
      int r;
      cin >> r;
      adj[i][i+n] = r;
    }

    int m;
    cin >> m;

    while(m--){
      int u,v,w;
      cin >> u >> v >> w; 
      adj[u+n][v] += w;
    }

    int b,d;
    cin >> b >> d;
    for(int i=0;i<b;i++){
      int u;
      cin >> u;
      adj[0][u] = INF;
    }

    for(int i=0;i<d;i++){
      int u;
      cin >> u;
      adj[u+n][2*n+1] = INF;
    }

    cout << Max_Flow() << endl;
  }


  return 0;
}