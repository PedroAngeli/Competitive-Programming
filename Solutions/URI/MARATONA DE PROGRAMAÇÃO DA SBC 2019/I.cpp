#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 401;
const int INF = 1e9 + 7;
int n;

struct Query{
  int i,a,b;
  Query(int a,int b,int i):a(a),b(b),i(i){}
};

int adj[nax][nax];
int dist[nax][nax];
vector<Query> querys[2][nax];


void find_rank(vector <vi>& Rank, vpii& T){
  int r = 1;
  Rank[r].pb(T[0].s);

  for(int i=1;i<n;i++){
    if(T[i].f == T[i-1].f) Rank[r].pb(T[i].s);
    else Rank[++r].pb(T[i].s);
  }
}

int main(){
  fastio;

  int r;
  cin >> n >> r;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      adj[i][j] = INF;

  vpii T(n);
  for(int i=0;i<n;i++){
    cin >> T[i].f;
    T[i].s = i+1;
  }

  vector <vi> Rank[2];
  Rank[0].resize(n+1);
  Rank[1].resize(n+1);

  sort(all(T));
  find_rank(Rank[0],T);
  reverse(all(T));
  find_rank(Rank[1],T);

  
  for(int i=0;i<r;i++){
    int u,v,w;
    cin >> u >> v >>w;
    adj[u][v] = min(adj[u][v], w);
    adj[v][u] = min(adj[v][u], w);
  }

  int q;
  cin >> q;
  for(int i=0;i<q;i++){
     int a, b, k, t;
    cin >> a >> b >> k >> t;
    Query q1(a,b,i);
    querys[t][k].pb(q1);
  }
  
  vi ans(q);

  for(int t=0;t<2;t++){
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        dist[i][j] = adj[i][j];

    for(int k=1;k<=n;k++){
      for(int u : Rank[t][k])
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][j]);

      for(Query q1 : querys[t][k])
        ans[q1.i] = dist[q1.a][q1.b];
    }
  }
    
  for(int i=0;i<q;i++){
    if(ans[i] == INF)
      ans[i] = -1;
    cout << ans[i] << endl;
    
  }

  return 0;
}