#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n ,m;

  while(cin >> n >> m && n){
    long long sum = 0;
    long long v[n];

    for(int i=0;i<n;i++){
      long long a;
      for(int j=0;j<m;j++){
        cin >> a;
        if(j == m-1){
          v[i] = a;
          sum += a;
        }
      }
    }

    for(int i=0;i<n;i++){
      long long mdc = __gcd(v[i],sum);
      cout << v[i]/mdc << " / " << sum/mdc << endl; 
    }
      
  }

  return 0;
}