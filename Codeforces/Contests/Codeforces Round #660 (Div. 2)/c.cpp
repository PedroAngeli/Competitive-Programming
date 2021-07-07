#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

const int nax = 1e5 + 5;
vll people;
vll h;
vll visiters;
vll happy;
vi adj[nax];
int n,m;
const ll INF = 1e18;
bool can;

void solve(int u,int p){
  visiters[u] = people[u];
  int sum = 0;
  for(int v:adj[u])
    if(v != p){
      solve(v,u);
      visiters[u] += visiters[v];
      sum += happy[v];
    }
  
  happy[u] = (visiters[u]+h[u])/2;

  if(sum > happy[u] || visiters[u]%2 != abs(h[u])%2 || abs(h[u]) > visiters[u])
    can = false;
}



int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;
  
  while(t--){
    cin >> n >> m;
    people.resize(n+1);
    h.resize(n+1);
    visiters.assign(n+1,0);
    happy.assign(n+1,0);
    for(int i=1;i<=n;i++)
      adj[i].clear();

    for(int i=1;i<=n;i++)
      cin >> people[i];
    for(int i=1;i<=n;i++)
      cin >> h[i];

    for(int i=0;i<n-1;i++){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    can = true;
    solve(1,0);
    if(can)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
 
  return 0;
}