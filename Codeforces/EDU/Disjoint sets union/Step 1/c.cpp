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
vi xp;

int find(int x){
  return (x == parent[x]) ? x : find(parent[x]);
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
  xp[x] -= xp[y];
}

int get(int x){
  int ans = 0;
  while(x != parent[x])
    ans += xp[x], x = parent[x];
  ans += xp[x];
  return ans;
}

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  parent.resize(n+1);
  iota(all(parent),0);
  set_size.assign(n+1,1);
  xp.assign(n+1,0);

  while(m--){
    string op;
    cin >> op;
    if(op == "add"){
      int x,v;
      cin >> x >> v;
      xp[find(x)] += v;
    }else if(op == "join"){
      int x,y;
      cin >> x >> y;
      join(x,y);
    }else{
      int x;
      cin >> x;
      cout << get(x) << endl;
    }
    
  }
  return 0;
}