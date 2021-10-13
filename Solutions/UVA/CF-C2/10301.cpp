#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

typedef struct{
  double x,y,r;
}Circle;

vector <int> parent;
vector <int> qtd;

bool intersects(Circle c1,Circle c2){
  double d = sqrt((c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y));
  return !(c1.r + c2.r <= d || c1.r+d <= c2.r || c2.r + d <= c1.r);
}

int find(int x){
  if(parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

int join(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y)
    return qtd[y];
  parent[x] = y;
  qtd[y] += qtd[x];
  return qtd[y];
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int n;

  while(cin >> n && n != -1){
    vector <Circle> circles(n);
    parent.resize(n);
    iota(parent.begin(),parent.end(),0);
    qtd.assign(n,1);

    for(int i=0;i<n;i++){
      cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int ans = n > 0 ? 1 : 0;

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(intersects(circles[i],circles[j])){
          ans = max(ans,join(i,j));
        }
      }
    }

    cout << "The largest component contains " << ans << " ring" << (ans > 1 || ans == 0 ? "s.\n" : ".\n");
  }

  
  return 0;
}