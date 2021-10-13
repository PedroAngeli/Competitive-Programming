#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long xa,ya,xb,yb;
 
  cin >> xa >> ya >> xb >> yb;
 
  int n;
  cin >> n;
  int ans =0;
  while(n--){
    long long a,b,c;
    cin >> a >> b >> c;
    long long f = (a*xa+b*ya+c);
    long long s = (a*xb+b*yb+c);
      if(f < 0 && s > 0 || f > 0 && s < 0)
        ans++;
  }
 
  cout << ans << endl;
 
 
  return 0;
}