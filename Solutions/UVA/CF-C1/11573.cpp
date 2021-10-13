#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
const int INF = 1e9 + 7;
vector <string> mat;
vector <vector <int> > dist;

bool valid(int i,int j){
  return i>=0 && i < n && j >=0 && j < m;
}

int bfs(int s1,int s2,int d1,int d2){
  vector <pair<int,int> > mov = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
  dist.assign(n,vector <int>(m,INF));

  deque <pair <int,int> > q;
  dist[s1][s2] = 0;
  q.push_front({s1,s2});

  while(!q.empty()){
    pair <int,int> u = q.front();
    q.pop_front();

    int curIdx = mat[u.first][u.second]-'0';  

    for(int i=0;i<8;i++){
      int w = curIdx == i ? 0 : 1;
      int v1 = mov[i].first + u.first;
      int v2 = mov[i].second + u.second;

      if(!valid(v1,v2))
        continue;

      if(dist[v1][v2] > w + dist[u.first][u.second]){
        dist[v1][v2] = dist[u.first][u.second] + w;
        if(w == 1)
          q.push_back({v1,v2});
        else
          q.push_front({v1,v2});
      }
    }
  }

  return dist[d1][d2];
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  mat.resize(n);

  for(int i=0;i<n;i++)
    cin >> mat[i];

  int q;
  cin >> q;
  while(q--){
    int s1,s2,d1,d2;
    cin >> s1 >> s2 >> d1 >> d2;
    s1--,s2--,d1--,d2--;
  
    cout << bfs(s1,s2,d1,d2) << endl;
  }
  

  return 0;
}