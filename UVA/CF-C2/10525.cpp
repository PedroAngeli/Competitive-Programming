#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int nax = 1005;

long long adjDist[nax][nax];
long long adjTime[nax][nax];
const long long INF = 1e18;

void init(){
  for(int i=0;i<nax;i++)
    for(int j=0;j<nax;j++)
      adjDist[i][j] = adjTime[i][j] = INF;
}

pair <long long,long long> solve(int s,int d,int v){
  vector <long long> dist(v+1,INF);
  vector <long long> time(v+1,INF);

  set <pair<long long,int>> q;
  dist[s] = 0;
  time[s] = 0;
  q.insert({0,s});

  while(!q.empty()){
    auto it = q.begin();
    int u = it->second;
    q.erase(it);
    for(int i=0;i<nax;i++){
      if(adjTime[u][i] != INF){
        long long wt = adjTime[u][i];
        long long wd = adjDist[u][i];

        if(time[i] > time[u] + wt){
          time[i] = time[u] + wt;
          dist[i] = dist[u] + wd;
          q.insert({time[i],i});
        }else if(time[i] == time[u] + wt && dist[i] > dist[u] + wd){
          dist[i] = dist[u] + wd;
          q.insert({time[i],i});
        }
      }
    }
  }

  return {dist[d],time[d]};

}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t;
  cin >> t;

  for(int i=0;i<t;i++){
    if(i)
      cout << endl;
    init();
    int n,e;
    cin >> n >> e;
    while(e--){
      long long u,v,time,dist;
      cin >> u >> v >> time >> dist;
      if(adjTime[u][v] > time){
        adjDist[u][v] = dist;
        adjDist[v][u] = dist;
        adjTime[u][v] = time;
        adjTime[v][u] = time;
      }else if(time == adjTime[u][v] && adjDist[u][v] > dist){
        adjDist[u][v] = dist;
        adjDist[v][u] = dist;
        adjTime[u][v] = time;
        adjTime[v][u] = time;
      }
    }

    int q;
    cin >> q;

    while(q--){
      int u,v;
      cin >> u >> v;
      pair <long long,long long> ans = solve(u,v,n);
      if(ans.first == INF)
        cout << "No Path." << endl;
      else
        cout << "Distance and time to reach destination is " << ans.first << " & " << ans.second << "." << endl;
    }
  }

  return 0;
}