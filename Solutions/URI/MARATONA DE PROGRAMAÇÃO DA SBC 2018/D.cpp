#include <bits/stdc++.h>


using namespace std;


int main(){

  int N;

  cin >> N;

  int ans = 0;

  while(N--){
    int a;
    cin >> a;
    if(a!=1)
      ans++;
  }

  cout << ans << endl;
  return 0;
}