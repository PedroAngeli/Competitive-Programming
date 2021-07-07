#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
double d;
bool can(int r,int r1,int R1){
  return r+d <= r1 || r+R1 <= d || d+R1 <= r;
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int x1,y1,r1,R1,x2,y2,r2,R2;
  cin >> x1 >> y1 >> r1 >> R1;
  cin >> x2 >> y2 >> r2 >> R2;
  d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  int ans = 0;
  if(can(r1,r2,R2))
    ans++;
  if(can(R1,r2,R2))
    ans++;
  if(can(r2,r1,R1))
    ans++;
  if(can(R2,r1,R1))
    ans++;
 
  cout << ans << endl;
  
  
  return 0;
}