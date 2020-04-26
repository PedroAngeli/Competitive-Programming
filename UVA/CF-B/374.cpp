#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


long long solve(long long b,long long p,long long m){
  b = b%m;
  long long ans = 1;

  while(p > 0){
    if(p & 1){
      ans = (ans * b)%m;
    }

    b = (b*b)%m;
    p = p >> 1;
  }

  return ans;

}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  long long b,p,m;

  while(cin >> b >> p >> m){
    cout << solve(b,p,m) << endl;
  }
  
  return 0;
}