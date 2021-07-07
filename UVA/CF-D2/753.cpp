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

map <string,int> mp;
const int INF = 1e9 + 7;
int adj[10009][10009];

bool augment_path(int source,int sink,vi& parent){
  vector <bool> vis(sink+1,false);
  queue <int> q;
  vis[source] = true;
  q.push(source);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v=0;v<=sink;v++){
      if(adj[u][v] == 0 || vis[v])
        continue;
      vis[v] = true;
      q.push(v);
      parent[v] = u;
    }
  }

  return vis[sink];
}

int Max_flow(int source,int sink){
  int max_flow = 0;
  vi parent(sink+1);

  while(augment_path(source,sink,parent)){
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

  int t;
  cin >> t;
  
  while(t--){
    
    mp.clear();
    vs rec;
    vs dev;

    for(int i=0;i<10009;i++)
      for(int j=0;j<10009;j++)
        adj[i][j] = 0;

    int n;
    cin >> n;
    int vertex = 1;

    for(int i=0;i<n;i++){
      string r;
      cin >> r;
      if(mp.count(r) == 0)
        mp[r] = vertex++;
      rec.pb(r);
    }

    int m;
    cin >> m;

    for(int i=0;i<m;i++){
      string a,b;
      cin >> a >> b;

      if(mp.count(a) == 0)
        mp[a] = vertex++;
      if(mp.count(b) == 0)
        mp[b] = vertex++;

      adj[mp[a]][mp[b]] = 1;
      dev.pb(a);
    }

    int k;
    cin >> k;
    for(int i=0;i<k;i++){
      string a,b;
      cin >> a >> b;
      if(mp.count(a) == 0)
        mp[a] = vertex++;
      if(mp.count(b) == 0)
        mp[b] = vertex++;
      adj[mp[a]][mp[b]] = INF;
    }

    int source = 0;
    int sink = vertex;
   
    for(string r:rec)
      adj[mp[r]][sink]++;
    for(string d:dev)
      adj[source][mp[d]]++;

         
    cout << m - Max_flow(source,sink) << endl;
    if(t >= 1)
      cout << endl;
  }


  return 0;
}