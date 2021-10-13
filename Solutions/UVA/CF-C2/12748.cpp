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

typedef struct{
  int x,y,r;
}Circle;

int squared(int x){
  return x*x;
}

bool inside(int x,int y,Circle c){
  int dist = squared(x-c.x) + squared(y-c.y);
  return dist <= c.r*c.r; 
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  int test = 1;

  while(t--){
    cout << "Case " << test++ << ":\n";
    int n,m;
    cin >> n >> m;
    vector <Circle> circles(n);
    for(int i=0;i<n;i++)
      cin >> circles[i].x >> circles[i].y >> circles[i].r;
    while(m--){
      int x,y;
      cin >> x >> y;
      bool wifi = false;

      for(int i=0;i<n;i++){
        if(inside(x,y,circles[i]))
          wifi = true;
      }

      if(wifi)
        cout << "Yes" << endl;
      else 
        cout << "No" << endl;
    }
  }
 
  return 0;
}