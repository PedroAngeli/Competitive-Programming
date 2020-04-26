#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const double EPS = 1e-9;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  cout << "INTERSECTING LINES OUTPUT" << endl;

  while(n--){
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double a1,b1,c1;
    if(fabs(x1-x2) < EPS){
      a1 = 1;
      b1 = 0;
      c1 = -x1;
    }else{
      b1 = 1;
      a1 = (y1-y2)/(x2-x1);
      c1 = -a1*x1 - y1;
    }

    double x3,y3,x4,y4;
    cin >> x3 >> y3 >> x4 >> y4;
    double a2,b2,c2;

    if(fabs(x3-x4) < EPS){
      a2 = 1;
      b2 = 0;
      c2 = -x3;
    }else{
      b2 = 1;
      a2 = (y3-y4)/(x4-x3);
      c2 = -a2*x3 - y3;
    }

    if(fabs(a1-a2) < EPS && fabs(b1-b2) < EPS){
      if(fabs(c1-c2) < EPS)
        cout << "LINE" << endl;
      else
        cout << "NONE" << endl;
    }else{
      cout << "POINT ";
      
      double y = (a2*c1-c2*a1)/(b2*a1-a2*b1);
      double x;

      if(fabs(a1) < EPS)
        x = (-b2*y-c2)/a2;
      else
        x = (-b1*y-c1)/a1;
      cout << fixed << setprecision(2) << x << " " << y << endl;
    }
  }

  cout << "END OF OUTPUT" << endl;

  return 0;
}