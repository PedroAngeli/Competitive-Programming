#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

class Line{
  public:
  double a,b,c;
  Line(int x1,int y1,int x2,int y2){
    a = -(double)(y1-y2)/(x1-x2);
    b = 1;
    c = -(double)(a*x1) - y1;
  }
};

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,d;

  cin >> n >> d;

  Line* l1 = new Line(0,d,d,0);
  Line* l2 = new Line(n,n-d,n-d,n);
  Line* l3 = new Line(0,d,n-d,n);
  Line* l4 = new Line(n,n-d,d,0);
  
  int m;

  cin >> m;

  while(m--){
    double x,y;
    cin >> x >> y;

    double Y1 = -l1->a*x - l1->c;
    double Y2 = -l2->a*x - l2->c;
    double X1 = (-y-l3->c)/l3->a;
    double X2 = (-y-l4->c)/l4->a;

    if(Y1 <= y && y <= Y2 && X1 <= x && x <= X2)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
   
  }

  
  return 0;
}