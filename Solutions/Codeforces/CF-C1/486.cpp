#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,p;
  cin >> n >> p;
  p--;
  int mid = n/2;

  string s;
  cin >> s;

  if(p >= mid)
    p = n-p-1;

  int ans = 0;

  for(int i=0;i<mid;i++){
    int dist = abs(s[i]-s[n-i-1]);
    ans += min(dist, 26-dist);
  }

  int pu = -1;
  int pp = n;

  for(int i=0;i<mid;i++){
    if(s[i] != s[n-i-1]){
      pu = max(pu,i);
      pp = min(pp,i);
    }
  }
  
  if(pu != -1 && pp != n)
    ans += min(abs(pu-p)+abs(pu-pp),abs(p-pp)+abs(pu-pp));

  cout << ans << endl;

  return 0;
}