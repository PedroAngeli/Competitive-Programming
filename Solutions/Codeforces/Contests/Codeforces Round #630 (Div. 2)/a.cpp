#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;

  while(t--){
    long long a,b,c,d;
    long long x,y,x1,y1,x2,y2;

    cin >> a >> b >> c >> d;

    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    long long sizea = x - x1;
    long long sizeb = x2 - x;
    
    bool canx = false;
    bool cany = false;

    if(a > b){
      long long dif = a-b;
      if(dif <= sizea && sizea){
        canx = true;
      }

    }else if(b > a){
      long long dif = b-a;
      if(dif <= sizeb && sizeb){
        canx = true;
      }
    }else{
      if(!a && !b)
        canx = true;
      else if(sizea || sizeb)
        canx = true;
    }

    long long sizec = y - y1;
    long long sized = y2 - y;

    if(c > d){
      long long dif = c-d;
      if(dif <= sizec && sizec){
        cany = true;
      }
    }else if(d > c){
      long long dif = d-c;
      if(dif <= sized && sized){
        cany = true;
      }
    }else{
      if(!d && !c)
        cany = true;
      else if(sizec || sized)
        cany = true;
    }

    if(canx && cany){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }   
  }
  
  return 0;
}