#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double vp,vd,t,f,c;

  cin >> vp >> vd >> t >> f >> c;

  double posp = vp*t;
  int ans = 0;

  if(vp >= vd){
    cout << 0 << endl;
    return 0;
  }

  while(true){
    if(posp >= c)
      break;

    double temp = posp/(vd-vp);
    double pd = temp*vd;
    
    if(pd >= c)
      break;

    ans++;
    posp = pd;
    posp += vp*f;
    posp += temp*vp;
  }


  cout << ans << endl;
  return 0;
}