#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int p,q,l,r;

  cin >> p >> q >> l >> r;

  vector <pair <int,int> > z(p);

  for(int i=0;i<p;i++)
    cin >> z[i].first >> z[i].second;
  

  vector <pair <int,int> > x(q);

  for(int i=0;i<q;i++)
    cin >> x[i].first >> x[i].second;
  

  int ans = 0;

  for(int i=l;i<=r;i++){
    for(int j=0;j<q;j++){
      int a = x[j].first + i;
      int b = x[j].second + i;

      bool flag = false;

      for(int k=0;k<p;k++){
        int c = z[k].first;
        int d = z[k].second;
        if((c >= a && c <= b) || (d >= a && d <= b) || (c <= a && a <= d) || (b >= c && b <=d)){
          ans++;
          flag = true;
          break;
        }
      }

      if(flag)
        break;
    }
  }

  cout << ans << endl;

  return 0;
}