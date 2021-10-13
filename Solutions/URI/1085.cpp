#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 5000;
const int INF = 1e9 + 7;
vector <pair <pii,char> > adj[nax];
map <string,int> mp;


int main(){
  fastio;

  int m;

  while(cin >> m){
    if(m == 0)
      break;
    
    mp.clear();
    string ori,dest;

    for(int i=0;i<nax;i++)
      adj[i].clear();

    cin >> ori >> dest;

    mp[ori] = 1;
    mp[dest] = 2;

    int idx = 3;

    for(int i=0;i<m;i++){
      string u,v;
      string word;
      cin >> u >> v >> word;

      if(!mp.count(u))
        mp[u] = idx++;
      if(!mp.count(v))
        mp[v] = idx++;

      int v1 = mp[u];
      int v2 = mp[v];
      int len = word.size();
      char ini = word[0];

      adj[v1].pb({{v2,len},ini});
      adj[v2].pb({{v1,len},ini});
    }

    vector <vi> dist(idx+10,vi(26,INF));

    set <pii> pq;
    pq.insert({0,mp[ori]});
    
    for(int i=0;i<26;i++)
      dist[mp[ori]][i] = 0;

    while(!pq.empty()){
      auto p = pq.begin();
      int u = p->s;
      pq.erase(p);

      for(auto e : adj[u]){
        int v = e.f.f;
        int w = e.f.s;
        int letter = e.s - 'a';
        bool update = false;

        for(int i=0;i<26;i++){
          if(letter == i)
            continue;
          if(dist[v][letter] > dist[u][i] + w){
            dist[v][letter] = dist[u][i] + w;
            update = true;
          }
        }
        if(update)
          pq.insert({dist[v][letter],v});
      }
    }

    int ans = INF;
    int u = mp[dest];

    for(int i=0;i<26;i++)
      ans = min(ans,dist[u][i]);

    if(ans == INF)
      cout << "impossivel" << endl;
    else
      cout << ans << endl;
  }

  return 0;
}