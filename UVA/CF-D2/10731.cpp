#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

const int nax = 30;
vi adj[nax];
vector <vi> components;
vi in_stack;
vi dfs_num;
vi dfs_low;
int dfs_counter;
stack <int> p;

void solve(int u){
  dfs_num[u] = dfs_low[u] = dfs_counter++;
  p.push(u);
  in_stack[u] = 1;

  for(int v : adj[u]){
    if(dfs_num[v] == -1){
      solve(v);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }else if(in_stack[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if(dfs_num[u] == dfs_low[u]){
    vi tmp;
    while(true){
      int v = p.top();
      tmp.pb(v);
      in_stack[v] = 0;
      p.pop();
      if(u == v)
        break;
    }
    components.pb(tmp);
  }
}

int main(){
  fastio;

  int n;
  int ncase = 0;
  while(cin >> n && n){
    int u = 1;
    if(ncase)
      cout << endl;
    ncase++;
    map <string,int> mp1;
    map <int,string> mp2;
    dfs_counter = 0;
    components.clear();
    for(int i=0;i<nax;i++)
      adj[i].clear();
    while(n--){
      vs options(5);

      for(int i=0;i<5;i++)
        cin >> options[i];

      string better;
      cin >> better;

      for(int i=0;i<5;i++){
        if(better == options[i])
          continue;
        if(!mp1.count(better))
          mp1[better] = u,mp2[u++] = better;
        if(!mp1.count(options[i]))
          mp1[options[i]] = u,mp2[u++] = options[i];
        int v = mp1[better];
        int w = mp1[options[i]];
        adj[v].pb(w);
      }
    }

    in_stack.assign(u,0);
    dfs_num.assign(u,-1);
    dfs_low.resize(u);

    for(int i=1;i<u;i++){
      if(dfs_num[i] == -1)
        solve(i);
    }
    vector <vs> ans;

    for(vi vet : components){
      vs tmp;
      for(int v : vet)
        tmp.pb(mp2[v]);
      sort(all(tmp));
      ans.pb(tmp);
    }

    sort(all(ans));
    for(auto a : ans)
      for(int i=0;i<sz(a);i++){
        cout << a[i];
        if(i == sz(a) - 1)
          cout << endl;
        else
          cout << " ";
      }
     
  }
  return 0;
}