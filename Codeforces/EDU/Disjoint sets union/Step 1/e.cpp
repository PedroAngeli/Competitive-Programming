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

vi set_size;
vi parent;
vector <vi> child;
vi ans;

int find(int x){
  if(x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

void join(int x,int y,int t){
  if(x == -1 || y == -1)
    return;

  x = find(x);
  y = find(y);

  if(x == y)
    return;

  if(set_size[x] > set_size[y])
    swap(x,y);

  if(x == 1)
    swap(x,y);

  parent[x] = y;
  set_size[y] += set_size[x];
  
  child[y].pb(x);
  for(auto c:child[x])
    child[y].pb(c);
  
  if(y == 1){
    ans[x] = t;
    for(auto c:child[x])
      ans[c] = t;
  }
  
}

int main(){
  fastio;

  int n,m;
  cin >> n >> m;
  vector <vi> h1(n+1,vi(2));
  vector <vi> h2(n+1,vi(2));

  for(int i=1;i<=n;i++){
    cin >> h1[i][0] >> h1[i][1];
    h2[i] = h1[i];
  }
  
  vpii querys;

  while(m--){
    int monkey, hand;
    cin >> monkey >> hand;
    h1[monkey][hand-1] = -1;
    querys.pb({monkey,hand});
  }

  //build the final graph and see who didnt fall.
  //iterate over the querys in the reverse order and see in what time the monkey 
  //in the query is in the same component of monkey 1.

  parent.resize(n+1);
  iota(all(parent),0);
  set_size.assign(n+1,1);
  child.resize(n+1);
  ans.assign(n+1,-1);

  for(int i=1;i<=n;i++){
    join(i,h1[i][0],-1);
    join(i,h1[i][1],-1);
  }


  for(int i=sz(querys)-1;i>=0;i--){
    int p = querys[i].f;
    int h = querys[i].s;
    join(p,h2[p][h-1],i);

    // for(int i=1;i<=n;i++){
    //   cout << find(i) << ":";
    //   for(auto c:child[i])
    //     cout << " " << c;
    //   cout << endl;
    //   }
  }

  for(int i=1;i<=n;i++)
    cout << ans[i] << endl;

  return 0;
}