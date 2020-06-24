#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

typedef struct point Point;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator+(point other){
    return point(x+other.x,y+other.y);
  }
  point operator-(point other){
    return point(x-other.x,y-other.y);
  }
  point operator*(double value){
    return point(x*value,y*value);
  }
};

typedef struct line Line;
struct line{
  double a,b,c;
  line(Point p1, Point p2){
    if(fabs(p1.x-p2.x)<EPS){
      a = 1;
      b = 0;
      c = -p1.x;
    }else{
      a = -(p1.y-p2.y)/(p1.x-p2.x);
      b = 1;
      c = -(a*p1.x) - p1.y;
    }
  }
};

point findCenter(point m1,point end1, point m2, point end2){
  Line l1(m1,end1);
  Line l2(m2,end2);
  double x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a * l2.b);
  double y;
  if(fabs(l1.b) > EPS)
    y = -(l1.a * x + l1.c);
  else
    y = -(l2.a * x + l2.c);
  
  return point(x,y);
}

double dist(point p1, point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double findRadius(Point p1,Point p2, Point p3){
  point m1 = (p1+p2)*0.5;
  point v1 = p1-p2;
  point pv1 = point(v1.y,-v1.x);
  point end1 = m1+pv1;
  point m2 = (p2+p3)*0.5;
  point v2 = p2-p3;
  point pv2 = point(v2.y,-v2.x);
  point end2 = m2+pv2;

  point center = findCenter(m1,end1,m2,end2);
  double r = dist(center,p1);

  return r;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  Point p1,p2,p3;

  while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y){
    double r = findRadius(p1,p2,p3);
    double ans = 2*PI*r;
    cout << fixed << setprecision(2) << ans << endl;
  }

 

  return 0;
}