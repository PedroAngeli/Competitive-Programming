#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long x;

  while(cin >> x){
    long long ans = 0;

    for(long long i=1;i<=x;i++)
      ans += (i*i*i);
    
    cout << ans << endl;
  }
  
  
  return 0;
}