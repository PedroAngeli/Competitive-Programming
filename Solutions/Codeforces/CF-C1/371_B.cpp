#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int pf[3] = {2,3,5};

long long gcd(long long a, long long b){
  if(b == 0)
    return a;

  return gcd(b,a%b);
}
int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;

  if(a == b){
    cout << 0 << endl;
    return 0;
  }

  long long mdc = gcd(a,b);

  int x1 = a/mdc;
  int x2 = b/mdc;
  int ans = 0;

  for(int i=0;i<3;i++){
    while(x1 % pf[i] == 0){
      x1 /= pf[i];
      ans++;
    }

    while(x2 % pf[i] == 0){
      x2 /= pf[i];
      ans++;
    }
  }

  if(x1 != 1 || x2 != 1)
    cout << -1 << endl;
  else
    cout << ans << endl;



  return 0;
}