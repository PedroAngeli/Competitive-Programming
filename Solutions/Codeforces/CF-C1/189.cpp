#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);int n,a,b,c;
 
  cin >> n >> a >> b >> c;
 
  int ans = 0;

  for(int i=0;i<=4000;i++)
    for(int j=0;j<=4000;j++){
      int k = n - i*a - j*b;
      if(k >= 0 && k % c == 0)
        ans = max(ans,i+j+(k/c)); 
    }

    cout << ans << endl;
   
  return 0;
}