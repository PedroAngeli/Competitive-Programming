#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    long long n,k;
    cin >> n >> k;
    set <long long> div;
    for(long long i=1;i*i<=n;i++)
      if(n % i == 0)
        div.insert(i),div.insert(n/i);
    
    long long ans = 1e18;
    for(auto it=div.begin();it!=div.end();it++){
      long long cur = *it;
      long long res = n/cur;
      if(cur <= k)
        ans = min(ans,res);
    }

    cout << ans << endl;
  }

  return 0;
}