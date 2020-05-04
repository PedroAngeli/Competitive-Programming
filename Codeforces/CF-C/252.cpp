#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n,d;
  cin >> n >> d;

  long long x[n];
  
  for(int i=0;i<n;i++)
    cin >> x[i];

  long long ans = 0;

  for(int i=0;i<n;i++){
    int l = i;
    int r = n-1;
    int pos = 0;

    while(l <= r){
      int m = (l+r)/2;
    
      if(x[i]+d >= x[m])
        l = m+1,pos = max(pos,m);
      else
        r = m-1;
    }

    long long dif = pos - i;
    if(dif < 2)
      continue;
    
    ans += (dif*(dif-1))/2;
  }

  cout << ans << endl;

  return 0;
}