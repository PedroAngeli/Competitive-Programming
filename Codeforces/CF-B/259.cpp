#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int a[10];

  for(int i=1;i<=9;i++)
    cin >> a[i];

  a[1] = (2*a[7]+a[8]-a[2])/2;
  a[5] = a[1]+a[2]+a[3]-a[4]-a[6];
  a[9] = a[3]+a[7]-a[1];

  for(int i=1;i<=9;i++){
    cout << a[i] << " ";
    if(i% 3 == 0)
      cout << endl;
  }

  


  return 0;
}