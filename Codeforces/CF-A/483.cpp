#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long gcd(long long a, long long b){
  if(b == 0)
    return a;

  return gcd(b,a%b);
}
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long l,r;

  cin >> l >> r;

  for(long long a = l;a <= r-2;a++){
    for(long long b = a+1;b <= r-1 ; b++){
      for(long long c = b+1;c <= r;c++ ){
        long long mmc1 = gcd(a,b);
        long long mmc2 = gcd(b,c);
        long long mmc3 = gcd(a,c);

        if(mmc1 == 1 && mmc2 == 1 && mmc3 != 1){
          cout << a << " " << b << " " << c << endl;
          return 0;
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}