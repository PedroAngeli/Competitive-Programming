#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const double PI = acos(-1);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int r1[n];

  for(int i=0;i<n;i++)
    cin >> r1[i];

  int m;
  cin >> m;

  int p1[m];

  for(int i=0;i<m;i++)
    cin >> p1[i];

  int k;
  cin >> k;

  int p2[k];

  for(int i=0;i<k;i++)
    cin >> p2[i];

  int A,B;
  cin >> A >> B;

  sort(p2,p2+k);
  sort(r1,r1+n);

  double r2 = 0;

  for(int i=0;i<m;i++)
    r2 = max(r2,sqrt((p1[i]*PI*r1[n-1]*r1[n-1]*B)/(p2[0]*PI*A + p1[i]*PI*B)));
  

  
  cout << fixed << setprecision(15) << r2 << endl;

  return 0;
}