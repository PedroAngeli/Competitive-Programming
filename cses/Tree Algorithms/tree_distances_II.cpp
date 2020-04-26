#include <bits/stdc++.h>

using namespace std;

const int nax = 2*1e5 + 5;
vector <int> adj[nax];
long long ans[nax];
long long qtdNaSub[nax];
long long n;
vector < pair <int,long long> > dfilho[nax];
long long somaDosFilhos[nax];

void solve(int u,int p){
  
  int filhos = 0;

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];

    if(v != p){
      solve(v,u);
      filhos += 1 + qtdNaSub[v];   
      somaDosFilhos[u] += 1 + qtdNaSub[v] + somaDosFilhos[v];
      dfilho[u].push_back({v,1 + qtdNaSub[v] + somaDosFilhos[v]});   
    }
  }

  qtdNaSub[u] = filhos;
}

void solve2(int u, int p, long long d){

  if(p != -1){
    ans[u] = somaDosFilhos[u] + (ans[p] - d) + (n - qtdNaSub[u] - 1);
  }else{
    ans[u] = somaDosFilhos[u];
  }

  for(int i = 0;i<dfilho[u].size();i++){
    int v = dfilho[u][i].first;
    long long dist = dfilho[u][i].second;
    solve2(v,u,dist);
  }
}

int main(){

  cin >> n;

  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  solve(1,-1);
  solve2(1,-1,0);

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";

  cout << endl;

  return 0;
}