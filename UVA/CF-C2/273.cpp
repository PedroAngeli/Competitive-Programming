#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

typedef struct point{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){};
}Point;

int orientation(Point a,Point b,Point c){
  int cross = (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);

  if(cross == 0)
    return 0;
  
  if(cross > 0)
    return 1;
  return 2;
}

bool beetween(Point p1, Point p, Point p2){
  return p.x >= min(p1.x,p2.x) && p.x <= max(p1.x,p2.x) && p.y >= min(p1.y,p2.y) && p.y <= max(p1.y,p2.y);
}

bool intersects(pair <Point,Point> p1, pair <Point,Point> p2){
  Point u1 = p1.first;
  Point u2 = p1.second;
  Point v1 = p2.first;
  Point v2 = p2.second;

  int o1 = orientation(u1,u2,v1);
  int o2 = orientation(u1,u2,v2);
  int o3 = orientation(v1,v2,u1);
  int o4 = orientation(v1,v2,u2);

  if(o1 != o2 && o3 != o4)
    return true;
  
  if(o1 == 0 && beetween(u1,v1,u2))
    return true;
  if(o2 == 0 && beetween(u1,v2,u2))
    return true;
  if(o3 == 0 && beetween(v1,u1,v2))
    return true;
  if(o4 == 0 && beetween(v1,u2,v2))
    return true;
  
  return false;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t;
  cin >> t;
  int test = 0;

  while(t--){
    if(test)
      cout << endl;
    test++;
    int n;
    cin >> n;
    vector <vector <int> > adj(n,vector <int>(n,0));
    vector <pair <Point,Point> > segments(n);

    for(int i=0;i<n;i++){
      cin >> segments[i].first.x >> segments[i].first.y >> segments[i].second.x >> segments[i].second.y;
      for(int j=i;j>=0;j--){
        if(intersects(segments[i],segments[j]))
          adj[i][j] = adj[j][i] = 1;
      }
    }

    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);

    int a,b;
    while(cin >> a >> b && a && b){
      a--,b--;
      if(adj[a][b])
        cout << "CONNECTED" << endl;
      else 
        cout << "NOT CONNECTED" << endl;
    }

  }

  return 0;
}