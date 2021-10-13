#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    long long n,r;
    cin >> n >> r;
    long long ans;
    if(n > r){
      ans = ((1+r)*r)/2;
    }else{
      n--;
      ans = ((1+n)*n)/2;
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}