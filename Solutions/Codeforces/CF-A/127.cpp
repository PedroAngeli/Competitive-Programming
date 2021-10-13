#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

double dist(pair <int,int> p1, pair <int,int> p2){
  return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  double dt = 0;

  vector <pair <int,int> > points;

  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    points.push_back({a,b});
  }

  for(int i=1;i<n;i++){
    dt += dist(points[i],points[i-1]);
  }

  cout << fixed << setprecision(15) << (dt/50) * k << endl;


  return 0;
}