#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
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

const int nax = 3e5 + 5;
vi adj[nax];
vi dp;
int n;

int solve(int i){
  if(i == n-1)
    return 0;
  
  int& state = dp[i];
  if(state != -1)
    return state;

  state = INT_MAX;

  for(int v : adj[i])
    state = min(state, 1 + solve(v));

  return state;
}

int main(){
  fastio;

  cin >> n;

  vi a(n);
  dp.assign(n,-1);

  for(int i=0;i<n;i++)
    cin >> a[i];

  for(int i=0;i<n-1;i++)
    adj[i].pb(i+1);
  
  stack <pii> p1;
  p1.push({a[0],0});
  //primeiro a esquerda que é maior ou igual ao atual
  for(int i=1;i<n;i++){
    while(!p1.empty() && p1.top().f < a[i])
      p1.pop();
    
    if(!p1.empty())
      adj[p1.top().s].pb(i);
    
    p1.push({a[i],i});
  }

  stack <pii> p2;
  p2.push({a[0],0});
  //primeiro a esquerda que é menor ou igual ao atual;
  for(int i=1;i<n;i++){
    while(!p2.empty() && p2.top().f > a[i])
      p2.pop();
    
    if(!p2.empty())
      adj[p2.top().s].pb(i);
    
    p2.push({a[i],i});
  }

  stack <pii> p3;
  p3.push({a[n-1],n-1});
  //primeiro a direita que é maior ou igual ao atual

  for(int i=n-2;i>=0;i--){
    while(!p3.empty() && p3.top().f < a[i])
      p3.pop();
    
    if(!p3.empty())
      adj[i].pb(p3.top().s);
    
    p3.push({a[i],i});
  }

  stack <pii> p4;
  p4.push({a[n-1],n-1});
  //primeiro a direita que é menor ou igual ao atual
  for(int i=n-2;i>=0;i--){
    while(!p4.empty() && p4.top().f > a[i])
      p4.pop();
    
    if(!p4.empty())
      adj[i].pb(p4.top().s);
    p4.push({a[i],i});
  }

  cout << solve(0) << endl;
  return 0;
}