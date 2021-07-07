#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    long long ans = 0;
    long long mid = n/2;
    long long e = 8;

    for(long long i=1;i<=mid;i++){
      ans += e*i;
      e += 8; 
    }

    cout << ans << endl;
  }

  return 0;
}