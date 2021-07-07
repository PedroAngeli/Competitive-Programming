#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for(int i=1;i<=n;i++){
    int cnt = 0;
    for(int x=1;x<=100;x++){
      for(int y=1;y<=100;y++){
        int val = i-x*x-y*y-x*y;
        int delta = (x+y)*(x+y) + 4*val;
        if(delta < 0)
          continue;
        int root = sqrt(delta);
        if(root*root != delta)
          continue;
        int z = (-(x+y) + root);
        if(z%2 || z <= 0)
          continue;
        cnt++;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}