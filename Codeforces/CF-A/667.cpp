#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const double PI = acos(-1);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int d,h,v,e;

  cin >> d >> h >> v >> e;

  double area = (PI*d*d)/4;
  double deltaH = v/area;

  if(deltaH > e){
    cout << "YES" << endl;
    cout << fixed << setprecision(15) << (double)h/(deltaH-e) << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;
}