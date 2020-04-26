#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e3;
int parent[nax];
vector <pair <int,int> > vert;
vector <pair <int, pair<int,int> > > edges;

int Find(int x){
  if(parent[x] == x)
    return x;

  return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
  parent[Find(x)] = Find(y);
}

int dist(pair <int,int> p1, pair <int,int> p2){
  return ((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

void kruskal(){
  sort(edges.begin(),edges.end());
  vector <pair <int,int> > ans;

  for(int i=0;i<edges.size();i++){
    int v1 = edges[i].second.first;
    int v2 = edges[i].second.second;

    if(Find(v1) != Find(v2)){
      Union(v1,v2);
      ans.push_back({v1+1,v2+1});
    }
  }

  for(int i=0;i<ans.size();i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){

    int n;

    cin >> n;
    vert.resize(n);
    edges.clear();

    for(int i=0;i<n;i++){
      parent[i] = i;
      cin >> vert[i].first >> vert[i].second;
    }

    int m;
    cin >> m;

    while(m--){
      int a,b;
      cin >> a >> b;
      a--,b--;
      Union(a,b);
    }

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(Find(i) != Find(j)){
          edges.push_back({dist(vert[i],vert[j]),{i,j}});
        }
      }
    }


    if(edges.size() == 0){
      cout << "No new highways need" << endl;
    }else{
      kruskal();
    }

    if(t)
    cout << endl;
  }

  return 0;
}