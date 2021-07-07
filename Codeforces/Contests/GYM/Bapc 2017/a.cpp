#include <bits/stdc++.h>

using namespace std;

double PI = acos(-1);

int main(){

  double m,n;
  double r;

  cin >> m >> n >> r;

  double ax,ay,bx,by;

  cin >> ax >> ay >> bx >> by;

  double angle = 180/m;
  double ans;
  
  ans = min(ay*(r/n) + by*(r/n),(r/n)*fabs(ay-by) + (angle/360)*fabs(bx-ax)*2*PI*((r/n)*min(ay,by)));
  

  cout << fixed << setprecision(15) << ans << endl;
  
  return 0;
}