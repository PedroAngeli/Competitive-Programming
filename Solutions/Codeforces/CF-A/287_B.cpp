#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long INF = 1e18;
long long n,k;

bool can(long long m){

  if(m == 1)
    return k >= n;
  
  if(m == 2)
    return (k-1)*2 >= n;

  long long ans = ((k-m+k-1)*m)/2 + 1;

  return ans >= n;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  long long l = 0;
  long long r = k-1;
  long long ans = INF;

  while(l <= r){
    long long m = (l+r)/2;
    
    if(can(m)){
      ans = min(ans,m);
      r = m-1;
    }else{
      l = m+1;
    }
  }

  if(ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}