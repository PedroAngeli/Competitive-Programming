#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


typedef struct{
  long long x,y;
}Point;

typedef struct{
  long long r, x,y;
}Circle;

long long squared(long long x){
  return x*x;
}

bool intersects(Point p1,Point p2, Circle c){
  long long d1 = squared(p1.x-c.x)+squared(p1.y-c.y);
  long long d2 = squared(p2.x-c.x)+squared(p2.y-c.y);
  long long r = squared(c.r);

  if(d1 > r && d2 > r)
    return false;

  if(d1 < r && d2 < r)
    return false;


  return true;  
}


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m,k;
  cin >>  n >> m >> k;
  vector <Point> points(n);

  for(int i=0;i<n;i++)
    cin >> points[i].x >> points[i].y;

  vector <Circle> circles(m);

  for(int i=0;i<m;i++)
  cin >> circles[i].r >> circles[i].x >> circles[i].y;

  while(k--){
    int a,b;
    cin >> a >> b;
    a--,b--;
    
    int ans = 0;
    for(int i=0;i<m;i++){
      if(intersects(points[a],points[b],circles[i]))
        ans++;
    }

    cout << ans << endl;
  }
  return 0;
}