#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;

  int ans = INT_MAX;

  for(int i=sqrt(n);i<=n;i++){
    for(int j=sqrt(n);j>=1;j--){
      if(i*j == n){
        int p = 2*i+2*j;
        ans = min(ans,p);
      }
    }
  }
  

  cout << ans << endl;
    
  return 0;
}