#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

typedef struct point Point;
struct point{
  int x,y;
  point(int x=0,int y=0): x(x),y(y) {}
  point operator-(point other){
    return point(x-other.x,y-other.y);
  }
};

typedef struct vec Vec;
struct vec{
  Point p;
  vec(Point p1,Point p2){
    p = p2-p1;
  }
  double dotProduct(vec other){
    return p.x*other.p.x + p.y*other.p.y;
  }
  double norm(){
    return sqrt(p.x*p.x + p.y*p.y);
  }
  double angle(vec other){
    double a = (acos(dotProduct(other)/(norm()*other.norm()))*180)/acos(-1);
    if(other.p.y < 0) a = 360 - a;

    return a;
  }
};


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n;
  cin >> n;
  vector <Vec> vecs;
  int N = n;

  while(N--){
    int x,y;
    cin >> x >> y;
    vecs.push_back(Vec(Point(0,0),Point(x,y)));
  }
  
  Vec v(Point(0,0),Point(1,0));

  sort(vecs.begin(),vecs.end(),[&](auto v1,auto v2){
    double a1 = v.angle(v1);

    double a2 = v.angle(v2);
    
    return a1 < a2;
  });

  double ans = 360;

  for(int i=0;i<n-1;i++){
    ans = min(ans,360 - abs(v.angle(vecs[i]) - v.angle(vecs[i+1])));
  }
  
  ans = min(ans,abs(v.angle(vecs[0]) - v.angle(vecs[n-1])));

  cout << fixed << setprecision(15) << ans << endl;

 

  return 0;
}