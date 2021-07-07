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



ll squared(ll x){
  return x*x;
}

ll dist(ll x1,ll x2){
  return squared(x1-x2);
}

int main(){
  fastio;
  int n,m;
  cin >> n >> m;
  vll col(n);
  vll row(m);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int x;
      cin >> x;
      col[i] += x;
      row[j] += x;
    }
  }

  vll sumX;
  sumX.assign(n+1,0);
  
  for(int i=0;i<=n;i++){
    for(int j=0;j<n;j++){
        sumX[i] += col[j]*dist(i*4,j*4+2);
    }
  }

  vll sumY;
  sumY.assign(m+1,0);

  for(int i=0;i<=m;i++){
    for(int j=0;j<m;j++){
      sumY[i] += row[j]*dist(i*4,j*4+2);
    }
  }

  ll ans = LLONG_MAX;
  int bestX = 0;
  int bestY = 0;

  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
      if(sumX[i] + sumY[j] < ans){
        ans = sumX[i] + sumY[j];
        bestX = i;
        bestY = j;
      }

  cout << ans << endl;
  cout << bestX << " " << bestY << endl;
    
  
  
  return 0;
}