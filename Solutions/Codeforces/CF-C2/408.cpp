#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int a,b;
  cin >> a >> b;
  a*=a;
  b*=b;
  int c = a+b;
 
  int x1 = 0,y1 = 0;
  int x2 = 1, y2 = 1;
  bool findP2 = false;
  vector <pair <int,int> > cand;

  while(x2 <= 1000){
    y2 = 1;
    while(y2 <= 1000){
      if(y2*y2 + x2*x2 == a){
        findP2 = true;
        cand.push_back({x2,y2});
      }
      y2++;
    }
    x2++;
  }
 
  if(!findP2){
    cout << "NO" << endl;
    return 0;
  }
  int x3 = -1000, y3 = -1000;
  bool findP3 = false;

  while(x3 <= 1000){
    if(x3 == 0){
      x3++;
      continue;
    }
    y3 = -1000;
    while(y3 <= 1000){
      if(y3 == 0){
        y3++;
        continue;
      }
      for(int i=0;i<cand.size();i++){
        x2 = cand[i].first;
        y2 = cand[i].second;
        if(x2 == x3 || y3 == y2)
        continue;
         if(x3*x3 + y3*y3 == c && (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2) == b){
          findP3 = true;
          break;
        }
        if(x3*x3 + y3*y3 == b && (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2) == c){
          findP3 = true;
          break;
        }
      }

      if(findP3)
        break;

      y3++;
    }

    if(findP3)
      break;
    x3++;
  }
 
  if(!findP3){
    cout << "NO" << endl;
    return 0;
  }
 
  cout << "YES" << endl;
  cout << x1 << " " << y1 << endl;
  cout << x2 << " " << y2 << endl;
  cout << x3 << " " << y3 << endl;
 
  return 0;
}