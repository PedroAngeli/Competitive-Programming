#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

class Line{
  public:
  double a,b,c;
  double x1, y1,x2,y2;
  Line(int x1,int y1,int x2,int y2){
    if(x1 == x2){
      a = 1;
      b = 0;
      c = -x1;
    }else{
      a = -(double)(y1 - y2)/(x1-x2);
      b = 1;
      c = -(double)(a*x1) - y1;
    }
    if(x1 > x2)
      swap(x1,x2);
    if(y1 > y2)
      swap(y1,y2);
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
  }
};

bool parallel(Line* l1, Line* l2){
  return (fabs(l1->a - l2->a) < EPS) && (fabs(l1->b - l2->b) < EPS);
}

bool same(Line* l1, Line* l2){
  return parallel(l1,l2) && (fabs(l1->c - l2->c) < EPS);
}

bool intersects(Line* l1, Line* l2){
   if(same(l1,l2))
    return true;
  return !(parallel(l1,l2));
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  int ncase = 0;
  while(t--){
    if(ncase)
      cout << endl;
    ncase++;
    int n;
    cin >> n;
    vector <Line*> lines(n);
    for(int i=0;i<n;i++){
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      lines[i] = new Line(x1,y1,x2,y2);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
      int cnt = 1;
      for(int j=0;j<n;j++){
        if(i!= j && intersects(lines[i],lines[j])){
          Line* l1 = lines[i];
          Line* l2 = lines[j];
          double x = (l2->b*l1->c - l1->b*l2->c)/(l2->a*l1->b - l1->a * l2->b);
          double y;
          if(fabs(l1->b) > EPS)
            y = -(l1->a * x + l1->c);
          else
            y = -(l2->a * x + l2->c);
          
          if(x >= l1->x1 && x <= l1->x2 && y >= l1->y1 && y <= l1->y2 && x >= l2->x1 && x <= l2->x2 && y >= l2->y1 && y <= l2->y2)
            cnt++;
        }
      }
      ans += cnt;
    }
    cout << ans << endl;
  }

 

  return 0;
}