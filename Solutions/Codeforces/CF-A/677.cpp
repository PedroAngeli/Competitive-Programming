#include <bits/stdc++.h>

using namespace std;


int main(){

  int n,h;

  cin >> n >> h;

  int vet[n];
  int ans = 0;

  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if (a > h)
      ans+=2;
    else
      ans++;
  }

  cout << ans << endl;    

  

  return 0;
}