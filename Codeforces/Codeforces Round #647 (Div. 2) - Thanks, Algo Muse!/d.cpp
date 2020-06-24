#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 5e5 + 5;

vector <int> adj[nax];
vector <int> wanted[nax];
bool vis[nax];
int topics[nax];

bool can(int u,int w){
  vis[u] = true;

  set <int,greater<int> > s;
  
  for(int v: adj[u]){
    if(vis[v])
      s.insert(topics[v]);
  }
  auto it = s.begin();
  // cout << u << " " << w << " " << s.size() << " " << *it << endl;
  return s.size() == w-1 && *it == w-1; 
} 

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  
  while(t--){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
      cin >> topics[i];
      wanted[topics[i]].push_back(i);
    }

    vector <int> ans;
    bool flag = true;
    for(int i=1;i<=n;i++){
      for(int j=0;j<wanted[i].size();j++){
          if(can(wanted[i][j],i))
            ans.push_back(wanted[i][j]);
          else{
            flag = false;
            // break;
          }
      }
    }

    if(flag){
      for(int i=0;i<n;i++)
        cout << ans[i] << " ";
        cout << endl;
    }else{
      cout << -1 << endl;
    }
  }

  return 0;
}