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

vi adj[500];
vi matchA,matchB;
vector <bool> visB;

bool dfs(int u){
  for(int v:adj[u]){
    if(visB[v])
      continue;
    visB[v] = true;
    if(matchB[v] == -1 || dfs(matchB[v])){
      matchA[u] = v;
      matchB[v] = u;
      return true;
    }
  }

  return false;
}

int max_flow(int n,int m){
  matchA.assign(n,-1);  
  matchB.assign(m,-1);  
  bool flag = true;
  int ans = 0;

  while(flag){
    flag = false;
    visB.assign(m,false);
    for(int i=0;i<n;i++){
      if(matchA[i] != -1)
        continue;
      if(dfs(i)){
        ans++;
        flag = true;
      }
    }
  } 
  
  return ans;
}

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    int c,d,v;
    cin >> c >> d >> v;
    vector <pair<string,string> > cats;
    vector <pair<string,string> > dogs;
    for(int i=0;i<v;i++)
      adj[i].clear();
    for(int i=0;i<v;i++){
      string p1,p2;
      cin >> p1 >> p2;
      if(p1[0] == 'C')
        cats.pb({p1,p2});
      else
        dogs.pb({p1,p2});
    }

    int n = sz(cats);
    int m = sz(dogs);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(cats[i].f == dogs[j].s || cats[i].s == dogs[j].f)
          adj[i].pb(j);

    cout << v - max_flow(n,m) << endl;
  }


  return 0;
}