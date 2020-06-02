#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
int v,e;
const int nax = 105;
vector <pair <int,pair<int,int> > > edges;
int parent[nax];

int find(int x){
  if(x == parent[x])
    return x;
  return find(parent[x]);
}

void join(int x,int y){
  parent[find(x)] = find(y);
}

void solve(){
  for(int i=1;i<=v;i++)
    parent[i] = i;

  sort(edges.begin(),edges.end());
  vector <pair <pair<int,int>,pair<int,int> > > tree;

  for(int i=0;i<e;i++){
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int c = edges[i].first;
    if(find(u) != find(v)){
      join(u,v);
      tree.push_back({{c,i},{u,v}});
    }
  }

  if(tree.size() < v-1){
    cout << "No way" << endl;
    return;
  }

  int ans = INT_MAX;

  for(int i=0;i<tree.size();i++){
    for(int i=1;i<=v;i++)
      parent[i] = i;

    int curIdx = tree[i].first.second;
    int curCost = 0;
    int cnt = 0;

    for(int j=0;j<e;j++){
       int u = edges[j].second.first;
      int v = edges[j].second.second;
      int c = edges[j].first;
      if(j != curIdx && find(u) != find(v)){
        cnt++;
        join(u,v);
        curCost += c;
      }
    }
    if(cnt == v-1)
      ans = min(ans,curCost);
  }

  if(ans == INT_MAX)
    cout << "No second way" << endl;
  else
    cout << ans << endl;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t = 1;
  cin >> t;
  int ncase = 1;
  while(t--){
   cin >> v >> e;
   edges.resize(e);
   for(int i=0;i<e;i++)
    cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    cout << "Case #" << ncase++ << " : ";
    solve();
  }
  
  return 0;
}