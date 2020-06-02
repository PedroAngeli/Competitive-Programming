#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool inside(int x, int y ,int xc,int r){
  return ((x-xc)*(x-xc))+y*y <= r*r;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector <pair<pair <int,int>, int> > circle(n);
  vector <int> ans(n,-1);

  for(int i=0;i<n;i++)
    cin >> circle[i].first.first >> circle[i].first.second, circle[i].second = i;

  sort(circle.begin(),circle.end());

  int m;
  cin >> m;

  int shot = 1;
  int right = 0;

  while(m--){
    int x,y;
    cin >> x >> y;

    int l = 0;
    int r = n-1;
    int i = 0;
    int mid = -1;

    while(l <= r){
      mid = (l+r)/2;
      int radius = circle[mid].first.second;
      int xc = circle[mid].first.first;
      int lower = xc - radius;
      int upper = xc + radius;
      i = circle[mid].second;
  
      if(x >= lower && x <= upper){
        if(inside(x,y,xc,radius) && ans[i] == -1){
          ans[i] = shot;
          right++;
          break;
        }else
          break;
      }else if(x > upper){
        l = mid+1;
      }else if(x < lower){
        r = mid-1;
      }
    }

    if(mid > 0 && inside(x,y,circle[mid-1].first.first,circle[mid-1].first.second) && ans[circle[mid-1].second] == -1)
      ans[circle[mid-1].second] = shot,right++;
    if(mid < n-1 && inside(x,y,circle[mid+1].first.first,circle[mid+1].first.second) && ans[circle[mid+1].second] == -1)
      ans[circle[mid+1].second] = shot,right++;
      
    shot++;
  }
  
  cout << right << endl;

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}