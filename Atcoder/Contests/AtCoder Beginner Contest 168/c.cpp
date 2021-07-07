#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int a,b,h,m;

  cin >> a >> b >> h >> m;

  double aAngle = h*30 + (double)m/60 * 30;
  double bAngle = m*6;
  double dif = abs(aAngle-bAngle);
  double angle = min(dif,360-dif)/180 * acos(-1);
  cout << fixed << setprecision(15) << sqrt(a*a + b*b - 2*a*b*cos(angle)) << endl;
  

  return 0;
}