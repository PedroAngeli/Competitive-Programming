#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m;
  cin >> n >> m;
  
  queue <pair <int,int > > q;
  const int nax = 2e4 + 5;
  vector <bool> vis(nax,false);
  q.push({n,0});

  while(!q.empty()){
    int d = q.front().second;
    int u = q.front().first;
    vis[u] = true;

    q.pop();

    if(u == m){
      cout << d << endl;
      return 0;
    }

    if(u*2 <= nax && !vis[u*2])
      q.push({u*2,d+1});

    if(u-1 > 0 && !vis[u-1])
      q.push({u-1,d+1});
  }
  
  return 0;
}