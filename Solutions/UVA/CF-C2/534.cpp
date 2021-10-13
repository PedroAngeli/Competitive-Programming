#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int n;
  int test = 1;

  while(cin >> n && n){
    vector <vector <double> > dist(n,vector <double>(n));
    vector <pair <int,int> > points(n);

    for(int i=0;i<n;i++){
      cin >> points[i].first >> points[i].second;

      for(int j=i;j>=0;j--){
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[j].first;
        int y2 = points[j].second;
        dist[i][j] = dist[j][i] = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
      }
    }

    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          dist[i][j] = min(dist[i][j], max(dist[i][k],dist[k][j]));
        }
      }
    }

    cout << "Scenario #" << test++ << endl;
    cout << fixed << setprecision(3) << "Frog Distance = " << dist[0][1] << endl; 
    cout << endl;
  }

  return 0;
}