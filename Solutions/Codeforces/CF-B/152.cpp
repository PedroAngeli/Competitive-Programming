#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n,m,x,y;

  cin >> n >> m >> x >> y;

  int k;

  cin >> k;

  long long ans = 0;

  while(k--){
    long long dx,dy;
    cin >> dx >> dy;
    long long tamx;
    long long tamy;

    if(dx < 0)
      tamx = x-1;
    else
      tamx = n-x;

    if(dy < 0)
      tamy = y-1;
    else
      tamy = m-y;

    long long stepx = 0,stepy = 0;

    if(dx == 0)
      stepy = abs(tamy/dy);
    else if(dy == 0)
      stepx = abs(tamx/dx);
    else
     stepx = stepy = min(abs(tamx/dx),abs(tamy/dy));

    y = stepy*dy + y;
    x = stepx*dx + x;

    ans += max(stepy,stepx);
    // cout << x << " " << y << endl;  
  }

  cout << ans << endl;
  return 0;
}