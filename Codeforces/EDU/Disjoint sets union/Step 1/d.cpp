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

vi parent;
vi set_size;

int find(int x){
  return parent[x] = (x == parent[x]) ? x : find(parent[x]);
}

void join(int x,int y){
  x = find(x);
  y = find(y);

  if(x == y)
    return;
  
  if(set_size[x] > set_size[y])
    swap(x,y);
  
  parent[x] = y;
  set_size[y] += set_size[x];
}

int main(){
  fastio;

  int n,m,k;
  cin >> n >> m >> k;

  parent.resize(n+1);
  iota(all(parent),0);
  set_size.assign(n+1,1);

  while(m--){
    int u,v;
    cin >> u >> v;
  }

  vs querys(k);
  string tmp;
  getline(cin,tmp);

  for(int i=0;i<k;i++)
    getline(cin,querys[i]);

  reverse(all(querys));

  vs ans;

  for(int i=0;i<k;i++){
    string op;
    int u,v;
    stringstream ss(querys[i]);
    ss >> op >> u >> v;
    if(op == "ask"){
      if(find(u) == find(v))
        ans.pb("YES");
      else
        ans.pb("NO");
    }else
      join(u,v);
  }

  reverse(all(ans));
  for(string a:ans)
    cout << a << endl;
  return 0;
}