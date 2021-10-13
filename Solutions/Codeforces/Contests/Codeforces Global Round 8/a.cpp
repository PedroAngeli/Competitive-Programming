#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t = 1;
  cin >> t;

  while(t--){
    long long a,b,n;
    cin >> a >> b >> n;
    int ans =0;

    while(a <= n && b <= n){
      if(a > b){
        b += a;
      }else{
        a += b;
      }
      ans++;
    }

    cout << ans << endl;
  }
 
  
  return 0;
}