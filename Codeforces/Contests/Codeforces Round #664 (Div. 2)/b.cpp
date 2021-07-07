#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

int n,m;
vpii ans;
vector <vector <bool> > vis;

void solve(int i,int j){
  if(i < 1 || i > n || j < 1 || j > m || vis[i][j])
    return;
  ans.push_back({i,j});
  vis[i][j] = true;
  for(int k=i+1;k<=n;k++)
    if(!vis[k][j])
      solve(k,j);
  for(int k=i-1;k>=1;k--)
    if(!vis[k][j])
      solve(k,j);
  for(int k=j+1;k<=m;k++)
    if(!vis[i][k])
      solve(i,k);
  for(int k=j-1;k>=1;k--)
    if(!vis[i][k])
      solve(i,k);
}

int main(){
  fastio;

  int t=1;
  // cin >> t;
  while(t--){
    int x,y;
    cin >> n >>  m>> x >> y;
    vis.assign(n+1,vector <bool>(m+1,false));
    solve(x,y);
    for(auto p:ans){
      cout << p.first << " " <<p.second << endl;
    }
  }
  return 0;
}