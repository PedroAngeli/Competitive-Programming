#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

const int nax = 1e5 + 5;
const int INF = 1e9 + 7;
multiset <int> S1, S2; //S1.size == S2.size (even) S1.size == S2.size + 1
int n;
vector <int> adj[nax];
vector <int> A;
int dp[nax];

void balance(){
  if(S1.size()){
    auto it = S1.end();
    it--;
    S2.insert(*it);
    S1.erase(it);
  }
  while(S1.size() < S2.size()){
    auto it = S2.begin();
    S1.insert(*it);
    S2.erase(it);
  }
}

void erase(int x){
  if(S1.find(x) != S1.end())
    S1.erase(S1.find(x));
  else
    S2.erase(S2.find(x));
  balance();
}

int median(){
  if(S1.size() == S2.size())
    return (*(S1.rbegin()) + *(S2.begin()))/2;
  return *(S1.rbegin());
}

void dfs(int u = 1, int p = -1, int d = 0){
  S1.insert(A[u]);
  balance();

  if(d%2) dp[u] = INF;
  else dp[u] = 0;
  int c = 0;
  for(int v:adj[u]){
    if(v == p) continue;
    c++;
    dfs(v, u, d+1);
    if(d%2) dp[u] = min(dp[u], dp[v]);
    else dp[u] = max(dp[u], dp[v]);
  }
  if(c == 0)
    dp[u] = median();
  erase(A[u]);
}

int main(){
  fastio;

  cin >> n;
  A.resize(n+1);
  
  for(int i=1;i<=n;i++)
    cin >> A[i];

  for(int i=0;i<n-1;i++){
    int u, v;
    cin >>u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs();

  cout << dp[1] << endl;
  return 0;
}