#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


long long solve(long long n, long long m){
  long long ans = 1;
  long long a = 3;

  while(n > 0){
    if(n & 1){
      ans = (ans * a) % m;
    }

    a = (a * a)%m;
    n = n >> 1;
  }

  return ((ans-1)%m + m)%m;
}


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n,m;

  cin >> n >> m;

  cout << solve(n,m) << endl; 

  return 0;
}