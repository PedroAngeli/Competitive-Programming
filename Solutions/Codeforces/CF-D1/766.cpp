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

map <string,int> mp;
vi parent;

int find(int x){
  if(x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

void join(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y)
    return;
  parent[x] = y;
}

int main(){
  fastio;

  int n,m,q;
  cin >> n >> m >> q;
  parent.resize(2*n);
  iota(all(parent),0);
  for(int i=0;i<n;i++){
    string a;
    cin >> a;
    mp[a] = i;
  }

  for(int i=0;i<m;i++){
    int rel;
    string a,b;
    cin >> rel >> a >> b;
    int u = mp[a];
    int v = mp[b];

    if(rel == 1){
      if(find(u) == find(v+n) || find(u+n) == find(v))
        cout << "NO" << endl;
      else{
        join(u,v);
        join(u+n,v+n);
        cout << "YES" << endl;
      }
    }else{
      if(find(u) == find(v) || find(u+n) == find(v+n))
        cout << "NO" << endl;
      else{
        join(u,v+n);
        join(u+n,v);
        cout << "YES" << endl;
      }
    }
  }

  while(q--){
    string a,b;
    cin >> a >> b;
    int u = mp[a];
    int v = mp[b];
    if(find(u) == find(v) || find(u+n) == find(v+n)){
      cout << 1 << endl;
    }else if(find(u) == find(v+n) || find(u+n) == find(v))
      cout << 2 << endl;
    else
      cout << 3 << endl;
  }
  
  return 0;
}