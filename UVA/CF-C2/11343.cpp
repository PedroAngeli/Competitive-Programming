#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef struct point{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){};
}Point;

bool onSegment(Point p,Point p1,Point p2){
  return p.x >= min(p1.x,p2.x) && p.x <= max(p1.x,p2.x) && p.y >= min(p1.y,p2.y) &&
  p.y <= max(p1.y,p2.y);
}

int orientation(Point a,Point b,Point c){
  int val = (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);

  if(val == 0)
    return 0;
  
  return val > 0 ? 1 : 2;
}

bool intersects(pair <Point,Point> pair1, pair<Point,Point> pair2){
  Point p1 = pair1.first;
  Point p2 = pair1.second;
  Point q1 = pair2.first;
  Point q2 = pair2.second;

  int o1 = orientation(p1,p2,q1);
  int o2 = orientation(p1,p2,q2);
  int o3 = orientation(q1,q2,p1);
  int o4 = orientation(q1,q2,p2);

  if(o1 != o2 && o3 != o4)
    return true;

  
  return (o1 == 0 && onSegment(q1,p1,p2)) || (o2 == 0 && onSegment(q2,p1,p2)) ||
  (o3 == 0 && onSegment(p1,q1,q2)) || (o4 == 0 && onSegment(p2,q1,q2));

}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector <pair <Point,Point> > segments(n);
    int ans = 0;

    for(int i=0;i<n;i++){
      cin >> segments[i].first.x >> segments[i].first.y >> segments[i].second.x >> segments[i].second.y;
    }

    for(int i=0;i<n;i++){
      bool cnt = false;
      for(int j=0;j<n;j++){
        if(i == j)
          continue;
        cnt = cnt || intersects(segments[i],segments[j]);
      }
      if(cnt == false)
        ans++;
    }

    cout << ans << endl;
  }
      
  return 0;
}