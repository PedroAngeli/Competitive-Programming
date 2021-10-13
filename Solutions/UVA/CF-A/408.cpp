#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long b){
  if(b==0)
    return a;

  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return a*(b/gcd(a,b));
}

int main(){

  long long step,mod;
  int count = 0;
  while(cin >> step >> mod){
    long long mmc = lcm(step,mod);
    if(mmc == step*mod)
      cout<<setw(10)<<step<<setw(10)<<mod<<"    "<<"Good Choice"<<endl;
    else
      cout<<setw(10)<<step<<setw(10)<<mod<<"    "<<"Bad Choice"<<endl;

    cout << endl;
  }

  return 0;
}