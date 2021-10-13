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

const int nax = 2e5+5;
vi adj[nax];
vi ans;
vector <bool> vis;

void solve(int u,int val){
  vis[u] = true;
  ans[u] = val;

  for(int v:adj[u])
    if(!vis[v])
      solve(v,val);
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;
  while(t--){
    int n;
    string a;
    cin >> n >> a;

    for(int i=0;i<n;i++)
      adj[i].clear();

    vis.assign(n,false);
    ans.assign(n,0);

    vector <vi> pos(2);

    for(int i=0;i<n;i++)
      pos[a[i]-'0'].push_back(i);

    int pone = 0;
    int pzero = 0;

    for(int i=0;i<n;i++){
      if(a[i] == '0'){
        if(pone < pos[1].size()){
          adj[i].push_back(pos[1][pone]);
          adj[pos[1][pone]].push_back(i);
          pone++;
        }
        if(pzero < pos[0].size() && pos[0][pzero] == i)
          pzero++;
      }else{
        if(pzero < pos[0].size()){
          adj[i].push_back(pos[0][pzero]);
          adj[pos[0][pzero]].push_back(i);
          pzero++;
        }
        if(pone < pos[1].size() && pos[1][pone] == i)
          pone++;
      }
    }

    int cnt = 0;

    for(int i=0;i<n;i++){
      if(!vis[i])
        cnt++,solve(i,cnt);
    }

    cout << cnt << endl;
    for(int i=0;i<n;i++)
      cout << ans[i] << " ";
    cout << endl;
  }

  return 0;
}