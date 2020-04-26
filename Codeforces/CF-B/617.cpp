#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long ans = 1;
  long long ant = -1;

  for(long long i=0;i<n;i++){
    int a;
    cin >> a;
    if(a == 1){
      if(ant != -1){
        ans *= (i - ant);
      }
      ant = i;
    }
  }

  if(ant == -1)
    ans = 0;
  
  cout << ans << endl;

  return 0;
}