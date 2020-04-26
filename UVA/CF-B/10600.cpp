#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e2 + 5;
int parent[nax];
vector <pair <int, pair<int,int> > > edges;
int n,m;
const int INF = 1e9 + 7;

void init(){
   for(int i=0;i<n;i++)
      parent[i] = i;
}

int Find(int x){
  if(x == parent[x])
    return x;
  
  return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
  parent[Find(x)] = Find(y);
}

void kruskal(){
  sort(edges.begin(),edges.end());

  int mst_cost = 0;
  int second_best = INF;

  int tam = edges.size();
  vector <int> idx;
  
  for(int i=0;i<tam;i++){
    int v1 = edges[i].second.first;
    int v2 = edges[i].second.second;
    int w = edges[i].first;

    if(Find(v1) != Find(v2)){
      Union(v1,v2);
      mst_cost += w;
      idx.push_back(i);
    }
  }

  cout << mst_cost << " ";

  for(int i=0;i<idx.size();i++){
    init();
    int cost = 0;
    int cnt = 0;

    for(int j=0;j<tam;j++){
      if(idx[i] == j)
        continue;
       int v1 = edges[j].second.first;
       int v2 = edges[j].second.second;
       int w = edges[j].first;
      if(Find(v1) != Find(v2)){
        cost += w;
        Union(v1,v2);
        cnt++;
      }
    }
    if(cnt == idx.size())
    second_best = min(second_best,cost);
  }

  cout << second_best << endl;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;

  while(t--){
    cin >> n >> m;

    init();
    edges.clear();

    while(m--){
      int a,b,c;
      cin >> a >> b >> c;
      a--,b--;
      edges.push_back({c,{a,b}});
    }

    kruskal();
  }

  return 0;
}