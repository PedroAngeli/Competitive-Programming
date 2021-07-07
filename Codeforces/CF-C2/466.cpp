#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n;
  cin >> n;
  vector <long long> pref(n+1,0);
  unordered_map<long long,long long> mp;

  for(int i=1;i<=n;i++){
    long long x;
    cin >> x;
    pref[i] = x+pref[i-1];
    if(i > 1 && i < n)
      mp[pref[i]]++;
  }

  long long ans = 0;

  for(int i=2;i<=n-1;i++){
    long long v1 = 3*pref[i-1];
    if(pref[n] == v1){
      long long v2 = 2*pref[i-1];
      ans += min(mp[v2],n-i+0LL);
    }
  }

  cout << ans << endl;
 
  return 0;
}