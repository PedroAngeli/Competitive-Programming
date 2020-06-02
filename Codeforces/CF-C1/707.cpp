#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin >> n;
 
  if(n <= 2)
    cout << -1 << endl;
  else if(n % 2 == 1){
    long long b = (n*n - 1)/2;
    long long c = b+1;
    cout << b << " " << c << endl;
  }else{
    long long b = ((n/2)*(n/2))-1;
    long long c = b+2;
    cout << b << " " << c << endl;
  }

  return 0;
}