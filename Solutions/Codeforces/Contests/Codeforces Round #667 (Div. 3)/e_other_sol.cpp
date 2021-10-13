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

vector <vi> dp;
vi pos;
int n,k;
const int INF = 1e9+7;

int solve(int i,int j){
  if(i == n || j == 0)
    return 0;

  int& state = dp[i][j];

  if(state != -1)
    return state;

  return state = max(solve(i+1,j), (pos[i]-i) + solve(pos[i],j-1));
}

int main(){
  fastio;
 
  int t = 1;
  cin >> t;
 
  while(t--){
    cin >> n >> k;

    dp.assign(n,vi(3,-1));
    
    vi x(n),y(n);
 
    for(int i=0;i<n;i++)
      cin >> x[i];
    
    for(int i=0;i<n;i++)
      cin >> y[i];
 
    sort(all(x));

    pos.resize(n);

    for(int i=0;i<n;i++){
      auto it = upper_bound(all(x),x[i] + k);
      it--;
      int j = it - x.begin();
      pos[i] = j+1;
    }

    cout << solve(0,2) << endl;
    
  }
 
  return 0;
}