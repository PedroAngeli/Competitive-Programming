#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

unordered_map <string, int> mapa;
vector <pair <int, pair<int,int> > > edges;
const int nax = 2*1e3 + 5;

int parent[nax];

int Find(int x){
  if(parent[x] == x)
    return x;

  return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
  parent[Find(x)] = Find(y);
}

int Kruskal(){
  sort(edges.begin(),edges.end());

  int n = edges.size();
  int cost = 0;

  for(int i=0;i<n;i++){
    int p = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if(Find(u) != Find(v)){
      Union(u,v);
      cost += p;
    }
  }

  return cost;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;

  while(t--){
    mapa.clear();
    edges.clear();

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
      parent[i] = i;

    int m;
    int index = 0;

    cin >> m;

    while(m--){
      string a,b;
      int c;
      cin >> a >> b >> c;

      if(!mapa.count(a))
        mapa[a] = index++;

      if(!mapa.count(b))
        mapa[b] = index++;

      int u = mapa[a];
      int v = mapa[b];

      edges.push_back({c,{u,v}});
    }

    cout << Kruskal() << endl;

    if(t)
      cout << endl;
  }
  return 0;
}