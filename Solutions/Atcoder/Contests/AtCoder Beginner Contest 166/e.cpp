#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  long long h[n+1];

  unordered_map <long long,long long> mp;

  for(int i=1;i<=n;i++){
    cin >> h[i];
    mp[i-h[i]]++;
  }

  long long ans = 0;

  for(int i=1;i<=n;i++){
    ans+=mp[h[i]+i]; 
  }

  cout << ans << endl;

  return 0;
}