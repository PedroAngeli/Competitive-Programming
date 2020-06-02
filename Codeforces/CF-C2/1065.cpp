#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2e5 + 5;
long long cnt[nax];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n,k;
  cin >> n >> k;
  long long h[n];
  long long mn = INT_MAX;
  long long mx = 0;

  for(int i=0;i<n;i++){
    cin >> h[i];
    mn = min(mn,h[i]);
    mx = max(mx,h[i]);
    cnt[h[i]]++;
  }

  for(int i=mx-1;i>=1;i--)
    cnt[i] += cnt[i+1];

  long long x = mx;
  long long y = 0;
  int ans = 0;

  while(x > mn){
    if(cnt[x] + y <= k){
      y+=cnt[x];
      x--;
    }else{
      ans++;
      y = 0;
    }
  }

  if(y)
    ans++;

  cout << ans << endl;
  return 0;
}