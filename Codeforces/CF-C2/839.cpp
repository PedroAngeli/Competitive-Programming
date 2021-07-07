#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

const int nax = 1e5 + 5;
bool vis[nax];
int dist[nax];
bool isLeaf[nax];
ld prob[nax];
vector <int> adj[nax];

void solve(){
    queue <int> q;
    q.push(1);
    dist[1] = 0;
    prob[1] = 1;

    while(!q.empty()){
      int u = q.front();
      q.pop();
      vis[u] = true;
      int total = 0;
      for(int v:adj[u])
        if(!vis[v])
          total++;
      if(total == 0){
        isLeaf[u] = true;
        continue;
      }
      for(int v:adj[u])
        if(!vis[v]){
          vis[v] = true;
          prob[v] = (1.0/total)*prob[u];
          dist[v] = 1 + dist[u];
          q.push(v);
        }
    }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve();

  ld ans = 0;

  for(int i=1;i<=n;i++){
    if(isLeaf[i])
      ans += dist[i]*prob[i];
  }

  cout << fixed << setprecision(9) << ans << endl;
 
  return 0;
}