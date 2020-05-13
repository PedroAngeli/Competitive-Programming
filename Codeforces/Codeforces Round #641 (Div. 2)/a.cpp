#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 100;
long long comb[nax][nax];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    long long n,k;
    cin >> n >> k;

    if(n % 2 == 0){
      n+=2*k;
      cout << n << endl;
    }else{
      while(n % 2 == 1 && k){
        bool div = false;
        for(long long i=2;i*i<=n;i++)
          if(n%i == 0){
            n = n + i;
            div = true;
            break;
          }

        if(!div){
          n = 2*n;
        }
        k--;
      }

      cout << n + 2*k << endl;
    }
  }

  return 0;
}