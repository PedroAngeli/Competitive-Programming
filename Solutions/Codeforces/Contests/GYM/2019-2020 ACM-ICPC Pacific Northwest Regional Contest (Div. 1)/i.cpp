#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


struct Graph{
  vector <vi> adj; 
  int V;
  const int INF = 1e9 + 7;
  vi matchA,matchB;
  vi side;
  vector <bool> visB;

  Graph(int V): V(V){
    adj.resize(V);
  }

  void addEdge(int u,int v){
    adj[u].pb(v);
    adj[v].pb(u);
  }

  bool dfs(int u){
  for(int v : adj[u]){
    if(visB[v])
      continue;
    visB[v] = true;
    if(matchB[v] == -1 || dfs(matchB[v])){
      matchA[u] = v;
      matchB[v] = u;
      return true;
    }
  }

  return false;
}
  void bfs(int u){
    queue<int> q;
    q.push(u);
    side[u] = 1;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int w:adj[u]){
        if(side[w] != -1)
          continue;
        q.push(w);
        if(side[u] == 1)
          side[w] = 2;
        else
          side[w] = 1;
      }
    }
  }
  int kuhn(){
    side.assign(V,-1);
    for(int i=0;i<V;i++)
      if(side[i] == -1)
        bfs(i);
    matchA.assign(V,-1);
    matchB.assign(V,-1);
    bool flag = true;
    int matched = 0;

    while(flag){
      flag = false;
      visB.assign(V+1,false);
      for(int i=0;i<V;i++){
        if(matchA[i] != -1 || side[i] == 2)
          continue;
        if(dfs(i)){
          matched++;
          flag = true;
        }
      }
    }
    
    return matched;
}

};

bool can(string& a,string& b){
  int cnt = 0;
  for(int i=0;i<sz(a);i++)
    if(a[i] != b[i])
      cnt++;

  return cnt == 2;
}

int main(){
  fastio;

  int n;
  cin >> n;
  vs words(n);

  for(int i=0;i<n;i++)
    cin >> words[i];
  
  Graph G(n);

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(can(words[i],words[j])){
        G.addEdge(i,j);
      }

  cout << n - G.kuhn() << endl;
  return 0;
}