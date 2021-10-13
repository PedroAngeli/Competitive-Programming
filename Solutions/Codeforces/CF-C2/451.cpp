#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long n,k,d1,d2;

bool solve(){
    if(n % 3 != 0)
      return false;
    for(int i : {-1,1}){
      for(int j : {-1,1}){
        long long n1 = i*d1;
        long long n2 = j*d2;
        
        if((2*n1 + k + n2) % 3 != 0)
          continue;

        long long x = (2*n1 + k + n2)/3;
        if(x >=0 && x <= k){
          long long y = x - n1;
          long long z = x - n1 - n2;
          if(y >= 0 && y<=k && z>=0 && z <= k && x <= n/3 && y <= n/3 && z <= n/3)
            return true;
        }

      }
    }

    return false;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k >> d1 >> d2;
    if(solve())
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}