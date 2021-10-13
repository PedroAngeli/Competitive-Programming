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

  int n,t;
  
  while(cin >> n >> t && n){
    long long coins[n];

    for(int i=0;i<n;i++)
      cin >> coins[i];
    
    for(int i=0;i<t;i++){
      long long h;
      cin >> h;

      long long mn = 0;
      long long mx = 1e9 + 7;

      for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
          for(int k=j+1;k<n;k++)
            for(int l=k+1;l<n;l++){
              long long mmc = lcm(lcm(coins[i],coins[j]),lcm(coins[k],coins[l]));
              long long temp = (h/mmc)*mmc;
              long long temp2 = ((h+mmc-1)/mmc)*mmc;

              if(temp == h){
                mn = mx = h;
                i = j = k = l = n;
              }else{
                mn = max(mn,temp);
                mx = min(mx,temp2);
              }
            }
        
      cout << mn << " " << mx << endl;
    }
  }
  
  
  return 0;
}