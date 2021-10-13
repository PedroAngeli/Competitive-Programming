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


vll dp;
vi pl;
vi pr;
const int INF = 1e9 + 7;

ll solve(int i){
  if(i < 0)
    return -INF;

  if(pl[i] == -1 && pr[i] == -1)
    return 0;

  ll& state = dp[i];
  if(state != -1)
    return state;
  
  return state = max(abs(i-pl[i]) + solve(pl[i]), abs(i-pr[i]) + solve(pr[i]));
}

int main(){
  fastio;

  int n;
  cin >> n;
  vi a(n);
  for(int i=0;i<n;i++)
    cin >> a[i];
  
  stack <pii> p;
  pr.assign(n,-1);
  pl.assign(n,-1);

  p.push({a[0],0});

  for(int i=1;i<n;i++){
    while(!p.empty() && a[i] > p.top().f)
      p.pop();

    if(!p.empty()){
      if(p.top().f == a[i])
        pl[i] = pl[p.top().s];
      else
        pl[i] = p.top().s;
    }

    if(p.empty())
      p.push({a[i],i});
    else if(p.top().f != a[i])
      p.push({a[i],i});

  }

  while(!p.empty())
    p.pop();
  
  p.push({a[n-1],n-1});

  for(int i=n-2;i>=0;i--){
    while(!p.empty() && a[i] > p.top().f)
      p.pop();

    if(!p.empty()){
      if(p.top().f == a[i])
        pr[i] = pr[p.top().s];
      else
        pr[i] = p.top().s;
    }

    if(p.empty())
      p.push({a[i],i});
    else if(p.top().f != a[i])
      p.push({a[i],i});
  }
  dp.assign(n,-1);

  for(int i=0;i<n;i++){
    cout << solve(i) << " ";
  }
  cout << endl;

  return 0;
}