#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int dist(pair <int,int> p1, pair <int,int> p2){
  return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int xa,ya,xb,yb;

  cin >> xa >> ya >> xb >> yb;

  int n;

  cin >> n;

  vector <pair <int,int > > p(n);
  vector <int> r(n);

  for(int i=0;i<n;i++)
    cin >> p[i].first >> p[i].second >> r[i];

  int menorx = xa > xb ? xb : xa;
  int maiorx = xa > xb ? xa : xb;
  int maiory = ya > yb ? ya : yb;
  int menory = ya > yb ? yb : ya;
  
  int ans = 0;
  
  for(int i=menorx;i<=maiorx;i++){
    bool need = true;
    for(int j=0;j<n;j++){
      if(dist({i,menory},p[j]) <= r[j]*r[j]){
        need = false;
        break;
      }
    }
    if(need)
      ans++;
  }

  for(int i=menorx;i<=maiorx;i++){
    bool need = true;
    for(int j=0;j<n;j++){
      if(dist({i,maiory},p[j]) <= r[j]*r[j]){
        need = false;
        break;
      }
    }
    if(need)
      ans++;
  }

  for(int i=menory+1;i<maiory;i++){
    bool need = true;
    for(int j=0;j<n;j++){
      if(dist({menorx,i},p[j]) <= r[j]*r[j]){
        need = false;
        break;
      }
    }
    if(need)
      ans++;
  }

  for(int i=menory+1;i<maiory;i++){
    bool need = true;
    for(int j=0;j<n;j++){
      if(dist({maiorx,i},p[j]) <= r[j]*r[j]){
        need = false;
        break;
      }
    }
    if(need)
      ans++;
  }

  cout << ans << endl;
    

  return 0;
}