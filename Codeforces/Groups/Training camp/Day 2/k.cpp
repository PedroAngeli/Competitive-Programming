#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long x1,y1;
  long long x2,y2;

  cin >> x1 >> y1 >> x2 >> y2;

  int n;

  cin >> n;
  int ans = 0;

  for(int i=0;i<n;i++){
    long long a,b,c;
    cin >> a >> b >> c;
    long long s1 = a*x1 + b*y1 + c;
    long long s2 = a*x2 + b*y2 + c;
    if((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0))
      ans++;
  }

  cout << ans << endl;
  
  return 0;
}