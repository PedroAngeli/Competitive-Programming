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

vi adj[101];
int n,m;
ld speed, seconds;
vi matchA, matchB;
vector <bool> visB;
vector <pair <ld,ld> > gophers;
vector <pair <ld,ld> > holes;
const ld EPS = 1e-9;

ld squared(ld x){
  return x*x;
}

ld dist(pair <ld,ld> p1, pair <ld,ld> p2){
  return sqrtl(squared(p1.f - p2.f) + squared(p1.s - p2.s));
}

ld get_time(ld dist){
  return dist/speed;
}

bool dfs(int u){
  for(int v:adj[u]){
    if(visB[v])
      continue;
    visB[v] = true;

    if(matchB[v] == -1 || dfs(matchB[v])){
      matchB[v] = u;
      matchA[u] = v;
      return true;
    }
  }

  return false;
}

int kuhn(){
  bool flag = true;
  int ans = 0;

  matchA.assign(n,-1);
  matchB.assign(m,-1);

  while(flag){
    visB.assign(m,false);
    flag = false;
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

  while(cin >> n >> m >> seconds >> speed){
    gophers.resize(n);
    holes.resize(m);
    for(int i=0;i<n;i++)
      adj[i].clear();
    
    for(int i=0;i<n;i++)
      cin >> gophers[i].f >> gophers[i].s;

    for(int i=0;i<m;i++)
      cin >> holes[i].f >> holes[i].s;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(get_time(dist(gophers[i],holes[j])) < seconds + EPS)
          adj[i].pb(j);

      cout << n - kuhn() << endl;
  }
  

  return 0;
}