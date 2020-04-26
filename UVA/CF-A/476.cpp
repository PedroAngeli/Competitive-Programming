#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool contains(pair <double,double> p, pair <pair<double,double> , pair<double,double> > r){
  return p.first > r.first.first && p.first < r.second.first && p.second > r.second.second && p.second < r.first.second;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  char c = 'r';

  vector < pair <pair<double,double> , pair<double,double> > > ret;

  while(cin >> c && c == 'r'){
    double a,b,c,d;

    cin >> a >> b >> c >> d;

    ret.push_back({{a,b},{c,d}});
  }

  vector <pair <double,double> > points;

  double x,y;

  while(cin >> x >> y){
    points.push_back({x,y});
  }

  int n = points.size();
  int m = ret.size();

  for(int i=0;i<n-1;i++){
    bool any = false;

    for(int j=0;j<m;j++){
      if(contains(points[i],ret[j])){
        any = true;
        cout << "Point " << i+1 << " is contained in figure " << j+1 << endl;
        
      }
    }

    if(!any){
      cout << "Point " << i+1 << " is not contained in any figure" << endl;
    }
  }



  return 0; 
}