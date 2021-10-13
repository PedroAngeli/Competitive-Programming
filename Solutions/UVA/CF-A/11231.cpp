#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n,m,c;

  while(cin >> n >> m >> c && n){

    long long ans = 0;
    
    if(c == 1){
     ans = ((m-8)/2 + 1) * ((n-8)/2 + 1);
     if(m-8-1 >= 0 && n-8-1>=0)
      ans += (((m-8-1)/2 + 1) * ((n-8-1)/2 + 1));
    }else{
      if(n-8-1 >= 0)
        ans += ((m-8)/2 + 1) * ((n-8-1)/2 + 1);
      if(m-8-1 >= 0)
        ans += ((m-8-1)/2 + 1) * ((n-8)/2 + 1);
    }

    cout << ans << endl;    
  }

  return 0; 
}