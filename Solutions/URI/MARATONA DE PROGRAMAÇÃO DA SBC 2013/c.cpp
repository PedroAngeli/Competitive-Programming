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

const int nax = 501;
int n,m,I;
vi age;
vi adj[nax];
vi pos;
const int INF = 1e9 + 7;
int ans;
vector <bool> vis;

void solve(int u){
  vis[u] = true;
  for(int v:adj[u])
    if(!vis[v]){
      ans = min(ans,age[v]);
      solve(v);
    }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  while(cin >> n >> m >> I){
    age.resize(n+1);
    pos.resize(n+1);
    for(int i=1;i<=n;i++)
      adj[i].clear();

    for(int i=1;i<=n;i++)
      cin >> age[i],pos[i]=i;

    for(int i=0;i<m;i++){
      int u,v;
      cin >> u >> v;
      adj[v].push_back(u);
    }

    while(I--){
      char c;
      cin >> c;
      if(c == 'P'){
        int u;
        cin >> u;
        ans = INF;
        vis.assign(n+1,false);
        solve(pos[u]);

        if(ans == INF)
          cout << "*" << endl;
        else
          cout << ans << endl;
      }else{
        int u,v;
        cin >> u >> v;
        swap(age[pos[u]],age[pos[v]]);
        swap(pos[u],pos[v]);
      }
    }
  }  

  return 0;
}