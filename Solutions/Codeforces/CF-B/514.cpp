#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

double a,b,c;
const int nax = 1e3 + 5;
bool dead[nax];
const double EPS = 1e-9;

void findAbc(pair <double,double> p1, pair <double,double> p2){
  if(fabs(p1.first - p2.first) < EPS){ 
        a = 1;
        b = 0;
        c = -p1.first;
      }else{
        a = -(p1.second - p2.second)/(p1.first - p2.first);
        b = 1;
        c = -(a * p1.first) - p1.second;
      }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double x,y;

  cin >> n >> x >> y;

  vector <pair <double,double > > p(n);

  for(int i=0;i<n;i++)
    cin >> p[i].first >> p[i].second;

  int ans = 0;

  for(int i=0;i<n;i++){
    if(!dead[i]){
      ans++;
      findAbc({x,y},p[i]);
      
      for(int j=0;j<n;j++){
        if(!dead[j] && fabs(a*p[j].first + b*p[j].second + c) < EPS){
          dead[j] = true;
        }
      }
    }
  }
      
  

  cout << ans << endl;

  return 0;
}