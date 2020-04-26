#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long gcd(long long a, long long b){
  if(b == 0)
    return a;

  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return (a*b)/gcd(a,b);
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long a,b;

  cin >> a >> b;

  long long mmc = lcm(a,b);

  long long fa = mmc/a;
  long long fb = mmc/b;

  if(abs(fa-fb) == 1)
    cout << "Equal" << endl;
  else if(fa > fb){
    cout << "Dasha" << endl;
  }else{
    cout << "Masha" << endl;
  }
 

  return 0;
}