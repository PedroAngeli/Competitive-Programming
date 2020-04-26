#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n,k;

  cin >> n >> k;

  if(n % 2 == 0){
    long long numI = n/2;
    
    if(k <= numI){
      cout << 2*(k-1) + 1 << endl;
    }else{
      k = k - numI;
      cout << 2*k << endl;
    }
  }
  else{
    long long numI = n/2 + 1;
    
    if(k <= numI){
      cout << 2*(k-1) + 1 << endl;
    }else{
      k = k - numI;
      cout << 2*k << endl;
    }
  }
  return 0;
}