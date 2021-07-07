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

int n,c,t1,t2;
vi to_min;
vi to_max;
vi dp;

int solve(int i){
  if(i == n)
    return 0;

  int& state = dp[i];

  if(state != -1)
    return state;

  return state = min(t1 + solve(to_min[i]), t2 + solve(to_max[i]));
}

int main(){
  fastio;

  while(cin >> n >> c >> t1 >> t2){
    vi dist(n);
    if(t1 > t2)
      swap(t1,t2);

    to_min.assign(n,n);
    to_max.assign(n,n);

    for(int i=0;i<n;i++)
      cin >> dist[i];
    
    for(int i=0;i<n;i++){
      int j;
      for(j=i+1;j<n;j++){
        if(dist[j]-dist[i] > t1)
          break;
      }
      to_min[i] = j;
      for(j=i+1;j<n;j++){
        if(dist[j]-dist[i] > t2)
          break;
      }
      to_max[i] = j;
    }

    dp.assign(n,-1);

    cout << solve(0) << endl;
  }


  return 0;
}