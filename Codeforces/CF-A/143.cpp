#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r1,r2;
  cin >> r1 >> r2;

  int c1,c2;
  cin >> c1 >> c2;

  int d1,d2;
  cin >> d1 >> d2;

  for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
      for(int k=1;k<=9;k++)
        for(int l=1;l<=9;l++){
          int n1 = i;
          int n2 = j;
          int n3 = k;
          int n4 = l;

          if(n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4)
            continue;

          if(n1 + n2 == r1 && n1 + n3 == c1 && n2 + n4 == c2 && n3 + n4 == r2 && n1 + n4 == d1 && n2 + n3 == d2){
            cout << n1 << " " << n2 << endl;
            cout << n3 << " " << n4 << endl;
            return 0;
          }
        }

  cout << -1 << endl;
  return 0;
}