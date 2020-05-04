#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long a;
  cin >> n >> a;
  long long d[n];
  long long s = 0;

  for(int i=0;i<n;i++)
    cin >> d[i], s+=d[i];

  long long ans[n];

  for(int i=0;i<n;i++){
    long long mx = 0, mn = s;

    long long l = 1;
    long long r = d[i];

    while(l <= r){
      long long m = (l+r)/2;
  
      if(m + (n-1) <= a)
        l = m+1, mx = max(m,mx);
      else
        r = m-1;
    }

    l = 1;
    r = mx;

    while(l <= r){
      long long m = (l+r)/2;
      if(m + (s-d[i]) >= a)
        r = m-1,mn = min(m,mn);
      else
        l = m+1;
    }

    ans[i] = (mn - 1) + (d[i] - mx);
  }

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";

  cout << endl;

  return 0;
}