#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int nax = 1e5 + 5;
vector <int> adj[nax]; 
vector <long long> s;
vector <long long> a;
bool can;

void solve(int u,long long cur){
  if(adj[u].size() == 0){
    if(s[u] == -1)
      a[u] = 0;
    else
      a[u] = s[u]-cur;
    return;
  }

  if(s[u] == -1){
    long long mn = INT_MAX;
    for(int v:adj[u]){
      mn = min(mn,s[v]);
    }
    if(mn < cur){
      can = false;
      return;
    }
    a[u] = mn-cur;
    for(int v:adj[u]){
      solve(v,cur+a[u]);
    }
  }else{
    if(u!=1)
      a[u] = s[u]-cur;
    for(int v:adj[u])
    if(u!=1)
      solve(v,a[u]+cur);
    else
      solve(v,cur);
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;

  for(int i=2;i<=n;i++){
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  s.assign(n+1,0);
  a.assign(n+1,0);

  for(int i=1;i<=n;i++)
    cin >> s[i];

  a[1] = s[1];
  can = true;
  solve(1,s[1]);

  if(!can){
    cout << -1 << endl;
    return 0;
  }

  long long ans = 0;

  for(int i=1;i<=n;i++){
    ans+=a[i];
  }

  cout << ans << endl;
  return 0;
}