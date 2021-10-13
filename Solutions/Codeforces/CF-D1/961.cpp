#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const ld EPS = 1e-10;
int n;

typedef struct point{
  ll x,y;
  point(ll x=0,ll y=0):x(x),y(y){};
}Point;

typedef struct line{
  ld a,b,c;
  line(Point p1,Point p2){
    if(p1.x == p2.x){
            a = 1;
            b = 0;
            c = -p1.x;
          }else{
            a = -(ld)(p1.y - p2.y)/(p1.x - p2.x);
            b = 1;
            c = -(ld)(a * p1.x) - p1.y;
          }
  }
}Line;

bool liesOn(Line l,Point p){
  return (fabsl(l.a*p.x + l.b*p.y + l.c) < EPS);
}

bool solve(Point p1,Point p2,vector <Point>& p){
  Line l(p1,p2);

  vector <bool> vis(n,false);
  int cnt = 0;
  for(int i=0;i<n;i++)
    if(liesOn(l,p[i]))
      vis[i]=true,cnt++;
  if(n-cnt <= 1)
    return true;
  
  int i1,i2;
  for(int i=0;i<n;i++)
    if(!vis[i]){
      i1 = i;
      break;
    }
  for(int i=n-1;i>=0;i--)
    if(!vis[i]){
      i2 = i;
      break;
    }
  Line l2(p[i1],p[i2]);
  cnt = 0;
  for(int i=0;i<n;i++)
    if(liesOn(l,p[i]) || liesOn(l2,p[i]))
      cnt++;

  return cnt == n;
}

int main(){
  fastio;

  cin >> n;
  vector <Point> p(n);

  for(int i=0;i<n;i++){
    cin >> p[i].x >> p[i].y;
  }

  if(n <= 2){
    cout << "YES" << endl;
    return 0;
  }

  if(solve(p[0],p[1],p) || solve(p[0],p[2],p) || solve(p[1],p[2],p))
    cout << "YES" << endl;
  else
    cout << "NO" << endl; 
  return 0;
}