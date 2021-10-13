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

int n,m;
vector <vector <string> > grid;
map <ii,vii> adj;
vii topo;
vector <vector <bool> > vis;

ii getCoord(string a){
  int i = 0;
  int col = 0;
  if(a[0] == '=')
    i++;
  while(isalpha(a[i])){
    int dig = a[i]-'A'+1;
    col *= 26;
    col += dig; 
    i++;
  }
  int row = stoi(a.substr(i,a.size()-i));
  return {row,col};
}

vii getCells(string a){
  vii ret;
  int pos = 0;
  while(true){
    pos = a.find('+');
    if(pos == string::npos)
      break;
    string tmp = a.substr(0,pos);
    ii p = getCoord(tmp);
    ret.push_back(p);
    a.erase(a.begin(),a.begin()+pos+1);
  }

  ii p = getCoord(a);
  ret.push_back(p);

  return ret;
}

void findGraph(){
  for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(grid[i][j][0] == '='){
          vii cells = getCells(grid[i][j]);
          for(auto c:cells){
            if(grid[c.f][c.s][0] == '=')
              adj[c].push_back({i,j});
          }
        }
}

void findTopo(ii u){
  if(vis[u.f][u.s])
    return;
  vis[u.f][u.s] = true;

  for(auto v:adj[u]){
    findTopo(v);
  }
  topo.push_back(u);
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  
  while(t--){
    cin >> m >> n;
    grid.assign(n+1,vector <string>(m+1));
    topo.clear();
    adj.clear();
    vis.assign(n+1,vector <bool>(m+1,false));    

    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        cin >> grid[i][j];
    }

    vector <vi> ans(n+1,vi(m+1,0));
    
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(grid[i][j][0] != '=')
          ans[i][j] = stoi(grid[i][j]);

    findGraph();

    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
          if(grid[i][j][0] == '=')
          findTopo({i,j});
      }

    reverse(topo.begin(),topo.end());

    for(auto p:topo){
      vii cells = getCells(grid[p.f][p.s]);
       for(auto c:cells){
         ans[p.f][p.s] += ans[c.f][c.s];
       }
    }

    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        if(j == m)
          cout << ans[i][j] << endl;
        else
          cout << ans[i][j] << " ";
    }
  }
  

  return 0;
}