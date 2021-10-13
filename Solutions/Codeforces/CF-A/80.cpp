#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isPrime(int n){

  for(int i=2;i<n;i++)
    if(n % i == 0)
      return false;
  return true;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;

  int ans = 0;

  for(int i=n+1;i<100;i++){
    if(isPrime(i)){
      ans = i;
      break;
    }
  }

  if(ans == m)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}