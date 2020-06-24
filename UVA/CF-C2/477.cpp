#include <bits/stdc++.h>

using namespace std;

double const EPS = 1e-9;

typedef struct point Point;
struct point{
  double x,y;
  point(double x,double y): x(x), y(y) {};
};

typedef struct rec Rec;
struct rec{
  Point p1,p2;
  rec(point p1,point p2): p1(p1), p2(p2){};
};

typedef struct circle Circle;
struct circle{
  Point center;
  double radius;
  circle(Point center, double radius): center(center), radius(radius){};
};

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  vector <pair <Rec,int > > rectangles;
  vector <pair <Circle,int > > circles;

  int figure = 1;

  while(cin >> c && c != '*'){
    if(c == 'r'){
      Point p1(0,0), p2(0,0);
      cin >> p1.x >> p1.y >> p2.x >> p2.y;
      rectangles.push_back({Rec(p1,p2), figure++});
    }else{
      Point center(0,0);
      double radius;
      cin >> center.x >> center.y >> radius;
      circles.push_back({Circle(center,radius),figure++});
    }
  }

  double x,y;
  int p = 1;

  while(cin >> x >> y){
    if(fabs(x-9999.9) < EPS && fabs(y-9999.9) < EPS)
      break;

    bool contain = false;

    for(int i=0;i<rectangles.size();i++){
      Rec cur = rectangles[i].first;
      int idx = rectangles[i].second;

      if(x > min(cur.p1.x,cur.p2.x) && x < max(cur.p1.x,cur.p2.x) && y > min(cur.p1.y, cur.p2.y) && y < max(cur.p1.y,cur.p2.y)){
        contain = true;
        cout << "Point " << p << " is contained in figure " << idx << endl;
      }
    }

    for(int i=0;i<circles.size();i++){
      Circle cur = circles[i].first;
      int idx = circles[i].second;

      if((x-cur.center.x)*(x-cur.center.x) + (y-cur.center.y)*(y-cur.center.y) < cur.radius * cur.radius){
        contain = true;
        cout << "Point " << p << " is contained in figure " << idx << endl;
      }
    }

    if(!contain)
      cout << "Point " << p << " is not contained in any figure" << endl;


    p++;
  }

 

  return 0;
}