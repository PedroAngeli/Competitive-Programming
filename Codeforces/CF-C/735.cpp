#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin >> n;

  long long fib[90] = {0};

  int i = 1;
  
  while(fib[i-1] <= n){
    if(i == 1)
      fib[1] = 2;
    else if(i == 2)
      fib[2] = 3;
    else
      fib[i] = fib[i-1] + fib[i-2];
    i++;
  }

  cout << i-2 << endl;
  


  return 0;
}