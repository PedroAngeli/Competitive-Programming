#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int n;
  while(cin >> n && n){
    long long x,y,z,d;
    long long dx,dy,dz,px,py,pz;
    cin >> x >> y >> z >> d;
    n--;
    dx = x + d;
    dy = y + d;
    dz = z + d;
    px = x;
    py = y;
    pz = z;

    while(n--){
      cin >> x >> y >> z >> d;
      px = max(px,x);
      py = max(py,y);
      pz = max(pz,z);
      dx = min(dx,x+d);
      dy = min(dy,y+d);
      dz = min(dz,z+d);
    }
    
    cout << max(0LL,(dx-px)*(dy-py)*(dz-pz)) << endl;
  }
  
  return 0;
}