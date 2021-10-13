#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;

  cin >> n >> m;
  set <int> adj[101];

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  int ans = 0;

  while(true){

    bool oneTie = false;

    vector <int> removed;

    for(int i=1;i<=n;i++){
      if(adj[i].size() == 1){
        oneTie = true;
        adj[i].clear();
        removed.push_back(i);
      }
    }

    for(int i=0;i<removed.size();i++)
      for(int j=1;j<=n;j++)
          if(adj[j].count(removed[i]))
            adj[j].erase(removed[i]);
        

    if(oneTie)
      ans++;
    else break;
  }

  cout << ans << endl;

  return 0;
}