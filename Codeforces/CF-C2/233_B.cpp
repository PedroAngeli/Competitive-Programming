#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int func(long long x){
  int sum = 0;
  while(x){
    int dig = x%10;
    sum+=dig;
    x/=10;
  }

  return sum;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  long long n;
  cin >> n;

  for(long long i=sqrt(n);i*i + 90*i >= n;i--){
    if(i*i + func(i)*i == n){
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}