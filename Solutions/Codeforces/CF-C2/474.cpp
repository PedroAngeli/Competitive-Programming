#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

const int INF = 1e9 + 7;

typedef struct{
  int x,y;
}Point;

typedef struct{
  Point p;
  Point q;
}Mole;

void rotate(Point &p,Point q,int times){
  for(int i=0;i<times;i++){
    p.x -= q.x;
    p.y -= q.y;
    swap(p.x,p.y);
    p.x *= -1;
    p.x += q.x;
    p.y += q.y;
  }
}

int squared(int x){
  return x*x;
}

int dist(Point p,Point q){
  return squared(p.x-q.x)+squared(p.y-q.y);
}
bool isSquare(Point p1,Point p2,Point p3,Point p4){
  int d2 = dist(p1,p2);
  int d3 = dist(p1,p3);
  int d4 = dist(p1,p4);

  if(d2 == 0 || d3 == 0 || d4 == 0)
    return false;
  
  return (d2 == d3 && 2*d2 == d4 && 2*dist(p2,p4) == dist(p2,p3)) ||
  (d3 == d4 && 2*d3 == d2 && 2*dist(p3,p2) == dist(p3,p4)) ||
  (d2 == d4 && 2*d2 == d3 && 2*dist(p2,p3) == dist(p2,p4));
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  while(n--){
    vector <Mole> moles(4);
    for(int i=0;i<4;i++)
      cin >> moles[i].p.x >> moles[i].p.y >> moles[i].q.x >> moles[i].q.y;
    int ans = INF;

    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        for(int k=0;k<4;k++)
          for(int l=0;l<4;l++){
            Point p1 = moles[0].p;
            rotate(p1,moles[0].q,i);

            Point p2 = moles[1].p;
            rotate(p2,moles[1].q,j);

            Point p3 = moles[2].p;
            rotate(p3,moles[2].q,k);

            Point p4 = moles[3].p;
            rotate(p4,moles[3].q,l);

            if(isSquare(p1,p2,p3,p4))
              ans = min(ans,i+j+k+l);
          }

    if(ans == INF)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}