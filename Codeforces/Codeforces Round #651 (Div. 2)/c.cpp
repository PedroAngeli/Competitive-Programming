#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool powerOfTwo(long long n){
  int lg = log2(n);
  long long pot = pow(2,lg);
  return pot == n;
}

bool can(long long n){
  for(long long i=4;i<n;i*=2){
        if(n % i == 0){
          return true;
        }
    }
  return false;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    long long n;
    cin >> n;
    if(n == 1){
      cout << "FastestFinger" << endl;
    }else if(n % 2 == 1 || n==2){
      cout << "Ashishgup" << endl;
    }else if(powerOfTwo(n)){
      cout << "FastestFinger" << endl;
    }else if(can(n)){
      cout << "Ashishgup" << endl;
    }else{
      int cnt = 0;

      for(long long i=2;i*i<=n;i++){
        if(n % i ==0){
          if(i%2==1)
            cnt++;
          if((n/i) % 2 == 1)
            cnt++;
        }
      }

      if(cnt > 1){
      cout << "Ashishgup" << endl;
      }else{
      cout << "FastestFinger" << endl;
        
      }
    }
    }
  

  return 0;
}